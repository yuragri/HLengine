//***************************************************************************************
// HotLine Demo
//***************************************************************************************

#include "d3dApp.h"
#include "d3dx11Effect.h"
#include "MathHelper.h"
#include "Camera.h"
#include "Effects.h"
#include "InputLayouts.h"
//-----------------------------------
#include "StateManager.h"
#include "ProcessManager.h"

#include "DrawAllProcess.h"
#include "TestState.h"

#include <functional>


using namespace HotLine;

#if defined(DEBUG) | defined(_DEBUG)
#ifndef HR
#define HR(x)                                              \
		{                                                          \
		HRESULT hr = (x);                                      \
		if(FAILED(hr))                                         \
				{                                                      \
			DXTrace(__FILE__, (DWORD)__LINE__, hr, L#x, true); \
				}                                                      \
		}
#endif

#else
#ifndef HR
#define HR(x) (x)
#endif
#endif 


class Cernel : public D3DApp
{

public:
	Cernel(HINSTANCE hInstance);
	~Cernel();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene(); 

	void OnMouseDown(WPARAM btnState, int x, int y, D3D11_VIEWPORT viewPort);
	void OnMouseUp(WPARAM btnState, int x, int y, D3D11_VIEWPORT viewPort);
	void OnMouseMove(WPARAM btnState, int x, int y, D3D11_VIEWPORT viewPort);

	void OnKeyDown(WPARAM btnState, int x, int y);
	void OnKeyUp(WPARAM btnState, int x, int y);


	void renderStates();

private:

	HotLine::cStateManager* stateManager; 
	//-------------------------------------------------------

	POINT mLastMousePos;

	Camera mCam;
};

//----------------------------------------CREATION OF THE WINDOW-------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
				   PSTR cmdLine, int showCmd)
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

	Cernel theApp(hInstance);
	
	if( !theApp.Init() )
		return 0;
	
	return theApp.Run();
}
//---------------------------------------------------------------------------------------

Cernel::Cernel(HINSTANCE hInstance)
: D3DApp(hInstance)
{
	mMainWndCaption = L"HotLine Demo";
	
	mLastMousePos.x = 0;
	mLastMousePos.y = 0;

	mCam.SetPosition(0.0f, 10.0f, 0.0f);

	stateManager = new HotLine::cStateManager();
}

Cernel::~Cernel()
{
	delete(stateManager);
	Effects::DestroyAll();
	InputLayouts::DestroyAll();
}


//--------listener trial------------------
typedef std::function<void (int)> TaskListener;
void addListener(TaskListener lis)
{
	//test commit
}

TaskListener lis;
//--------listener trial------------------



bool Cernel::Init()
{
	if(!D3DApp::Init())
		return false;

	Effects::InitAll(md3dDevice);
	InputLayouts::InitAll(md3dDevice);

	mCam.SetLens(0.25f*MathHelper::Pi, (float)mClientWidth / (float)mClientHeight, 1.0f, 1000.0f);

	TestState * initialState = new TestState(md3dDevice, &mCam);
	initialState->init();

	//bounding states with each other
	stateManager->push_back(initialState);

	HotLine::screen_view_port = &GetScreenViewPort();

	//--------listener trial------------------
	TaskListener lis;
	lis = [](int a) { a; };
	BaseState * b = stateManager->at(0);
	addListener([b](int a)
	{
		string l = "his is a second listener";
	});
	//--------listener trial------------------

	return true;
}

void Cernel::OnResize()
{
	D3DApp::OnResize();

	// The window resized, so update the aspect ratio and recompute the projection matrix.
	XMMATRIX P = XMMatrixPerspectiveFovLH(0.25f*MathHelper::Pi, AspectRatio(), 1.0f, 1000.0f);
	mCam.SetLens(0.25f*MathHelper::Pi, AspectRatio(), 1.0f, 1000.0f);	
}

void Cernel::UpdateScene(float dt)
{
	////
	//// Control the camera.
	////

	//float camspeed = 4.0f;
	//if (GetAsyncKeyState('W') & 0x8000)
	//	//mCam.Walk(10.0f*dt);
	//	mCam.FlyUp(camspeed*dt);

	//if (GetAsyncKeyState('S') & 0x8000)
	//	//mCam.Walk(-10.0f*dt);
	//	mCam.FlyUp(-camspeed*dt);

	//if (GetAsyncKeyState('A') & 0x8000)
	//	mCam.Strafe(-camspeed*dt);

	//if (GetAsyncKeyState('D') & 0x8000)
	//	mCam.Strafe(camspeed*dt);

	XMFLOAT3 pos = stateManager->back()->getPlayerBodySprite()->getWorldPosition();
	mCam.SetPosition(pos.x, mCam.GetPosition().y, pos.z);

	//UPDATE ANIMATIONS
	for (int i = 0; i < stateManager->back()->animations->size(); ++i)
	{
		bool hasNextFrame = stateManager->back()->animations->at(i)->NextFrame(dt);
		////if (stateManager->back()->animations->at(i)->ReachedEnd())
		////if (!hasNextFrame)
		//{
		//	stateManager->back()->animations->erase(stateManager->back()->animations->begin() + i);
		//	i--;
		//}
	}

	mCam.UpdateViewMatrix();
}

void Cernel::DrawScene()
{
	//preparing to draw------
	md3dImmediateContext->ClearRenderTargetView(mRenderTargetView, reinterpret_cast<const float*>(&Colors::LightSteelBlue));
	md3dImmediateContext->ClearDepthStencilView(mDepthStencilView, D3D11_CLEAR_DEPTH|D3D11_CLEAR_STENCIL, 1.0f, 0);
	//-----------------------
	
	renderStates();

	HR(mSwapChain->Present(0, 0));
}

void Cernel::renderStates()
{
	stateManager->prepare();
	for (int i = 0; i < stateManager->size(); ++i)
	{
		BaseState* resultingState = stateManager->at(i)->render(md3dImmediateContext, mCam.ViewProj());
		if (resultingState)
		{
			stateManager->addState(resultingState);
		}
	}
}
 
//INPUT MANAGER block of the code-----------------------------------------------
//delegating all the input resolvations to State class
void Cernel::OnMouseDown(WPARAM btnState, int x, int y, D3D11_VIEWPORT viewPort)
{
	mLastMousePos.x = x;
	mLastMousePos.y = y;

	//SetCapture(mhMainWnd);
}

void Cernel::OnMouseUp(WPARAM btnState, int x, int y, D3D11_VIEWPORT viewPort)
{
	ReleaseCapture();
}

void Cernel::OnMouseMove(WPARAM btnState, int x, int y, D3D11_VIEWPORT viewPort)
{
	if ((btnState & MK_LBUTTON) != 0)
	{
		// Make each pixel correspond to a quarter of a degree.
		float dx = XMConvertToRadians(0.25f*static_cast<float>(x - mLastMousePos.x));
		float dy = XMConvertToRadians(0.25f*static_cast<float>(y - mLastMousePos.y));

		mCam.Pitch(dy);
		mCam.RotateY(dx);
	}

	mLastMousePos.x = x;
	mLastMousePos.y = y;

	//mScreenViewport

	stateManager->back()->resolveMouseMove(btnState, x, y, mCam.ViewProj(), mScreenViewport);

	////------------------------detecting the mouse world position----------------------------
	//XMFLOAT2 viewPos;
	//viewPos.x = (((x * 2) / mScreenViewport.Width) - 1);
	//viewPos.y = (-(((y * 2) / mScreenViewport.Height) - 1));


	////TODO: camera`s orientation should be taking into the account here 
	//XMFLOAT3 cameraPos = mCam.GetPosition();
	//float aspect = mScreenViewport.Width / mScreenViewport.Height;
	//viewPos.x = (mCam.frustumWidth*aspect / 2)*viewPos.x + cameraPos.x;
	//viewPos.y = (mCam.frustumHeight / 2)*viewPos.y + cameraPos.z;

	//TRACE(L"\nNormalized screen x = %f, y = %f", viewPos.x, viewPos.y);
	//--------------------------------------------------------------------------------------
}

void Cernel::OnKeyDown(WPARAM btnState, int x, int y)
{
	//delegating the onKeyDown to the last added state 
	stateManager->back()->resolveKeyDown(btnState, x, y, mCam.ViewProj());
}
void Cernel::OnKeyUp(WPARAM btnState, int x, int y)
{
	//delegating the onKeyUp to the last added  state 
	stateManager->back()->resolveKeyUp(btnState, x, y, mCam.ViewProj());
}

//-------------------------------------------------------------------------------