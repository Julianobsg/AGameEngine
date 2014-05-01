#pragma once
#include "graphics2d.h"
#include <wrl.h>
#include <d3d11_1.h>
#include <d2d1_1.h>
#include <d2d1effects.h>
#include <dwrite_1.h>
#include <wincodec.h>
#include <agile.h>
#include <ppltasks.h>


class Graphics2DDirectX :
	public Graphics2D
{
public:
	Graphics2DDirectX(void);
	~Graphics2DDirectX(void);

	virtual void LoadTexture(string textureName);

	virtual void Draw();
private:
	void CreateTexture( _In_ bool decodeAsDDS, _In_reads_bytes_(dataSize) byte* data, _In_ uint32 dataSize, _Out_opt_ ID3D11Texture2D** texture, _Out_opt_ ID3D11ShaderResourceView** textureView, _In_opt_ Platform::String^ debugName );
};

