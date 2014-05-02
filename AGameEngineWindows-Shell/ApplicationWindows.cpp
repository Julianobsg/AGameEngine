#include "DXUT.h"
#include "ApplicationWindows.h"

ApplicationWindows::ApplicationWindows(void) : Application ()
{
}


ApplicationWindows::~ApplicationWindows(void)
{
}

void ApplicationWindows::Draw()
{
	toolkitSpriteBatch->Begin();
	//toolkitSpriteBatch->Draw( g_pTextureRV1, XMFLOAT2(10, 75 ), nullptr, Colors::White );
	/*for (int i = 0; i < inGameTextures.size(); i)
	{
	}*/
	for (std::list<ID3D11ShaderResourceView*>::iterator it = inGameTextures.begin(); it != inGameTextures.end(); it++) 
	{
		toolkitSpriteBatch->Draw( *it, XMFLOAT2(10, 75 ), nullptr, Colors::White );
	}
	toolkitSpriteBatch->End();
}

void ApplicationWindows::Init()
{
	//InitSpriteBatch( );
}

HRESULT ApplicationWindows::InitSpriteBatch(ID3D11Device* pd3dDevice)
{
	this->pd3dDevice = pd3dDevice;
	HRESULT hr;

	dx11DeviceContext = DXUTGetD3D11DeviceContext();

	toolkitSpriteBatch.reset( new SpriteBatch( dx11DeviceContext ) );

	// Load the Texture first scene texture
	return InitTextures();

}

HRESULT ApplicationWindows::InitTextures()
{
	ID3D11ShaderResourceView* tempTexture;
	list<GameObject*> gos = scenes[currentScene].gameObjects;
	HRESULT hr;

	while (!gos.empty())
	{
		GameObject* go = gos.back();
		if (go != NULL)
		{
			Sprite* sprite = dynamic_cast<Sprite*>(go);
			if (sprite != NULL)
			{
				WCHAR str[MAX_PATH];
				std::wstring widestr = L"..\\AGame\\Midia\\" + std::wstring(sprite->texture.begin(), sprite->texture.end());

				DXUTFindDXSDKMediaFileCch( str, MAX_PATH, widestr.c_str() );

				ID3D11ShaderResourceView* generatedSpriteTexture;

				hr = CreateWICTextureFromFile( pd3dDevice, dx11DeviceContext, str, nullptr, &generatedSpriteTexture );

				if( FAILED( hr ) )
					return hr;
				inGameTextures.push_back(generatedSpriteTexture);
			}
		}
		gos.pop_back();
	}
	return hr;
}

void ApplicationWindows::Release()
{
	//g_DialogResourceManager.OnD3D11DestroyDevice();

	toolkitSpriteBatch.reset();
	while (!inGameTextures.empty())
	{
		SAFE_RELEASE(inGameTextures.back());
		inGameTextures.pop_back();
	}
}
