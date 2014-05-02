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
#include "Sprite.h"

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
	
	HRESULT InitTextures();
	
	std::unique_ptr<SpriteBatch> toolkitSpriteBatch;
	
	HRESULT InitSpriteBatch(ID3D11Device*);

	void Release();
private:
	list<ID3D11ShaderResourceView*> inGameTextures;
	ID3D11Device* pd3dDevice;
	ID3D11DeviceContext* dx11DeviceContext;
};

