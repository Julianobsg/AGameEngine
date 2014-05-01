// AGameEngineWindows-Shell.cpp : Defines the entry point for the application.
//

#include "DXUT.h"
#include "AGameEngineWindows-Shell.h"
#include "MainGame.h"
#include "ApplicationWindows.h"

#include "SDKmisc.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					 _In_opt_ HINSTANCE hPrevInstance,
					 _In_ LPTSTR    lpCmdLine,
					 _In_ int       nCmdShow)
{
	//UNREFERENCED_PARAMETER(hPrevInstance);
	//UNREFERENCED_PARAMETER(lpCmdLine);

	//// TODO: Place code here.
	//MSG msg;
	//HACCEL hAccelTable;

	//// Initialize global strings
	//LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	//LoadString(hInstance, IDC_AGAMEENGINEWINDOWSSHELL, szWindowClass, MAX_LOADSTRING);
	//MyRegisterClass(hInstance);

	//// Perform application initialization:
	//if (!InitInstance (hInstance, nCmdShow))
	//{
	//	return FALSE;
	//}

	//hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_AGAMEENGINEWINDOWSSHELL));

	//ApplicationWindows* appWin = new ApplicationWindows();

	//MainGame mainGame = MainGame(appWin);

	//mainGame.Init();


	//// Main message loop:
	//while (GetMessage(&msg, NULL, 0, 0) && appWin->isRunning)
	//{
	//	if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
	//	{
	//		TranslateMessage(&msg);
	//		DispatchMessage(&msg);
	//	} else
	//	{	
	//		appWin->Run();
	//	}
	//}

	//return (int) msg.wParam;

	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

	// DXUT will create and use the best device
	// that is available on the system depending on which D3D callbacks are set below

	// Set DXUT callbacks
	//DXUTSetCallbackMsgProc( MsgProc );
	//DXUTSetCallbackKeyboard( OnKeyboard );
	//DXUTSetCallbackFrameMove( OnFrameMove );
	//DXUTSetCallbackDeviceChanging( ModifyDeviceSettings );

	DXUTSetCallbackD3D11DeviceAcceptable( IsD3D11DeviceAcceptable );
	DXUTSetCallbackD3D11DeviceCreated( OnD3D11CreateDevice );
	//DXUTSetCallbackD3D11SwapChainResized( OnD3D11ResizedSwapChain );
	//DXUTSetCallbackD3D11SwapChainReleasing( OnD3D11ReleasingSwapChain );
	DXUTSetCallbackD3D11DeviceDestroyed( OnD3D11DestroyDevice );
	DXUTSetCallbackD3D11FrameRender( OnD3D11FrameRender );

	InitApp();
	DXUTInit( true, true, nullptr ); // Parse the command line, show msgboxes on error, no extra command line params
	DXUTSetCursorSettings( true, true );
	DXUTCreateWindow( L"A Game Engine" );

	// Only require 10-level hardware, change to D3D_FEATURE_LEVEL_11_0 to require 11-class hardware
	// Switch to D3D_FEATURE_LEVEL_9_x for 10level9 hardware
	DXUTCreateDevice( D3D_FEATURE_LEVEL_10_0, true, 640, 480 );

	DXUTMainLoop(); // Enter into the DXUT render loop

	return DXUTGetExitCode();
}

ApplicationWindows* application;
MainGame* mainGame;

void InitApp()
{
	application = new ApplicationWindows();
	
	mainGame = new MainGame(application);

	mainGame->Init();
}

//--------------------------------------------------------------------------------------
// Render the help and statistics text.
//--------------------------------------------------------------------------------------
void RenderText()
{

}

//--------------------------------------------------------------------------------------
// Reject any D3D11 devices that aren't acceptable by returning false
//--------------------------------------------------------------------------------------
bool CALLBACK IsD3D11DeviceAcceptable( const CD3D11EnumAdapterInfo *AdapterInfo, UINT Output,
									  const CD3D11EnumDeviceInfo *DeviceInfo,
									  DXGI_FORMAT BackBufferFormat, bool bWindowed, void* pUserContext )
{
	return true;
}


//--------------------------------------------------------------------------------------
// Create any D3D11 resources that aren't dependant on the back buffer
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnD3D11CreateDevice( ID3D11Device* pd3dDevice, const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc,
									 void* pUserContext )
{
	application->InitSpriteBatch(pd3dDevice);
	return S_OK;
}

//--------------------------------------------------------------------------------------
// Create any D3D11 resources that depend on the back buffer
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnD3D11ResizedSwapChain( ID3D11Device* pd3dDevice, IDXGISwapChain* pSwapChain,
										 const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext )
{
	return S_OK;
}


//--------------------------------------------------------------------------------------
// Render the scene using the D3D11 device
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D11FrameRender( ID3D11Device* pd3dDevice, ID3D11DeviceContext* pd3dImmediateContext, double fTime,
								 float fElapsedTime, void* pUserContext )
{
	application->Run();
	application->Draw();
}

//--------------------------------------------------------------------------------------
// Release D3D11 resources created in OnD3D11ResizedSwapChain 
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D11ReleasingSwapChain( void* pUserContext )
{
}


//--------------------------------------------------------------------------------------
// Release D3D11 resources created in OnD3D11CreateDevice 
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D11DestroyDevice( void* pUserContext )
{
	DXUTGetGlobalResourceCache().OnDestroyDevice();
	application->Release();
	// Delete additional render resources here...
}


//--------------------------------------------------------------------------------------
// Called right before creating a D3D device, allowing the app to modify the device settings as needed
//--------------------------------------------------------------------------------------
bool CALLBACK ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, void* pUserContext )
{
	return true;
}

//--------------------------------------------------------------------------------------
// Handle updates to the scene.  This is called regardless of which D3D API is used
//--------------------------------------------------------------------------------------
void CALLBACK OnFrameMove( double fTime, float fElapsedTime, void* pUserContext )
{

}

//--------------------------------------------------------------------------------------
// Handle messages to the application
//--------------------------------------------------------------------------------------
LRESULT CALLBACK MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pbNoFurtherProcessing,
						 void* pUserContext )
{


	return 0;
}



//--------------------------------------------------------------------------------------
// Handle key presses
//--------------------------------------------------------------------------------------
void CALLBACK OnKeyboard( UINT nChar, bool bKeyDown, bool bAltDown, void* pUserContext )
{
}

