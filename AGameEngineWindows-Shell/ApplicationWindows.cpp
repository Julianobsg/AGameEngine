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
	toolkitSpriteBatch->Draw( g_pTextureRV1, XMFLOAT2(10, 75 ), nullptr, Colors::White );
	toolkitSpriteBatch->End();
}

void ApplicationWindows::Init()
{
	//InitSpriteBatch( );
}

HRESULT ApplicationWindows::InitSpriteBatch(ID3D11Device* pd3dDevice)
{
	HRESULT hr;

	auto dx11DeviceContext = DXUTGetD3D11DeviceContext();
	//V_RETURN( g_DialogResourceManager.OnD3D11CreateDevice( pd3dDevice, dx11DeviceContext ) );

	toolkitSpriteBatch.reset( new SpriteBatch( dx11DeviceContext ) );
	WCHAR str[MAX_PATH];

	// Load the Texture
	//V_RETURN( DXUTFindDXSDKMediaFileCch( str, MAX_PATH, L"D:\\Projects\\DXUT+DirectXTK Simpl1\\Media\\Misc\\windowslogo.dds" ) );
	V_RETURN( DXUTFindDXSDKMediaFileCch( str, MAX_PATH, L"D:\\Bibliotecas\\Imagens\\Ryu\\Ryu_474.png" ) );
	//hr = CreateDDSTextureFromFile( pd3dDevice, str, nullptr, &g_pTextureRV1 );
	hr = CreateWICTextureFromFile( pd3dDevice, dx11DeviceContext, str, nullptr, &g_pTextureRV1 );
	
	if( FAILED( hr ) )
		return hr;


}

void ApplicationWindows::InitTextures()
{
	list<GameObject> gos = scenes[currentScene].gameObjects;

}

void ApplicationWindows::Release()
{
	//g_DialogResourceManager.OnD3D11DestroyDevice();

	toolkitSpriteBatch.reset();
	SAFE_RELEASE(g_pTextureRV1);
}
