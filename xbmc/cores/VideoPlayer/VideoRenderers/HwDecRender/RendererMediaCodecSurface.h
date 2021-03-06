/*
 *      Copyright (C) 2005-2017 Team Kodi
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Kodi; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#if defined(TARGET_ANDROID)

#include "system.h"
#include "cores/VideoPlayer/VideoRenderers/BaseRenderer.h"
#include <chrono>

class CMediaCodecVideoBuffer;

class CRendererMediaCodecSurface : public CBaseRenderer
{
public:
  CRendererMediaCodecSurface();
  virtual ~CRendererMediaCodecSurface();

  static CBaseRenderer* Create(CVideoBuffer *buffer);
  static bool Register();

  virtual bool RenderCapture(CRenderCapture* capture) override;
  virtual void AddVideoPicture(const VideoPicture &picture, int index) override;
  virtual void ReleaseBuffer(int idx) override;
  virtual bool Configure(const VideoPicture &picture, float fps, unsigned flags, unsigned int orientation) override;
  virtual bool IsConfigured() override { return m_bConfigured; };
  virtual bool ConfigChanged(const VideoPicture &picture) { return false; };
  virtual CRenderInfo GetRenderInfo() override;
  virtual void FlipPage(int source) override;
  virtual void UnInit() override {};
  virtual void Reset() override;
  virtual void Update() override {};
  virtual void RenderUpdate(bool clear, unsigned int flags = 0, unsigned int alpha = 255) override;
  virtual bool SupportsMultiPassRendering() override { return false; };

  // Player functions
  virtual bool IsGuiLayer() { return false; };

  // Feature support
  virtual bool Supports(ESCALINGMETHOD method) { return false; };
  virtual bool Supports(ERENDERFEATURE feature);

protected:
  virtual void ReorderDrawPoints() override;

private:

  int m_iRenderBuffer;
  static const int m_numRenderBuffers = 4;

  struct BUFFER
  {
    BUFFER() : videoBuffer(nullptr) {};
    CMediaCodecVideoBuffer *videoBuffer;
    int duration;
  } m_buffers[m_numRenderBuffers];

<<<<<<< HEAD
  std::chrono::time_point<std::chrono::system_clock> m_prevTime;
  bool m_bConfigured;
  unsigned int m_updateCount;
<<<<<<< HEAD
  CRect m_surfDestRect;
=======
=======
  // textures
  virtual bool UploadTexture(int index);
  virtual void DeleteTexture(int index);
  virtual bool CreateTexture(int index);
  
  // hooks for hw dec renderer
  virtual bool LoadShadersHook();
  virtual bool RenderHook(int index);  
  virtual int  GetImageHook(YuvImage *image, int source = AUTOSOURCE, bool readonly = false);
>>>>>>> 3548552... VideoPlayer: rename and move YuvImage
>>>>>>> ab3767c29e... VideoPlayer: rename and move YuvImage
};

#endif
