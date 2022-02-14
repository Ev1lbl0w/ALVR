#pragma once

#include <memory>
#include "shared/d3drender.h"
#include "alvr_server/ClientConnection.h"
#include "VideoEncoder.h"

// Software video encoder using FFMPEG
class VideoEncoderSW : public VideoEncoder
{
public:
	VideoEncoderSW(std::shared_ptr<CD3DRender> pD3DRender
		, std::shared_ptr<ClientConnection> listener
		, int width, int height);
	~VideoEncoderSW() {}

	void Initialize() {}
	void Shutdown() {}

	void Transmit(ID3D11Texture2D *pTexture, uint64_t presentationTime, uint64_t frameIndex, uint64_t frameIndex2, uint64_t clientTime, bool insertIDR) {}
private:
    std::shared_ptr<CD3DRender> m_d3dRender;
	std::shared_ptr<ClientConnection> m_Listener;

    int m_codec;
	int m_refreshRate;
	int m_renderWidth;
	int m_renderHeight;
	int m_bitrateInMBits;
};
