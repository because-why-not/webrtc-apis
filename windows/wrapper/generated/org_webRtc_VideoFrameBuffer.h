// Generated by zsLibEventingTool

#ifdef WRAPPER_USE_CUSTOM_ORG_WEBRTC_VIDEOFRAMEBUFFER
#include <wrapper/override/org_webRtc_VideoFrameBuffer.h>
#else // WRAPPER_USE_CUSTOM_ORG_WEBRTC_VIDEOFRAMEBUFFER
#pragma once

#include "types.h"

namespace wrapper {
  namespace org {
    namespace webRtc {

      struct VideoFrameBuffer
      {
        static VideoFrameBufferPtr wrapper_create() noexcept;
        virtual ~VideoFrameBuffer() noexcept {}
        virtual void wrapper_dispose() noexcept = 0;


        static wrapper::org::webRtc::VideoFrameBufferPtr createFromYuv(
          int width, 
          int height, 
          int strideY, 
          int strideU, 
          int strideV, 
          wrapper::org::webRtc::VideoDataPtr y, 
          wrapper::org::webRtc::VideoDataPtr u, 
          wrapper::org::webRtc::VideoDataPtr v
          ) noexcept;
        static wrapper::org::webRtc::VideoFrameBufferPtr createFromARGB(
          int width, 
          int height, 
          int strideRgb, 
          wrapper::org::webRtc::VideoDataPtr data
          ) noexcept;
        static wrapper::org::webRtc::VideoFrameBufferPtr createFromBGRA(
          int width, 
          int height, 
          int strideRgb, 
          wrapper::org::webRtc::VideoDataPtr data
          ) noexcept;
        static wrapper::org::webRtc::VideoFrameBufferPtr createFromBGRAPtr2(
          int width, 
          int height, 
          int strideRgb, 
          uint64_t dataPtr
          ) noexcept;
        static wrapper::org::webRtc::VideoFrameBufferPtr createFromABGR(
          int width, 
          int height, 
          int strideRgb, 
          wrapper::org::webRtc::VideoDataPtr data
          ) noexcept;
        static wrapper::org::webRtc::VideoFrameBufferPtr createFromRGBA(
          int width, 
          int height, 
          int strideRgb, 
          wrapper::org::webRtc::VideoDataPtr data
          ) noexcept;
        static wrapper::org::webRtc::VideoFrameBufferPtr createFromRGB24(
          int width, 
          int height, 
          int strideRgb, 
          wrapper::org::webRtc::VideoDataPtr data
          ) noexcept;
        virtual wrapper::org::webRtc::VideoFramePlanarYuvBufferPtr toI420() noexcept = 0;
        virtual wrapper::org::webRtc::VideoDataPtr toARGB() noexcept = 0;
        virtual wrapper::org::webRtc::VideoDataPtr toBGRA() noexcept = 0;
        virtual wrapper::org::webRtc::VideoDataPtr toABGR() noexcept = 0;
        virtual wrapper::org::webRtc::VideoDataPtr toRGBA() noexcept = 0;
        virtual wrapper::org::webRtc::VideoDataPtr toRGB24() noexcept = 0;

        virtual wrapper::org::webRtc::VideoFrameBufferType get_type() noexcept = 0;
        virtual int get_width() noexcept = 0;
        virtual int get_height() noexcept = 0;
        virtual wrapper::org::webRtc::VideoFramePlanarYuvBufferPtr get_yuvFrame() noexcept = 0;
        virtual wrapper::org::webRtc::VideoFramePlanarYuvaBufferPtr get_yuvaFrame() noexcept = 0;
        virtual wrapper::org::webRtc::VideoFrameNativeBufferPtr get_nativeFrame() noexcept = 0;
      };

    } // webRtc
  } // org
} // namespace wrapper

#endif // WRAPPER_USE_CUSTOM_ORG_WEBRTC_VIDEOFRAMEBUFFER
