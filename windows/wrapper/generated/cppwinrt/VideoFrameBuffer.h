// Generated by zsLibEventingTool

#pragma once


#ifdef CPPWINRT_USE_CUSTOM_ORG_WEBRTC_VIDEOFRAMEBUFFER
#include <wrapper/override/cppwinrt/VideoFrameBuffer.h>
#else // CPPWINRT_USE_CUSTOM_ORG_WEBRTC_VIDEOFRAMEBUFFER

#include "types.h"

#include "VideoFrameBuffer.g.h"
#include <wrapper/generated/org_webRtc_VideoFrameBuffer.h>

namespace winrt {
  namespace Org {
    namespace WebRtc {
      namespace implementation {


        struct VideoFrameBuffer : VideoFrameBufferT<VideoFrameBuffer>
        {
          // internal
          wrapper::org::webRtc::VideoFrameBufferPtr native_;

          struct WrapperCreate {};
          VideoFrameBuffer(const WrapperCreate &) {}

          // ToCppWinrtImpl
          static winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > ToCppWinrtImpl(wrapper::org::webRtc::VideoFrameBufferPtr value);
          static winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > ToCppWinrtImpl(Org::WebRtc::VideoFrameBuffer const & value);
          static winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > ToCppWinrtImpl(winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > const & value);
          static winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > ToCppWinrtImpl(Org::WebRtc::IVideoFrameBuffer const & value);

          // ToCppWinrt
          static Org::WebRtc::VideoFrameBuffer ToCppWinrt(wrapper::org::webRtc::VideoFrameBufferPtr value);
          static Org::WebRtc::VideoFrameBuffer ToCppWinrt(Org::WebRtc::VideoFrameBuffer const & value);
          static Org::WebRtc::VideoFrameBuffer ToCppWinrt(winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > const & value);
          static Org::WebRtc::VideoFrameBuffer ToCppWinrt(Org::WebRtc::IVideoFrameBuffer const & value);

          // ToCppWinrtInterface
          static Org::WebRtc::IVideoFrameBuffer ToCppWinrtInterface(wrapper::org::webRtc::VideoFrameBufferPtr value);
          static Org::WebRtc::IVideoFrameBuffer ToCppWinrtInterface(Org::WebRtc::VideoFrameBuffer const & value);
          static Org::WebRtc::IVideoFrameBuffer ToCppWinrtInterface(winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > const & value);
          static Org::WebRtc::IVideoFrameBuffer ToCppWinrtInterface(Org::WebRtc::IVideoFrameBuffer const & value);

          // FromCppWinrt
          static wrapper::org::webRtc::VideoFrameBufferPtr FromCppWinrt(wrapper::org::webRtc::VideoFrameBufferPtr value);
          static wrapper::org::webRtc::VideoFrameBufferPtr FromCppWinrt(winrt::com_ptr< Org::WebRtc::implementation::VideoFrameBuffer > const & value);
          static wrapper::org::webRtc::VideoFrameBufferPtr FromCppWinrt(Org::WebRtc::VideoFrameBuffer const & value);
          static wrapper::org::webRtc::VideoFrameBufferPtr FromCppWinrt(Org::WebRtc::IVideoFrameBuffer const & value);




        public:
          /// <summary>
          /// Cast from Org::WebRtc::IVideoFrameBuffer to VideoFrameBuffer
          /// </summary>
          static Org::WebRtc::VideoFrameBuffer Cast(Org::WebRtc::IVideoFrameBuffer const & value);
          /// <summary>
          /// Cast from Org::WebRtc::VideoFramePlanarYuvaBuffer to VideoFrameBuffer
          /// </summary>
          static Org::WebRtc::VideoFrameBuffer Cast(Org::WebRtc::VideoFramePlanarYuvaBuffer const & value);
          /// <summary>
          /// Cast from Org::WebRtc::IVideoFramePlanarYuvaBuffer to VideoFrameBuffer
          /// </summary>
          static Org::WebRtc::VideoFrameBuffer Cast(Org::WebRtc::IVideoFramePlanarYuvaBuffer const & value);
          /// <summary>
          /// Cast from Org::WebRtc::VideoFrameNativeBuffer to VideoFrameBuffer
          /// </summary>
          static Org::WebRtc::VideoFrameBuffer Cast(Org::WebRtc::VideoFrameNativeBuffer const & value);
          /// <summary>
          /// Cast from Org::WebRtc::IVideoFrameNativeBuffer to VideoFrameBuffer
          /// </summary>
          static Org::WebRtc::VideoFrameBuffer Cast(Org::WebRtc::IVideoFrameNativeBuffer const & value);
          /// <summary>
          /// Cast from Org::WebRtc::VideoFramePlanarYuvBuffer to VideoFrameBuffer
          /// </summary>
          static Org::WebRtc::VideoFrameBuffer Cast(Org::WebRtc::VideoFramePlanarYuvBuffer const & value);
          /// <summary>
          /// Cast from Org::WebRtc::IVideoFramePlanarYuvBuffer to VideoFrameBuffer
          /// </summary>
          static Org::WebRtc::VideoFrameBuffer Cast(Org::WebRtc::IVideoFramePlanarYuvBuffer const & value);

          // ::org::webRtc::VideoFrameBuffer

          static Org::WebRtc::IVideoFrameBuffer CreateFromYuv(
            int32_t width,
            int32_t height,
            int32_t strideY,
            int32_t strideU,
            int32_t strideV,
            Org::WebRtc::IVideoData const & y,
            Org::WebRtc::IVideoData const & u,
            Org::WebRtc::IVideoData const & v
            );
          static Org::WebRtc::IVideoFrameBuffer CreateFromARGB(
            int32_t width,
            int32_t height,
            int32_t strideRgb,
            Org::WebRtc::IVideoData const & data
            );
          static Org::WebRtc::IVideoFrameBuffer CreateFromBGRA(
            int32_t width,
            int32_t height,
            int32_t strideRgb,
            Org::WebRtc::IVideoData const & data);
          static Org::WebRtc::IVideoFrameBuffer CreateFromBGRA2Ptr(
              int32_t width,
              int32_t height,
              int32_t strideRgb,
              uint64_t data);
          static Org::WebRtc::IVideoFrameBuffer CreateFromABGR(
            int32_t width,
            int32_t height,
            int32_t strideRgb,
            Org::WebRtc::IVideoData const & data
            );
          static Org::WebRtc::IVideoFrameBuffer CreateFromRGBA(
            int32_t width,
            int32_t height,
            int32_t strideRgb,
            Org::WebRtc::IVideoData const & data
            );
          static Org::WebRtc::IVideoFrameBuffer CreateFromRGB24(
            int32_t width,
            int32_t height,
            int32_t strideRgb,
            Org::WebRtc::IVideoData const & data
            );

          bool ToDataPtr(bool toAbgr, uint64_t dataSize, uint64_t dataPtr);
          bool ToI420pPtr(uint64_t y,
                          uint64_t yStride,
                          uint64_t u,
                          uint64_t uStride,
                          uint64_t v,
                          uint64_t vStride);

          
          /// <summary>
          /// Convert to a new (or return an existing) I420 frame buffer (if
          /// possible). <summary> </summary>
          /// </summary>
          Org::WebRtc::IVideoFramePlanarYuvBuffer ToI420();
          /// <summary>
          /// Convert to an ARGB data buffer (if possible). <summary> </summary>
          /// </summary>
          Org::WebRtc::IVideoData ToARGB();
          /// <summary>
          /// Convert to an BGRA data buffer (if possible). <summary> </summary>
          /// </summary>
          Org::WebRtc::IVideoData ToBGRA();
          /// <summary>
          /// Convert to an ABGR data buffer (if possible). <summary> </summary>
          /// </summary>
          Org::WebRtc::IVideoData ToABGR();
          /// <summary>
          /// Convert to an RGBA data buffer (if possible). <summary> </summary>
          /// </summary>
          Org::WebRtc::IVideoData ToRGBA();
          /// <summary>
          /// Convert to an RGB24 data buffer (if possible). <summary>
          /// </summary>
          /// </summary>
          Org::WebRtc::IVideoData ToRGB24();
          // Windows.Foundation.IClosable
          void Close();

          /// <summary>
          /// Gets the video frame type.
          /// </summary>
          Org::WebRtc::VideoFrameBufferType Type();
          /// <summary>
          /// Gets the width of the video frame. <summary> </summary>
          /// </summary>
          int32_t Width();
          /// <summary>
          /// Gets the width of the video frame. <summary> </summary>
          /// </summary>
          int32_t Height();
          /// <summary>
          /// Gets the YUV frame if the buffer type is YUV format. <summary>
          /// </summary>
          /// </summary>
          Org::WebRtc::IVideoFramePlanarYuvBuffer YuvFrame();
          /// <summary>
          /// Gets the I420A frame if the buffer type is YUVA. <summary>
          /// </summary>
          /// </summary>
          Org::WebRtc::IVideoFramePlanarYuvaBuffer YuvaFrame();
          /// <summary>
          /// Gets a native frame if the buffer type is native. <summary>
          /// </summary>
          /// </summary>
          Org::WebRtc::IVideoFrameNativeBuffer NativeFrame();

        };

      } // namespace implementation

      namespace factory_implementation {

        struct VideoFrameBuffer : VideoFrameBufferT<VideoFrameBuffer, implementation::VideoFrameBuffer>
        {
        };

      } // namespace factory_implementation

    } // namespace WebRtc
  } // namespace Org
} // namespace winrt
#endif // CPPWINRT_USE_CUSTOM_ORG_WEBRTC_VIDEOFRAMEBUFFER
