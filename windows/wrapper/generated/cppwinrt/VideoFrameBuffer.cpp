// Generated by zsLibEventingTool

#include "pch.h"

#ifdef CPPWINRT_USE_CUSTOM_ORG_WEBRTC_VIDEOFRAMEBUFFER
#include <wrapper/override/cppwinrt/VideoFrameBuffer.cpp>
#else // CPPWINRT_USE_CUSTOM_ORG_WEBRTC_VIDEOFRAMEBUFFER
#include "cppwinrt_Helpers.h"
#include "VideoFrameBuffer.h"
#include "VideoFormat.h"
#include "RTCRtcpFeedback.h"
#include "RTCRtpCodecCapability.h"
#include "RTCRtpContributingSource.h"
#include "RTCRtpDecodingParameters.h"
#include "RTCRtpSynchronizationSource.h"
#include "RTCIceServer.h"
#include "CustomAudioRecordingDeviceInfo.h"
#include "RTCRtpCodecParameters.h"
#include "RTCDtlsFingerprint.h"
#include "Constraint.h"
#include "RTCRtpHeaderExtensionCapability.h"
#include "CustomAudioPlayoutDeviceInfo.h"
#include "RTCRtpHeaderExtensionParameters.h"
#include "VideoDeviceInfo.h"
#include "RTCStatsReport.h"
#include "RTCCertificate.h"
#include "RTCSessionDescription.h"
#include "RTCRtpReceiver.h"
#include "RTCRtpEncodingParameters.h"
#include "RTCIceCandidate.h"
#include "RTCRtpTransceiver.h"
#include "RTCRtpSender.h"
#include "VideoFramePlanarYuvaBuffer.h"
#include "VideoFrameNativeBuffer.h"
#include "VideoFramePlanarYuvBuffer.h"
#include "VideoData.h"

using namespace winrt;

//------------------------------------------------------------------------------
winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrtImpl(wrapper::org::webRtc::VideoFrameBufferPtr value)
{
  if (!value) return nullptr;
  auto result = winrt::make_self<Org::WebRtc::implementation::VideoFrameBuffer>(WrapperCreate{});
  result->native_ = value;
  return result;
}

//------------------------------------------------------------------------------
winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrtImpl(Org::WebRtc::VideoFrameBuffer const & value)
{
  winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > impl {nullptr};
  impl.copy_from(winrt::from_abi<Org::WebRtc::implementation::VideoFrameBuffer>(value));
  return impl;
}

//------------------------------------------------------------------------------
winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrtImpl(winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > const & value)
{
  return value;
}

//------------------------------------------------------------------------------
winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrtImpl(Org::WebRtc::IVideoFrameBuffer const & value)
{
  winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > impl {nullptr};
  impl.copy_from(winrt::from_abi<Org::WebRtc::implementation::VideoFrameBuffer>(value));
  return impl;
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrt(wrapper::org::webRtc::VideoFrameBufferPtr value)
{
  auto result = ToCppWinrtImpl(value);
  if (!result) return Org::WebRtc::VideoFrameBuffer {nullptr};
  return result.as< Org::WebRtc::VideoFrameBuffer >();
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrt(Org::WebRtc::VideoFrameBuffer const & value)
{
  return value;
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrt(winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > const & value)
{
  if (!value) return Org::WebRtc::VideoFrameBuffer {nullptr};
  return value.as< Org::WebRtc::VideoFrameBuffer >();
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrt(Org::WebRtc::IVideoFrameBuffer const & value)
{
  if (!value) return Org::WebRtc::VideoFrameBuffer {nullptr};
  return value.as< Org::WebRtc::VideoFrameBuffer >();
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrtInterface(wrapper::org::webRtc::VideoFrameBufferPtr value)
{
  auto result = ToCppWinrtImpl(value);
  if (!result) return Org::WebRtc::IVideoFrameBuffer {nullptr};
  return result.as< Org::WebRtc::IVideoFrameBuffer >();
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrtInterface(Org::WebRtc::VideoFrameBuffer const & value)
{
  if (!value) return Org::WebRtc::IVideoFrameBuffer {nullptr};
  return value.as< Org::WebRtc::IVideoFrameBuffer >();
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrtInterface(winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > const & value)
{
  if (!value) return Org::WebRtc::IVideoFrameBuffer {nullptr};
  return value.as< Org::WebRtc::IVideoFrameBuffer >();
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::ToCppWinrtInterface(Org::WebRtc::IVideoFrameBuffer const & value)
{
  return value;
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr Org::WebRtc::implementation::VideoFrameBuffer::FromCppWinrt(winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > const & value)
{
  if (!value) return wrapper::org::webRtc::VideoFrameBufferPtr();
  return value->native_;
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr Org::WebRtc::implementation::VideoFrameBuffer::FromCppWinrt(Org::WebRtc::VideoFrameBuffer const & value)
{
  return FromCppWinrt(ToCppWinrtImpl(value));
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr Org::WebRtc::implementation::VideoFrameBuffer::FromCppWinrt(wrapper::org::webRtc::VideoFrameBufferPtr value)
{
  return value;
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::VideoFrameBufferPtr Org::WebRtc::implementation::VideoFrameBuffer::FromCppWinrt(Org::WebRtc::IVideoFrameBuffer const & value)
{
  return FromCppWinrt(ToCppWinrtImpl(value));
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::Cast(Org::WebRtc::IVideoFrameBuffer const & value)
{
  if (!value) return nullptr;
  auto nativeObject = ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoFrameBuffer(value);  
  if (!nativeObject) return nullptr;
  auto result = std::dynamic_pointer_cast< wrapper::org::webRtc::VideoFrameBuffer >(nativeObject);
  if (!result) return nullptr;
  return ToCppWinrt(result);
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::Cast(Org::WebRtc::VideoFramePlanarYuvaBuffer const & value)
{
  if (!value) return nullptr;
  auto nativeObject = ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoFramePlanarYuvaBuffer(value);  
  if (!nativeObject) return nullptr;
  auto result = std::dynamic_pointer_cast< wrapper::org::webRtc::VideoFrameBuffer >(nativeObject);
  if (!result) return nullptr;
  return ToCppWinrt(result);
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::Cast(Org::WebRtc::IVideoFramePlanarYuvaBuffer const & value)
{
  if (!value) return nullptr;
  auto nativeObject = ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoFramePlanarYuvaBuffer(value);  
  if (!nativeObject) return nullptr;
  auto result = std::dynamic_pointer_cast< wrapper::org::webRtc::VideoFrameBuffer >(nativeObject);
  if (!result) return nullptr;
  return ToCppWinrt(result);
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::Cast(Org::WebRtc::VideoFrameNativeBuffer const & value)
{
  if (!value) return nullptr;
  auto nativeObject = ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoFrameNativeBuffer(value);  
  if (!nativeObject) return nullptr;
  auto result = std::dynamic_pointer_cast< wrapper::org::webRtc::VideoFrameBuffer >(nativeObject);
  if (!result) return nullptr;
  return ToCppWinrt(result);
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::Cast(Org::WebRtc::IVideoFrameNativeBuffer const & value)
{
  if (!value) return nullptr;
  auto nativeObject = ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoFrameNativeBuffer(value);  
  if (!nativeObject) return nullptr;
  auto result = std::dynamic_pointer_cast< wrapper::org::webRtc::VideoFrameBuffer >(nativeObject);
  if (!result) return nullptr;
  return ToCppWinrt(result);
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::Cast(Org::WebRtc::VideoFramePlanarYuvBuffer const & value)
{
  if (!value) return nullptr;
  auto nativeObject = ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoFramePlanarYuvBuffer(value);  
  if (!nativeObject) return nullptr;
  auto result = std::dynamic_pointer_cast< wrapper::org::webRtc::VideoFrameBuffer >(nativeObject);
  if (!result) return nullptr;
  return ToCppWinrt(result);
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::Cast(Org::WebRtc::IVideoFramePlanarYuvBuffer const & value)
{
  if (!value) return nullptr;
  auto nativeObject = ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoFramePlanarYuvBuffer(value);  
  if (!nativeObject) return nullptr;
  auto result = std::dynamic_pointer_cast< wrapper::org::webRtc::VideoFrameBuffer >(nativeObject);
  if (!result) return nullptr;
  return ToCppWinrt(result);
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::CreateFromYuv(
  int32_t width,
  int32_t height,
  int32_t strideY,
  int32_t strideU,
  int32_t strideV,
  Org::WebRtc::IVideoData const & y,
  Org::WebRtc::IVideoData const & u,
  Org::WebRtc::IVideoData const & v
  )
{
  Org::WebRtc::IVideoFrameBuffer result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoFrameBuffer(wrapper::org::webRtc::VideoFrameBuffer::createFromYuv(::Internal::Helper::FromCppWinrt_Int(width), ::Internal::Helper::FromCppWinrt_Int(height), ::Internal::Helper::FromCppWinrt_Int(strideY), ::Internal::Helper::FromCppWinrt_Int(strideU), ::Internal::Helper::FromCppWinrt_Int(strideV), ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoData(y), ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoData(u), ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoData(v)));
  return result;
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::CreateFromARGB(
  int32_t width,
  int32_t height,
  int32_t strideRgb,
  Org::WebRtc::IVideoData const & data
  )
{
  Org::WebRtc::IVideoFrameBuffer result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoFrameBuffer(wrapper::org::webRtc::VideoFrameBuffer::createFromARGB(::Internal::Helper::FromCppWinrt_Int(width), ::Internal::Helper::FromCppWinrt_Int(height), ::Internal::Helper::FromCppWinrt_Int(strideRgb), ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoData(data)));
  return result;
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::CreateFromBGRA(
  int32_t width,
  int32_t height,
  int32_t strideRgb,
  Org::WebRtc::IVideoData const & data
  )
{
  Org::WebRtc::IVideoFrameBuffer result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoFrameBuffer(wrapper::org::webRtc::VideoFrameBuffer::createFromBGRA(::Internal::Helper::FromCppWinrt_Int(width), ::Internal::Helper::FromCppWinrt_Int(height), ::Internal::Helper::FromCppWinrt_Int(strideRgb), ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoData(data)));
  return result;
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameBuffer
Org::WebRtc::implementation::VideoFrameBuffer::CreateFromBGRA2Ptr(
    int32_t width,
    int32_t height,
    int32_t strideRgb,
    uint64_t dataPtr) {
  Org::WebRtc::IVideoFrameBuffer result{nullptr};
  
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoFrameBuffer(
      wrapper::org::webRtc::VideoFrameBuffer::createFromBGRAPtr2(
          ::Internal::Helper::FromCppWinrt_Int(width),
          ::Internal::Helper::FromCppWinrt_Int(height),
          ::Internal::Helper::FromCppWinrt_Int(strideRgb),
          ::Internal::Helper::FromCppWinrt_Uint64_t(dataPtr)));
  
  return result;
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::CreateFromABGR(
  int32_t width,
  int32_t height,
  int32_t strideRgb,
  Org::WebRtc::IVideoData const & data
  )
{
  Org::WebRtc::IVideoFrameBuffer result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoFrameBuffer(wrapper::org::webRtc::VideoFrameBuffer::createFromABGR(::Internal::Helper::FromCppWinrt_Int(width), ::Internal::Helper::FromCppWinrt_Int(height), ::Internal::Helper::FromCppWinrt_Int(strideRgb), ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoData(data)));
  return result;
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::CreateFromRGBA(
  int32_t width,
  int32_t height,
  int32_t strideRgb,
  Org::WebRtc::IVideoData const & data
  )
{
  Org::WebRtc::IVideoFrameBuffer result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoFrameBuffer(wrapper::org::webRtc::VideoFrameBuffer::createFromRGBA(::Internal::Helper::FromCppWinrt_Int(width), ::Internal::Helper::FromCppWinrt_Int(height), ::Internal::Helper::FromCppWinrt_Int(strideRgb), ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoData(data)));
  return result;
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameBuffer Org::WebRtc::implementation::VideoFrameBuffer::CreateFromRGB24(
  int32_t width,
  int32_t height,
  int32_t strideRgb,
  Org::WebRtc::IVideoData const & data
  )
{
  Org::WebRtc::IVideoFrameBuffer result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoFrameBuffer(wrapper::org::webRtc::VideoFrameBuffer::createFromRGB24(::Internal::Helper::FromCppWinrt_Int(width), ::Internal::Helper::FromCppWinrt_Int(height), ::Internal::Helper::FromCppWinrt_Int(strideRgb), ::Internal::Helper::FromCppWinrt_Org_WebRtc_VideoData(data)));
  return result;
}


//------------------------------------------------------------------------------
Org::WebRtc::IVideoFramePlanarYuvBuffer Org::WebRtc::implementation::VideoFrameBuffer::ToI420()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  Org::WebRtc::IVideoFramePlanarYuvBuffer result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoFramePlanarYuvBuffer(native_->toI420());
  return result;
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoData Org::WebRtc::implementation::VideoFrameBuffer::ToARGB()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  Org::WebRtc::IVideoData result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoData(native_->toARGB());
  return result;
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoData Org::WebRtc::implementation::VideoFrameBuffer::ToBGRA()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  Org::WebRtc::IVideoData result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoData(native_->toBGRA());
  return result;
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoData Org::WebRtc::implementation::VideoFrameBuffer::ToABGR()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  Org::WebRtc::IVideoData result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoData(native_->toABGR());
  return result;
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoData Org::WebRtc::implementation::VideoFrameBuffer::ToRGBA()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  Org::WebRtc::IVideoData result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoData(native_->toRGBA());
  return result;
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoData Org::WebRtc::implementation::VideoFrameBuffer::ToRGB24()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  Org::WebRtc::IVideoData result {nullptr};
  result = ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoData(native_->toRGB24());
  return result;
}


//------------------------------------------------------------------------------
bool Org::WebRtc::implementation::VideoFrameBuffer::ToDataPtr(
    bool toAbgr, 
    uint64_t dataSize,
    uint64_t dataPtr) {
  if (!native_) {
    throw hresult_error(E_POINTER);
  }
  return native_->toDataPtr(::Internal::Helper::FromCppWinrt_Bool(toAbgr),
      ::Internal::Helper::FromCppWinrt_Uint64_t(dataSize),
      ::Internal::Helper::FromCppWinrt_Uint64_t(dataPtr));
}

//------------------------------------------------------------------------------
bool Org::WebRtc::implementation::VideoFrameBuffer::ToI420pPtr(
    uint64_t y,
    uint64_t yStride,
    uint64_t u,
    uint64_t uStride,
    uint64_t v,
    uint64_t vStride)
{
  if (!native_) {
    throw hresult_error(E_POINTER);
  }
  return native_->toI420pPtr(
      ::Internal::Helper::FromCppWinrt_Uint64_t(y),
      ::Internal::Helper::FromCppWinrt_Uint64_t(yStride),
      ::Internal::Helper::FromCppWinrt_Uint64_t(u),
      ::Internal::Helper::FromCppWinrt_Uint64_t(uStride),
      ::Internal::Helper::FromCppWinrt_Uint64_t(v),
      ::Internal::Helper::FromCppWinrt_Uint64_t(vStride));
}

//------------------------------------------------------------------------------
void Org::WebRtc::implementation::VideoFrameBuffer::Close()
{
  if (native_) native_->wrapper_dispose();
  native_.reset();
}

//------------------------------------------------------------------------------
Org::WebRtc::VideoFrameBufferType Org::WebRtc::implementation::VideoFrameBuffer::Type()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  return ::Internal::Helper::ToCppWinrt(native_->get_type());
}

//------------------------------------------------------------------------------
int32_t Org::WebRtc::implementation::VideoFrameBuffer::Width()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  return ::Internal::Helper::ToCppWinrt_Int(native_->get_width());
}

//------------------------------------------------------------------------------
int32_t Org::WebRtc::implementation::VideoFrameBuffer::Height()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  return ::Internal::Helper::ToCppWinrt_Int(native_->get_height());
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFramePlanarYuvBuffer Org::WebRtc::implementation::VideoFrameBuffer::YuvFrame()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  return ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoFramePlanarYuvBuffer(native_->get_yuvFrame());
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFramePlanarYuvaBuffer Org::WebRtc::implementation::VideoFrameBuffer::YuvaFrame()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  return ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoFramePlanarYuvaBuffer(native_->get_yuvaFrame());
}

//------------------------------------------------------------------------------
Org::WebRtc::IVideoFrameNativeBuffer Org::WebRtc::implementation::VideoFrameBuffer::NativeFrame()
{
  if (!native_) {throw hresult_error(E_POINTER);}
  return ::Internal::Helper::ToCppWinrt_Org_WebRtc_VideoFrameNativeBuffer(native_->get_nativeFrame());
}


#endif // CPPWINRT_USE_CUSTOM_ORG_WEBRTC_VIDEOFRAMEBUFFER
