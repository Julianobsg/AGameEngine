#pragma once

#include "Application.h"
#include <d3d11_1.h>
#include <wrl.h>
#include "SpriteBatch.h"
#include <memory>
#include <Windows.h>
#include "DDSTextureLoader.h"
#include "DXUTgui.h"
#include "SDKmisc.h"
#include "WICTextureLoader.h"

using namespace Microsoft::WRL;
using namespace DirectX;

class ApplicationWindows :
	public Application
{
public:
	ApplicationWindows(void);
	~ApplicationWindows(void);
	void Draw();

	void Init();
	
	void InitTextures();
	
	std::unique_ptr<SpriteBatch> toolkitSpriteBatch;
	
	HRESULT InitSpriteBatch(ID3D11Device*);

	void Release();
private:
	ID3D11ShaderResourceView* g_pTextureRV1;
	CDXUTDialogResourceManager  g_DialogResourceManager;

};

