
#include "impl_org_webRtc_VideoFrameBuffer.h"
#include "impl_org_webRtc_VideoFramePlanarYuvBuffer.h"
#include "impl_org_webRtc_VideoFramePlanarYuvaBuffer.h"
#include "impl_org_webRtc_VideoFrameNativeBuffer.h"
#include "impl_org_webRtc_VideoData.h"
#include "impl_org_webRtc_enums.h"

#include "impl_org_webRtc_pre_include.h"
#include "api/video/video_frame_buffer.h"
#include "api/video/i420_buffer.h"
#include "libyuv.h"
#include "third_party/winuwp_h264/native_handle_buffer.h"
#include "impl_org_webRtc_post_include.h"

#include <zsLib/SafeInt.h>

using ::zsLib::String;
using ::zsLib::Optional;
using ::zsLib::Any;
using ::zsLib::AnyPtr;
using ::zsLib::AnyHolder;
using ::zsLib::Promise;
using ::zsLib::PromisePtr;
using ::zsLib::PromiseWithHolder;
using ::zsLib::PromiseWithHolderPtr;
using ::zsLib::eventing::SecureByteBlock;
using ::zsLib::eventing::SecureByteBlockPtr;
using ::std::shared_ptr;
using ::std::weak_ptr;
using ::std::make_shared;
using ::std::list;
using ::std::set;
using ::std::map;

// borrow definitions from class
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::VideoFrameBuffer::WrapperImplType, WrapperImplType);
ZS_DECLARE_TYPEDEF_PTR(WrapperImplType::WrapperType, WrapperType);

ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::IEnum, UseEnum);

ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::VideoFramePlanarYuvBuffer, UseVideoFramePlanarYuvBuffer);
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::VideoFramePlanarYuvaBuffer, UseVideoFramePlanarYuvaBuffer);
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::VideoFrameNativeBuffer, UseVideoFrameNativeBuffer);

//------------------------------------------------------------------------------
wrapper::impl::org::webRtc::VideoFrameBuffer::VideoFrameBuffer() noexcept
{
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr wrapper::org::webRtc::VideoFrameBuffer::wrapper_create() noexcept
{
  auto pThis = make_shared<wrapper::impl::org::webRtc::VideoFrameBuffer>();
  pThis->thisWeak_ = pThis;
  return pThis;
}

//------------------------------------------------------------------------------
wrapper::impl::org::webRtc::VideoFrameBuffer::~VideoFrameBuffer() noexcept
{
  thisWeak_.reset();
  wrapper_dispose();
}

//------------------------------------------------------------------------------
void wrapper::impl::org::webRtc::VideoFrameBuffer::wrapper_dispose() noexcept
{
  native_ = NativeTypeScopedRefPtr();
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr wrapper::org::webRtc::VideoFrameBuffer::createFromYuv(
  int width,
  int height,
  int strideY,
  int strideU,
  int strideV,
  wrapper::org::webRtc::VideoDataPtr y,
  wrapper::org::webRtc::VideoDataPtr u,
  wrapper::org::webRtc::VideoDataPtr v
) noexcept
{
  if ((!y) ||
      (!u) ||
      (!v))
    return {};

  if ((0 == width) ||
      (0 == height))
    return {};

  auto py = y->get_data8bit();
  auto pu = u->get_data8bit();
  auto pv = v->get_data8bit();

  if ((!py) ||
      (!pu) ||
      (!pv))
    return {};

  auto buffer = webrtc::I420Buffer::Copy(width, height, py, strideY, pu, strideU, pv, strideV);
  return UseVideoFramePlanarYuvBuffer::toWrapper(buffer.get());
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr wrapper::org::webRtc::VideoFrameBuffer::createFromARGB(
  int width,
  int height,
  int strideRgb,
  wrapper::org::webRtc::VideoDataPtr data
) noexcept
{
  if (!data)
    return {};

  auto source = data->get_data8bit();
  if (!source)
    return {};

  auto dest = std::unique_ptr<uint8_t>(new uint8_t[(width * height) + ((width * height) / 2) + ((width * height) / 2)]);

  auto py = dest.get();
  auto pu = &(dest.get()[width * height]);
  auto pv = &(pu[(width * height)/2]);

  int result = libyuv::ARGBToI420(
    source,
    strideRgb,
    py,
    width,
    pu,
    width/2,
    pv,
    width/2,
    width,
    height);
  assert(result == 0);

  if (0 != result)
    return {};

  auto buffer = webrtc::I420Buffer::Copy(width, height, py, width, pu, width/2, pv, width/2);
  return UseVideoFramePlanarYuvBuffer::toWrapper(buffer.get());
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr wrapper::org::webRtc::VideoFrameBuffer::createFromBGRA(
  int width,
  int height,
  int strideRgb,
  wrapper::org::webRtc::VideoDataPtr data
) noexcept
{
  if (!data)
    return {};

  auto source = data->get_data8bit();
  if (!source)
    return {};

  auto dest = std::unique_ptr<uint8_t>(new uint8_t[(width * height) + ((width * height) / 2) + ((width * height) / 2)]);

  auto py = dest.get();
  auto pu = &(dest.get()[width * height]);
  auto pv = &(pu[(width * height) / 2]);

  int result = libyuv::BGRAToI420(
    source,
    strideRgb,
    py,
    width,
    pu,
    width / 2,
    pv,
    width / 2,
    width,
    height);
  assert(result == 0);

  if (0 != result)
    return {};

  auto buffer = webrtc::I420Buffer::Copy(width, height, py, width, pu, width / 2, pv, width / 2);
  return UseVideoFramePlanarYuvBuffer::toWrapper(buffer.get());
}
//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr
wrapper::org::webRtc::VideoFrameBuffer::createFromBGRAPtr2(
    int width,
    int height,
    int strideRgb,
    uint64_t dataPtr) noexcept {

  auto source = reinterpret_cast<uint8_t*>(SafeInt<uintptr_t>(dataPtr).Ref());
  if (source == nullptr)
    return nullptr;

  auto stridey = width;
  auto strideuv = width / 2;
  auto buffer =
      webrtc::I420Buffer::Create(width, abs(height), stridey, strideuv, strideuv);
  
  int result = libyuv::BGRAToI420(source, strideRgb,
      buffer->MutableDataY(), stridey,
      buffer->MutableDataU(), strideuv,
      buffer->MutableDataV(), strideuv,
      width, height);
  assert(result == 0);
  return UseVideoFramePlanarYuvBuffer::toWrapper(buffer.get());
}
//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr wrapper::org::webRtc::VideoFrameBuffer::createFromABGR(
  int width,
  int height,
  int strideRgb,
  wrapper::org::webRtc::VideoDataPtr data
) noexcept
{
  if (!data)
    return {};

  auto source = data->get_data8bit();
  if (!source)
    return {};

  auto dest = std::unique_ptr<uint8_t>(new uint8_t[(width * height) + ((width * height) / 2) + ((width * height) / 2)]);

  auto py = dest.get();
  auto pu = &(dest.get()[width * height]);
  auto pv = &(pu[(width * height) / 2]);

  int result = libyuv::ABGRToI420(
    source,
    strideRgb,
    py,
    width,
    pu,
    width / 2,
    pv,
    width / 2,
    width,
    height);
  assert(result == 0);

  if (0 != result)
    return {};

  auto buffer = webrtc::I420Buffer::Copy(width, height, py, width, pu, width / 2, pv, width / 2);
  return UseVideoFramePlanarYuvBuffer::toWrapper(buffer.get());
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr wrapper::org::webRtc::VideoFrameBuffer::createFromRGBA(
  int width,
  int height,
  int strideRgb,
  wrapper::org::webRtc::VideoDataPtr data
) noexcept
{
  if (!data)
    return {};

  auto source = data->get_data8bit();
  if (!source)
    return {};

  auto dest = std::unique_ptr<uint8_t>(new uint8_t[(width * height) + ((width * height) / 2) + ((width * height) / 2)]);

  auto py = dest.get();
  auto pu = &(dest.get()[width * height]);
  auto pv = &(pu[(width * height) / 2]);

  int result = libyuv::RGBAToI420(
    source,
    strideRgb,
    py,
    width,
    pu,
    width / 2,
    pv,
    width / 2,
    width,
    height);
  assert(result == 0);

  if (0 != result)
    return {};

  auto buffer = webrtc::I420Buffer::Copy(width, height, py, width, pu, width / 2, pv, width / 2);
  return UseVideoFramePlanarYuvBuffer::toWrapper(buffer.get());
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr wrapper::org::webRtc::VideoFrameBuffer::createFromRGB24(
  int width,
  int height,
  int strideRgb,
  wrapper::org::webRtc::VideoDataPtr data
) noexcept
{
  if (!data)
    return {};

  auto source = data->get_data8bit();
  if (!source)
    return {};

  auto dest = std::unique_ptr<uint8_t>(new uint8_t[(width * height) + ((width * height) / 2) + ((width * height) / 2)]);

  auto py = dest.get();
  auto pu = &(dest.get()[width * height]);
  auto pv = &(pu[(width * height) / 2]);

  int result = libyuv::RGB24ToI420(
    source,
    strideRgb,
    py,
    width,
    pu,
    width / 2,
    pv,
    width / 2,
    width,
    height);
  assert(result == 0);

  if (0 != result)
    return {};

  auto buffer = webrtc::I420Buffer::Copy(width, height, py, width, pu, width / 2, pv, width / 2);
  return UseVideoFramePlanarYuvBuffer::toWrapper(buffer.get());
}


//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFramePlanarYuvBufferPtr wrapper::impl::org::webRtc::VideoFrameBuffer::toI420() noexcept
{
  if (!native_)
    return {};

  auto i420Frame = native_->ToI420();
  return UseVideoFramePlanarYuvBuffer::toWrapper(i420Frame);
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoDataPtr WrapperImplType::toARGB() noexcept
{
  return toARGB(native_.get());
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoDataPtr WrapperImplType::toBGRA() noexcept
{
  return toBGRA(native_.get());
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoDataPtr WrapperImplType::toABGR() noexcept
{
  return toABGR(native_.get());
}



//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoDataPtr WrapperImplType::toRGBA() noexcept
{
  return toRGBA(native_.get());
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoDataPtr WrapperImplType::toRGB24() noexcept
{
  return toRGB24(native_.get());
}

//------------------------------------------------------------------------------
bool WrapperImplType::toDataPtr(bool toAbgr,
    uint64_t dataSize,
    uint64_t dataPtr) noexcept {
  return toDataPtr(native_.get(), toAbgr, dataSize, dataPtr);
}

//------------------------------------------------------------------------------
bool WrapperImplType::toI420pPtr(uint64_t y,
                                 uint64_t yStride,
                                 uint64_t u,
                                 uint64_t uStride,
                                 uint64_t v,
                                 uint64_t vStride) noexcept {
  return toI420pPtr(native_.get(), y, yStride, u, uStride, v, vStride);
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferType wrapper::impl::org::webRtc::VideoFrameBuffer::get_type() noexcept
{
  ZS_ASSERT(native_);
  if (!native_)
    return wrapper::org::webRtc::VideoFrameBufferType::VideoFrameBufferType_native;
  return UseEnum::toWrapper(native_->type());
}

//------------------------------------------------------------------------------
int wrapper::impl::org::webRtc::VideoFrameBuffer::get_width() noexcept
{
  ZS_ASSERT(native_);
  if (!native_)
    return {};

  return native_->width();
}

//------------------------------------------------------------------------------
int wrapper::impl::org::webRtc::VideoFrameBuffer::get_height() noexcept
{
  ZS_ASSERT(native_);
  if (!native_)
    return {};

  return native_->height();
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFramePlanarYuvBufferPtr wrapper::impl::org::webRtc::VideoFrameBuffer::get_yuvFrame() noexcept
{
  ZS_ASSERT(native_);
  if (!native_)
    return {};

  switch (native_->type())
  {
    case ::webrtc::VideoFrameBuffer::Type::kNative: return {};
    case ::webrtc::VideoFrameBuffer::Type::kI420:   return UseVideoFramePlanarYuvBuffer::toWrapper(native_->GetI420());
    case ::webrtc::VideoFrameBuffer::Type::kI420A:  return UseVideoFramePlanarYuvBuffer::toWrapper(native_->GetI420A());
    case ::webrtc::VideoFrameBuffer::Type::kI444:   return UseVideoFramePlanarYuvBuffer::toWrapper(native_->GetI444());
    case ::webrtc::VideoFrameBuffer::Type::kI010:   return UseVideoFramePlanarYuvBuffer::toWrapper(native_->GetI010());
  }

  return {};
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFramePlanarYuvaBufferPtr wrapper::impl::org::webRtc::VideoFrameBuffer::get_yuvaFrame() noexcept
{
  ZS_ASSERT(native_);
  if (!native_)
    return {};

  switch (native_->type())
  {
    case ::webrtc::VideoFrameBuffer::Type::kNative: return {};
    case ::webrtc::VideoFrameBuffer::Type::kI420:   return {};
    case ::webrtc::VideoFrameBuffer::Type::kI420A:  return UseVideoFramePlanarYuvaBuffer::toWrapper(native_->GetI420A());
    case ::webrtc::VideoFrameBuffer::Type::kI444:   return {};
    case ::webrtc::VideoFrameBuffer::Type::kI010:   return {};
  }

  return {};
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameNativeBufferPtr wrapper::impl::org::webRtc::VideoFrameBuffer::get_nativeFrame() noexcept
{
  ZS_ASSERT(native_);
  if (!native_)
    return {};

  switch (native_->type())
  {
    case ::webrtc::VideoFrameBuffer::Type::kNative: return UseVideoFrameNativeBuffer::toWrapper(reinterpret_cast<::webrtc::NativeHandleBuffer *>(native_.get()));
    case ::webrtc::VideoFrameBuffer::Type::kI420:   return {};
    case ::webrtc::VideoFrameBuffer::Type::kI420A:  return {};
    case ::webrtc::VideoFrameBuffer::Type::kI444:   return {};
    case ::webrtc::VideoFrameBuffer::Type::kI010:   return {};
  }

  return {};
}

//------------------------------------------------------------------------------
WrapperImplType::NativeTypeScopedRefPtr WrapperImplType::toNative(WrapperType *type) noexcept
{
  if (!type)
    return {};
  {
    auto ptr = dynamic_cast<WrapperImplType *>(type);
    if (ptr)
      return ptr->native_;
  }
  {
    auto ptr = dynamic_cast<UseVideoFramePlanarYuvBuffer *>(type);
    if (ptr)
      return ptr->native_;
  }
  {
    auto ptr = dynamic_cast<UseVideoFramePlanarYuvaBuffer *>(type);
    if (ptr)
      return ptr->native_;
  }
  {
    auto ptr = dynamic_cast<UseVideoFrameNativeBuffer *>(type);
    if (ptr)
      return ptr->native_;
  }
  return {};
}

//------------------------------------------------------------------------------
WrapperImplType::NativeTypeScopedRefPtr WrapperImplType::toNative(WrapperTypePtr type) noexcept
{
  if (!type)
    return {};
  return toNative(type.get());
}

//------------------------------------------------------------------------------
WrapperImplTypePtr WrapperImplType::toWrapper(NativeType *native) noexcept
{
  auto result = make_shared<WrapperImplType>();
  result->thisWeak_ = result;
  result->native_ = NativeTypeScopedRefPtr(native);
  return result;
}

//------------------------------------------------------------------------------
WrapperImplTypePtr WrapperImplType::toWrapper(NativeTypeScopedRefPtr native) noexcept
{
  if (!native)
    return {};
  return toWrapper(native.get());
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoDataPtr WrapperImplType::toARGB(NativeType *native) noexcept
{
  if (!native)
    return {};
  auto i420Frame = native->ToI420();
  if (!i420Frame)
    return {};

  size_t bytesPerPixel = (sizeof(uint8_t) * 4);
  size_t stride = bytesPerPixel * i420Frame->width();
  size_t size = SafeInt<size_t>(i420Frame->width() * i420Frame->height() * bytesPerPixel);
  std::unique_ptr<uint8_t> buffer(new uint8_t[size]);

  libyuv::I420ToARGB(
    i420Frame->DataY(), i420Frame->StrideY(),
    i420Frame->DataU(), i420Frame->StrideU(),
    i420Frame->DataV(), i420Frame->StrideV(),
    buffer.get(),
    SafeInt<int>(stride),
    i420Frame->width(),
    i420Frame->height()
  );

  return UseVideoData::toWrapper(std::move(buffer), size);
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoDataPtr WrapperImplType::toBGRA(NativeType *native) noexcept
{
  if (!native)
    return {};
  auto i420Frame = native->ToI420();
  if (!i420Frame)
    return {};

  size_t bytesPerPixel = (sizeof(uint8_t) * 4);
  size_t stride = bytesPerPixel * i420Frame->width();
  size_t size = SafeInt<size_t>(i420Frame->width() * i420Frame->height() * bytesPerPixel);
  std::unique_ptr<uint8_t> buffer(new uint8_t[size]);

  libyuv::I420ToBGRA(
    i420Frame->DataY(), i420Frame->StrideY(),
    i420Frame->DataU(), i420Frame->StrideU(),
    i420Frame->DataV(), i420Frame->StrideV(),
    buffer.get(),
    SafeInt<int>(stride),
    i420Frame->width(),
    i420Frame->height()
  );

  return UseVideoData::toWrapper(std::move(buffer), size);
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoDataPtr WrapperImplType::toABGR(NativeType *native) noexcept
{
  if (!native)
    return {};
  auto i420Frame = native->ToI420();
  if (!i420Frame)
    return {};

  size_t bytesPerPixel = (sizeof(uint8_t) * 4);
  size_t stride = bytesPerPixel * i420Frame->width();
  size_t size = SafeInt<size_t>(i420Frame->width() * i420Frame->height() * bytesPerPixel);
  std::unique_ptr<uint8_t> buffer(new uint8_t[size]);

  libyuv::I420ToABGR(
    i420Frame->DataY(), i420Frame->StrideY(),
    i420Frame->DataU(), i420Frame->StrideU(),
    i420Frame->DataV(), i420Frame->StrideV(),
    buffer.get(),
    SafeInt<int>(stride),
    i420Frame->width(),
    i420Frame->height()
  );

  return UseVideoData::toWrapper(std::move(buffer), size);
}


//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoDataPtr WrapperImplType::toRGBA(NativeType *native) noexcept
{
  if (!native)
    return {};
  auto i420Frame = native->ToI420();
  if (!i420Frame)
    return {};

  size_t bytesPerPixel = (sizeof(uint8_t) * 4);
  size_t stride = bytesPerPixel * i420Frame->width();
  size_t size = SafeInt<size_t>(i420Frame->width() * i420Frame->height() * bytesPerPixel);
  std::unique_ptr<uint8_t> buffer(new uint8_t[size]);

  libyuv::I420ToRGBA(
    i420Frame->DataY(), i420Frame->StrideY(),
    i420Frame->DataU(), i420Frame->StrideU(),
    i420Frame->DataV(), i420Frame->StrideV(),
    buffer.get(),
    SafeInt<int>(stride),
    i420Frame->width(),
    i420Frame->height()
  );

  return UseVideoData::toWrapper(std::move(buffer), size);
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoDataPtr WrapperImplType::toRGB24(NativeType *native) noexcept
{
  if (!native)
    return {};
  auto i420Frame = native->ToI420();
  if (!i420Frame)
    return {};

  size_t bytesPerPixel = (sizeof(uint8_t) * 3);
  size_t stride = bytesPerPixel * i420Frame->width();
  size_t size = SafeInt<size_t>(i420Frame->width() * i420Frame->height() * bytesPerPixel);
  std::unique_ptr<uint8_t> buffer(new uint8_t[size]);

  libyuv::I420ToRGB24(
    i420Frame->DataY(), i420Frame->StrideY(),
    i420Frame->DataU(), i420Frame->StrideU(),
    i420Frame->DataV(), i420Frame->StrideV(),
    buffer.get(),
    SafeInt<int>(stride),
    i420Frame->width(),
    i420Frame->height()
  );

  return UseVideoData::toWrapper(std::move(buffer), size);
}


//------------------------------------------------------------------------------
bool WrapperImplType::toDataPtr(NativeType* native, bool toAbgr,
    uint64_t dataSize,
    uint64_t dataPtr) noexcept {
  
  if (!native)
    return false;

  auto destination = reinterpret_cast<uint8_t*>(SafeInt<uintptr_t>(dataPtr).Ref());
  if (!destination)
    return false;
  
  auto i420 = native->ToI420();

  auto width = i420->width();
  auto height = i420->height();
  size_t outputStride = 4 * width;

  auto y = i420->DataY();
  auto ystride = i420->StrideY();
  auto u = i420->DataU();
  auto ustride = i420->StrideU();
  auto v = i420->DataV();
  auto vstride = i420->StrideV();

  size_t bytesPerPixel = (sizeof(uint8_t) * 4);
  size_t size = SafeInt<size_t>(width * height * bytesPerPixel);


  libyuv::I420ToABGR(y, ystride,
      u, ustride, 
      v, vstride,
      destination, outputStride,
      width, height);
  

  

  for (int i = 0; i < 10; i++) {
    destination[i * 4 + 0] = 255;
    destination[i * 4 + 1] = 1;
    destination[i * 4 + 2] = 255;
  }
  return true;
}


bool WrapperImplType::toI420pPtr(NativeType* native,
    uint64_t y,
    uint64_t yStride,
    uint64_t u,
    uint64_t uStride,
    uint64_t v,
    uint64_t vStride) noexcept {

    auto i420 = native->ToI420();

    libyuv::I420Copy(i420->DataY(), i420->StrideY(), 
        i420->DataU(),i420->StrideU(),
        i420->DataV(), i420->StrideV(), 
        (uint8_t*)y, yStride, (uint8_t*)u, uStride, (uint8_t*)v,
                     vStride,
        i420->width(), i420->height());
  return true;
}