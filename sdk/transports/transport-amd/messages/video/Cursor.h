/*
Notice Regarding Standards.  AMD does not provide a license or sublicense to
any Intellectual Property Rights relating to any standards, including but not
limited to any audio and/or video codec technologies such as MPEG-2, MPEG-4;
AVC/H.264; HEVC/H.265; AAC decode/FFMPEG; AAC encode/FFMPEG; VC-1; and MP3
(collectively, the "Media Technologies"). For clarity, you will pay any
royalties due for such third party technologies, which may include the Media
Technologies that are owed as a result of AMD providing the Software to you.

This software uses libraries from the FFmpeg project under the LGPLv2.1.

MIT license

Copyright (c) 2024 Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#pragma once

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#endif

#include "transports/transport-amd/messages/Message.h"
#include <string>

namespace ssdk::transport_amd
{
    class CursorData : public Message
    {
    public:
        CursorData();
        CursorData(int32_t width, int32_t height, int32_t pitch, int32_t hotspotX, int32_t hotspotY,
            int32_t captureResolutionX, int32_t captureResolutionY, bool visible, bool monochrome);

        virtual bool FromJSON(amf::JSONParser::Node* root) override;

        inline int32_t GetWidth() const noexcept { return m_Width; }
        inline int32_t GetHeight() const noexcept { return m_Height; }
        inline int32_t GetPitch() const noexcept { return m_Pitch; }
        inline int32_t GetHotspotX() const noexcept { return m_HotspotX; }
        inline int32_t GetHotspotY() const noexcept { return m_HotspotY; }
        inline int32_t GetCaptureResolutionX() const noexcept { return m_CaptureResolutionX; }
        inline int32_t GetCaptureResolutionY() const noexcept { return m_CaptureResolutionY; }
        inline bool GetVisible() const noexcept { return m_Visible; }
        inline bool GetMonochrome() const noexcept { return m_Monochrome; }

    private:
        int32_t m_Width = 0;
        int32_t m_Height = 0;
        int32_t m_Pitch = 0;
        int32_t m_HotspotX = 0;
        int32_t m_HotspotY = 0;
        int32_t m_CaptureResolutionX = 0;
        int32_t m_CaptureResolutionY = 0;
        bool m_Visible = true;
        bool m_Monochrome = false;
    };
}