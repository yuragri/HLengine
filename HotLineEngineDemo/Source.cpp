//
////Include and link appropriate libraries and headers//
//#pragma comment(lib, "d3d11.lib")
//#pragma comment(lib, "d3dx11.lib")
//#pragma comment(lib, "d3dx10.lib")
//#pragma comment (lib, "D3D10_1.lib")
//#pragma comment (lib, "DXGI.lib")
//#pragma comment (lib, "D2D1.lib")
//#pragma comment (lib, "dwrite.lib")
//#pragma comment (lib, "dinput8.lib")
//#pragma comment (lib, "dxguid.lib")
//
//#include <windows.h>
//#include <d3d11.h>
//#include <d3dx11.h>
//#include <d3dx10.h>
//#include <xnamath.h>
//#include <D3D10_1.h>
//#include <DXGI.h>
//#include <D2D1.h>
//#include <sstream>
//#include <dwrite.h>
//#include <dinput.h>
//
//#include <string>
//#include <iostream>
//#include <cassert>
//#include "d3dx11effect.h"
//
//#pragma region stencil
//ID3D11DepthStencilState* g_pDSState = NULL;
//ID3D11DepthStencilState* g_pDSStateOutline = NULL;
//ID3D11DepthStencilState* g_pDSStateNoStencil = NULL;
//
//ID3D10Effect*            g_pEffect = NULL;
//ID3D10EffectTechnique*   g_pOutlineTechnique = NULL;
//ID3D10EffectTechnique*   g_pTechnique = NULL;
//
//// Second Render Target Functionality
//ID3D11Texture2D*                    g_pSecondRenderTarget = NULL;
//ID3D11RenderTargetView*				g_pSecondRenderTargetRTView = NULL;
//ID3D11ShaderResourceView*			g_pSecondRenderTargetSRView = NULL;
//
//// Third Render Target Functionality
//ID3D11Texture2D*                    g_pThirdRenderTarget = NULL;
//ID3D11RenderTargetView*				g_pThirdRenderTargetRTView = NULL;
//ID3D11ShaderResourceView*			g_pThirdRenderTargetSRView = NULL;
//
//// Blur Shader Variables
//ID3D10Effect*                       g_pBlurEffect = NULL;
//ID3D10InputLayout*                  g_pBlurVertexLayout = NULL;
//ID3D10EffectTechnique*              g_pBlurTechnique = NULL;
//ID3D10EffectShaderResourceVariable* g_pBlurDiffuseVariable = NULL;
//ID3D10EffectVectorVariable*			g_pBlurOffsets = NULL;
//ID3D10EffectVectorVariable*			g_pBlurWeights = NULL;
//
//ID3D11BlendState* blendState;
//ID3D11BlendState* blendStateNone;
//D3D11_BLEND_DESC blendStateDesc;
//#pragma endregion
//#pragma region moving camera code
//XMVECTOR DefaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
//XMVECTOR DefaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
//XMVECTOR camForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
//XMVECTOR camRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
//
//XMMATRIX camRotationMatrix;
//
//XMMATRIX groundWorld;
//
//float moveLeftRight = 0.0f;
//float moveBackForward = 0.0f;
//
//float camYaw = 0.0f;
//float camPitch = 0.0f;
//
//IDirectInputDevice8* DIKeyboard;
//IDirectInputDevice8* DIMouse;
//
//DIMOUSESTATE mouseLastState;
//LPDIRECTINPUT8 DirectInput;
//#pragma endregion
//#pragma region texture declarations
//ID3D11ShaderResourceView* CubesTexture;
//ID3D11ShaderResourceView* CubesDashedTexture;
//ID3D11SamplerState* CubesTexSamplerState;
//#pragma endregion
////MATRIXES
//XMMATRIX Rotation;
//XMMATRIX Scale;
//XMMATRIX Translation;
//
//#pragma region GLOBAL DECLARATIONS
////Global Declarations - Interfaces//
//IDXGISwapChain* SwapChain;
//ID3D11Device* d3d11Device;
//ID3D11DeviceContext* d3d11DevCon;
//ID3D11RenderTargetView* renderTargetView;
//ID3D11Buffer* squareIndexBuffer;
//ID3D11DepthStencilView* depthStencilView;
//ID3D11Texture2D* depthStencilBuffer;
//ID3D11Buffer* squareVertBuffer;
//ID3D11VertexShader* VS;
//ID3D11PixelShader* PS;
//ID3D10Blob* VS_Buffer;
//ID3D10Blob* PS_Buffer;
//ID3D11InputLayout* vertLayout;
/////////////////**************new**************////////////////////
//ID3D11Buffer* cbPerObjectBuffer;
/////////////////**************new**************////////////////////
//
////Global Declarations - Others//
//LPCTSTR WndClassName = L"firstwindow";
//HWND hwnd = NULL;
//HRESULT hr;
//
//const int Width = 1200;
//const int Height = 700;
//
/////////////////**************new**************////////////////////
//XMMATRIX WVP;
//XMMATRIX WV;
//XMMATRIX P;
//XMMATRIX World1;
//XMMATRIX World1outline;
//XMMATRIX WorldFatLine;
//XMMATRIX WorldRoundedLine;
//
//XMMATRIX worldOutline1;
//XMMATRIX worldOutline2;
//XMMATRIX worldOutline3;
//XMMATRIX worldOutline4;
//XMMATRIX worldOutline5;
//XMMATRIX worldOutline6;
//XMMATRIX worldOutline7;
//XMMATRIX worldOutline8;
//XMMATRIX worldOutline9;
//XMMATRIX worldOutline10;
//XMMATRIX worldOutline11;
//XMMATRIX worldOutline12;
//
//XMMATRIX worldOutline13;
//
//XMMATRIX worldLine;
//
//
//XMMATRIX camView;
//XMMATRIX camProjection;
//
//XMVECTOR camPosition;
//XMVECTOR camTarget;
//XMVECTOR camUp;
/////////////////**************new**************////////////////////
//#pragma endregion
//
////Function Prototypes//
//bool InitializeDirect3d11App(HINSTANCE hInstance);
//void CleanUp();
//bool InitScene();
//void UpdateScene();
//void UpdateCamera();
//void DrawScene();
//
//bool InitDirectInput(HINSTANCE hInstance);
//void DetectInput(double time);
//
//bool InitializeWindow(HINSTANCE hInstance,
//	int ShowWnd,
//	int width, int height,
//	bool windowed);
//int messageloop();
//
//LRESULT CALLBACK WndProc(HWND hWnd,
//	UINT msg,
//	WPARAM wParam,
//	LPARAM lParam);
//
////Create effects constant buffer's structure//
//struct cbPerObject
//{
//	XMMATRIX WVP;
//	XMMATRIX WV;
//	XMMATRIX P;
//	XMFLOAT4 COLOR;
//	float LINE_WIDTH;
//	float MARKER;
//};
//cbPerObject cbPerObj;
//
////#define MARKER_DASHED_LINE = 1;
////#define MARKER_TEXTURED_OBJECT = 2;
//
////Vertex Structure and Vertex Layout (Input Layout)//
//struct Vertex	//Overloaded Vertex Structure
//{
//	Vertex(){}
//	Vertex(float x, float y, float z,
//		float cr, float cg, float cb, float ca,
//		float nx0, float ny0, float nz0
//		, float nx1, float ny1, float nz1,
//		float nx2, float ny2, float nz2, float texu = 0, float texv = 0,
//		float other_x = 0, float other_y = 0, float other_z = 0)
//		: pos(x, y, z), color(cr, cg, cb, ca), normal0(nx0, ny0, nz0), normal1(nx1, ny1, nz1), normal2(nx2, ny2, nz2),
//		texCoord(texu, texv), otherPos(other_x, other_y, other_z) {}
//	//{
//	//	otherPos = (XMFLOAT3)0;
//	//}
//	//void setTextCoord(float u, float v) {
//	//	texCoord.x = u;
//	//	texCoord.y = v;
//	//}
//	XMFLOAT3 pos;
//	XMFLOAT4 color;
//	XMFLOAT3 normal0;
//	XMFLOAT3 normal1;
//	XMFLOAT3 normal2;
//	XMFLOAT2 texCoord;
//	XMFLOAT3 otherPos;
//};
//
//D3D11_INPUT_ELEMENT_DESC layout[] =
//{
//	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//	{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//	{ "NORMAL_ZERO", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 28, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//	{ "NORMAL_FIRST", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 40, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//	{ "NORMAL_SECOND", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 52, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//	{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 64, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//	{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 72, D3D11_INPUT_PER_VERTEX_DATA, 0 }
//};
//UINT numElements = ARRAYSIZE(layout);
//
//
//void drawObject(XMMATRIX * world, Vertex * v, size_t size_v, DWORD * indeces, size_t size_indeces,
//	float line_width = 0.1, XMFLOAT4 color = { 0.0f, 0.0f, 0.0f, 0.0f });
//
//#pragma region MODEL
////*********************************************MODEL******************************************
//#pragma region CUBE
//Vertex v1[] =
//{
//	Vertex(-1.0f, -1.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f, 
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 1.0f),
//	Vertex(-1.0f, +1.0f, -1.0f,
//	0.0f, 1.0f, 0.0f, 1.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f),
//	Vertex(+1.0f, +1.0f, -1.0f,
//	0.0f, 0.0f, 1.0f, 1.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f),
//	Vertex(+1.0f, -1.0f, -1.0f,
//	1.0f, 1.0f, 0.0f, 1.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	1.0f,1.0f),
//
//	Vertex(-1.0f, -1.0f, +1.0f,
//	0.0f, 1.0f, 1.0f, 1.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, +1.0f, +1.0f,
//	1.0f, 1.0f, 1.0f, 1.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//	Vertex(+1.0f, +1.0f, +1.0f,
//	1.0f, 0.0f, 1.0f, 1.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//	Vertex(+1.0f, -1.0f, +1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//};
//
//DWORD indices1[] = {
//	// front face
//	0, 1, 2,
//	0, 2, 3,
//	// back face
//	4, 6, 5,
//	4, 7, 6,
//	// left face
//	4, 5, 1,
//	4, 1, 0,
//	// right face
//	3, 2, 6,
//	3, 6, 7,
//	// top face
//	1, 5, 6,
//	1, 6, 2,
//	// bottom face
//	4, 0, 3,
//	4, 3, 7
//};
//
//DWORD indicesBackOfTheCube[] = {
//	//// front face
//	//0, 1, 2,
//	//0, 2, 3,
//	// back face
//	4, 6, 5,
//	4, 7, 6,
//	//// left face
//	//4, 5, 1,
//	//4, 1, 0,
//	//// right face
//	//3, 2, 6,
//	//3, 6, 7,
//	//// top face
//	//1, 5, 6,
//	//1, 6, 2,
//	//// bottom face
//	//4, 0, 3,
//	//4, 3, 7
//};
//#pragma endregion
//
//#pragma region CUBEOutline
//Vertex v1outline[] =
//{
//	Vertex(-1.0f, -1.1f, -1.1f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, +1.0f, -1.1f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//	Vertex(+1.1f, +1.0f, -1.1f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//	Vertex(+1.1f, -1.1f, -1.1f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//
//	Vertex(-1.0f, -1.1f, +1.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, +1.0f, +1.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//	Vertex(+1.1f, +1.0f, +1.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//	Vertex(+1.1f, -1.1f, +1.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//};
//
//DWORD indices1outline[] = {
//	// front face
//	0, 1, 2,
//	0, 2, 3,
//	// back face
//	4, 6, 5,
//	4, 7, 6,
//	// left face
//	4, 5, 1,
//	4, 1, 0,
//	// right face
//	3, 2, 6,
//	3, 6, 7,
//	// top face
//	1, 5, 6,
//	1, 6, 2,
//	// bottom face
//	4, 0, 3,
//	4, 3, 7
//};
//#pragma endregion
//
//#pragma region outline1 (LeftFront)
////Create the vertex buffer
//Vertex outline1[] =
//{
//	Vertex(-3.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f, 
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f, 
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f, 
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f, 
//	-1.0f, 0.0f, 0.0f)
//};
//DWORD outline1indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
//#pragma endregion
//
//#pragma region outline2 (LeftBack)
//Vertex outline2[] =
//{
//	Vertex(-3.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, +1.0f,
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, +1.0f,
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, +1.0f,
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, +1.0f,
//	-1.0f, 0.0f, 0.0f)
//};
//
//DWORD outline2indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
////**********************************************MODEL****************************************
//#pragma endregion 
//
//#pragma region outline3 (UpBack)
//Vertex outline3[] =
//{
//	Vertex(-3.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, 1.0f),
//	Vertex(-1.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, 1.0f),
//	Vertex(-1.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, 1.0f),
//	Vertex(-3.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, 1.0f)
//};
//
//DWORD outline3indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
////**********************************************MODEL****************************************
//#pragma endregion 
//
//#pragma region outline4 (UpFront)
////Create the vertex buffer
//Vertex outline4[] =
//{
//	Vertex(-3.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f),
//	Vertex(-1.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f),
//	Vertex(-1.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f),
//	Vertex(-3.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f)
//};
//
//DWORD outline4indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
//#pragma endregion
//
//#pragma region outline5 (RightFront)
//Vertex outline5[] =
//{
//	Vertex(-1.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f)
//};
//
//DWORD outline5indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
////**********************************************MODEL****************************************
//#pragma endregion 
//
//#pragma region outline6 (RightBack)
//Vertex outline6[] =
//{
//	Vertex(-1.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 1.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 1.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 1.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 1.0f,
//	1.0f, 0.0f, 0.0f)
//};
//
//DWORD outline6indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
////**********************************************MODEL****************************************
//#pragma endregion 
//
//#pragma region outline7 (DownBack)
//Vertex outline7[] =
//{
//	Vertex(-3.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	0.0f, 0.0f, 1.0f),
//	Vertex(-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	0.0f, 0.0f, 1.0f),
//	Vertex(-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	0.0f, 0.0f, 1.0f),
//	Vertex(-3.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	0.0f, 0.0f, 1.0f)
//};
//
//DWORD outline7indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
////**********************************************MODEL****************************************
//#pragma endregion 
//
//#pragma region outline8 (DownFront)
//Vertex outline8[] =
//{
//	Vertex(-3.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 1.0f,
//	0.0f, -1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f),
//	Vertex(-1.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 1.0f,
//	0.0f, -1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f),
//	Vertex(-1.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, -1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f),
//	Vertex(-3.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, -1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f)
//};
//
//DWORD outline8indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
////**********************************************MODEL****************************************
//#pragma endregion 
//
//#pragma region outline9 (LeftUpCenter)
//Vertex outline9[] =
//{
//	Vertex(-3.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f),
//};
//
//DWORD outline9indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
////**********************************************MODEL****************************************
//#pragma endregion 
//
//#pragma region outline10 (LeftDownCenter)
//Vertex outline10[] =
//{
//	Vertex(-3.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f),
//	Vertex(-3.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f),
//};
//
//DWORD outline10indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
////**********************************************MODEL****************************************
//#pragma endregion 
//
//#pragma region outline13(RightDownCenter)
//Vertex outline13[] =
//{
//	Vertex(-1.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, 0.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, -1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//};
//
//DWORD outline13indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
////**********************************************MODEL****************************************
//#pragma endregion 
//
//#pragma region outline11 (RightUpCenter)
//Vertex outline11[] =
//{
//	Vertex(-1.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//};
//
//DWORD outline11indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
//
//#pragma endregion 
//
////strange bug appears if this region is deleted
//#pragma region outline12 (RightDownCenter)
//Vertex outline12[] =
//{
//	Vertex(-1.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, +2.0f, -2.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	-1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//	Vertex(-1.0f, +2.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f),
//
//};
//
//DWORD outline12indices[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
////**********************************************MODEL****************************************
//#pragma endregion
//
//#pragma endregion
//#pragma region lineVertexes
//Vertex lineVertexes[] =
//{
//	Vertex(-5.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//	Vertex(3.0f, 0.0f, 0.0f,
//	1.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f),
//}; 
//////*******************************************MODEL****************************************
////#pragma endregion
//#pragma endregion
//
//#pragma region FAT_LINE
//Vertex fat_line_vertexes[] =
//{
//	Vertex(-3.0f, +1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	0.0f, 0.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f),
//	Vertex(5.0f, +1.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 1.0f,
//	0.0f, 0.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f),
//	Vertex(5.0f, +1.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 1.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f),
//	Vertex(-3.0f, +1.0f, 0.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f)
//};
//
//DWORD fat_line_indeces[] = {
//	0, 1, 2,
//	2, 1, 0,
//
//	0, 2, 3,
//	3, 2, 0,
//};
//#pragma endregion
//
//#pragma region rounded line
//Vertex rounded_line_vertexes[] =
//{
//	//Vertex(-5.0f, -2.0f, -1.0f,
//	Vertex(-5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.25f, 0.75f,
//	5.0f, 0.0f, -1.0f),
//	//Vertex(-5.0f, 2.0f, -1.0f,
//	Vertex(-5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.25f, 0.25f,
//	5.0f, 0.0f, -1.0f),
//	//Vertex(5.0f, 2.0f, -1.0f,
//	Vertex(5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.75f, 0.25f,
//	-5.0f, 0.0f, -1.0f),
//	//Vertex(5.0f, -2.0f, -1.0f,
//	Vertex(5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.75f, 0.75f,
//	-5.0f, 0.0f, -1.0f),
//
//	//left halfcircle
//	Vertex(-5.5f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	1.0f, 0.0f,
//	-5.0f, 0.0f, -1.0f),
//	Vertex(-5.5f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, 0.0f,
//	-5.0f, 0.0f, -1.0f),
//	Vertex(-5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, 0.5f,
//	-5.5f, 0.0f, -1.0f),
//	Vertex(-5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	1.0f, 0.5f,
//	-5.5f, 0.0f, -1.0f),
//
//	//right halfcircle
//	Vertex(5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	1.0f, 0.5f,
//	5.5f, 0.0f, -1.0f),
//	Vertex(5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, 0.5f,
//	5.5f, 0.0f, -1.0f),
//	Vertex(5.5f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, 1.0f,
//	5.0f, 0.0f, -1.0f),
//	Vertex(5.5f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	1.0f, 1.0f,
//	5.0f, 0.0f, -1.0f),
//};
//DWORD rounded_line_indeces[] = {
//	0, 1, 2,
//	0, 2, 3,
//
//	//4, 5, 6,
//	//4, 6, 7,
//
//	//8, 9, 10,
//	//8, 10, 11,
//};
//
//
//
//#pragma endregion
//
////#pragma region rounded line2
////Vertex rounded_line_vertexes[] =
////{
////	//Vertex(-5.0f, -2.0f, -1.0f,
////	Vertex(-5.0f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, -1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	0.25f, 0.75f,
////	5.0f, 0.0f, -1.0f),
////	//Vertex(-5.0f, 2.0f, -1.0f,
////	Vertex(-5.0f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, 1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	0.25f, 0.25f,
////	5.0f, 0.0f, -1.0f),
////	//Vertex(5.0f, 2.0f, -1.0f,
////	Vertex(5.0f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, 1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	0.75f, 0.25f,
////	-5.0f, 0.0f, -1.0f),
////	//Vertex(5.0f, -2.0f, -1.0f,
////	Vertex(5.0f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, -1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	0.75f, 0.75f,
////	-5.0f, 0.0f, -1.0f),
////
////	//left halfcircle
////	Vertex(-5.5f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, -1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	1.0f, 0.0f),
////	Vertex(-5.5f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, 1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	0.0f, 0.0f),
////	Vertex(-5.0f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, 1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	0.0f, 0.5f),
////	Vertex(-5.0f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, -1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	1.0f, 0.5f),
////
////	//right halfcircle
////	Vertex(5.0f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, -1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	1.0f, 0.5f),
////	Vertex(5.0f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, 1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	0.0f, 0.5f),
////	Vertex(5.5f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, 1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	0.0f, 1.0f),
////	Vertex(5.5f, 0.0f, -1.0f,
////	1.0f, 0.0f, 0.0f, 1.0f,
////	0.0f, 0.0f, -1.0f,
////	0.0f, 1.0f, 0.0f,
////	0.0f, 0.0f, -1.0f,
////	1.0f, 1.0f),
////};
////DWORD rounded_line_indeces[] = {
////	0, 1, 2,
////	0, 2, 3,
////
////	4, 5, 6,
////	4, 6, 7,
////
////	8, 9, 10,
////	8, 10, 11,
////};
////
////#pragma endregion
//
//#pragma region line
//Vertex line_vertexes[] =
//{
//	//Vertex(-5.0f, -2.0f, -1.0f,
//	Vertex(-5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	1.0f, 0.0f,
//	5.0f, 0.0f, -1.0f ),
//	//Vertex(-5.0f, 2.0f, -1.0f,
//	//if third parameter == 1.0f, 1.0f, 1.0f, - this is expandable vector with sign + 
//	//if third parameter == 1.0f, 1.0f, -1.0f, - this is expandable vector with sign - 
//	Vertex(-5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, 0.0f,
//	5.0f, 0.0f, -1.0f),
//	//Vertex(5.0f, 2.0f, -1.0f,
//	//if third parameter == 1.0f, 1.0f, 1.0f, - this is expandable vector with sign + 
//	//if third parameter == 1.0f, 1.0f, -1.0f, - this is expandable vector with sign - 
//	Vertex(5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, -1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	0.0f, 0.5f,
//	-5.0f, 0.0f, -1.0f),
//	//Vertex(5.0f, -2.0f, -1.0f,
//	Vertex(5.0f, 0.0f, -1.0f,
//	1.0f, 0.0f, 0.0f, 1.0f,
//	1.0f, 1.0f, 1.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, -1.0f,
//	1.0f, 0.5f,
//	-5.0f, 0.0f, -1.0f),
//};
//DWORD line_indeces[] = {
//	0, 1, 2,
//	0, 2, 3,
//};
//
//#pragma endregion
//
//int WINAPI WinMain(HINSTANCE hInstance,	//Main windows function
//	HINSTANCE hPrevInstance,
//	LPSTR lpCmdLine,
//	int nShowCmd)
//{
//
//	if (!InitializeWindow(hInstance, nShowCmd, Width, Height, true))
//	{
//		MessageBox(0, L"Window Initialization - Failed",
//			L"Error", MB_OK);
//		return 0;
//	}
//
//	if (!InitializeDirect3d11App(hInstance))	//Initialize Direct3D
//	{
//		MessageBox(0, L"Direct3D Initialization - Failed",
//			L"Error", MB_OK);
//		return 0;
//	}
//
//	if (!InitScene())	//Initialize our scene
//	{
//		MessageBox(0, L"Scene Initialization - Failed",
//			L"Error", MB_OK);
//		return 0;
//	}
//
//	if (!InitDirectInput(hInstance))
//	{
//		MessageBox(0, L"Direct Input Initialization - Failed",
//			L"Error", MB_OK);
//		return 0;
//	}
//
//	messageloop();
//
//	CleanUp();
//
//	return 0;
//}
//
//bool InitializeWindow(HINSTANCE hInstance,
//	int ShowWnd,
//	int width, int height,
//	bool windowed)
//{
//	typedef struct _WNDCLASS {
//		UINT cbSize;
//		UINT style;
//		WNDPROC lpfnWndProc;
//		int cbClsExtra;
//		int cbWndExtra;
//		HANDLE hInstance;
//		HICON hIcon;
//		HCURSOR hCursor;
//		HBRUSH hbrBackground;
//		LPCTSTR lpszMenuName;
//		LPCTSTR lpszClassName;
//	} WNDCLASS;
//
//	WNDCLASSEX wc;
//
//	wc.cbSize = sizeof(WNDCLASSEX);
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.lpfnWndProc = WndProc;
//	wc.cbClsExtra = NULL;
//	wc.cbWndExtra = NULL;
//	wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = WndClassName;
//	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//
//	if (!RegisterClassEx(&wc))
//	{
//		MessageBox(NULL, L"Error registering class",
//			L"Error", MB_OK | MB_ICONERROR);
//		return 1;
//	}
//
//	hwnd = CreateWindowEx(
//		NULL,
//		WndClassName,
//		L"Lesson 4 - Begin Drawing",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		width, height,
//		NULL,
//		NULL,
//		hInstance,
//		NULL
//		);
//
//	if (!hwnd)
//	{
//		MessageBox(NULL, L"Error creating window",
//			L"Error", MB_OK | MB_ICONERROR);
//		return 1;
//	}
//
//	ShowWindow(hwnd, ShowWnd);
//	UpdateWindow(hwnd);
//
//	return true;
//}
//
//
//
//// variables to hold the current rasterizer state and its description
//ID3D11RasterizerState * rState;
//D3D11_RASTERIZER_DESC rDesc;
//
////http://blog.vertexwahn.de/Wordpress/?p=138
//void checkMultisampleQualityLevels()
//{
//	for (UINT sampleCount = 1; sampleCount <= D3D11_MAX_MULTISAMPLE_SAMPLE_COUNT; sampleCount++)
//	{
//		UINT asd;
//		UINT maxQualityLevel;
//		hr = d3d11Device->CheckMultisampleQualityLevels(
//			DXGI_FORMAT_R8G8B8A8_UNORM, sampleCount, &maxQualityLevel);
//
//		if (maxQualityLevel > 0)
//		{
//			maxQualityLevel--;
//		}
//
//		if (hr != S_OK)
//		{
//			asd = 0;
//			//BLUE_LOG_STREAM_EX(
//			//	log_category,
//			//	buw::eLogSeverityLevel::Error) << "CheckMultisampleQualityLevels failed.";
//		}
//
//		if (maxQualityLevel > 0)
//		{
//			asd = 0;
//			//BLUE_LOG_STREAM_EX(log_category,
//			//	buw::eLogSeverityLevel::Trace) <<
//			//	"MSAA " << sampleCount << "X supported with " <<
//			//	maxQualityLevel << " quality levels.";
//		}
//	}
//}
//
//Vertex * createRoundedLine(XMFLOAT3 v1, XMFLOAT3 v2, float radius) {
//	float v1Length = sqrt(pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2));
//	float v2Length = sqrt(pow(v2.x, 2) + pow(v2.y, 2) + pow(v2.z, 2));
//	XMFLOAT3 directionVector(((v1.x - v2.x) / v1Length) * radius,
//		((v1.y - v2.y) / v1Length) * radius,
//		((v1.z - v2.z) / v1Length) * radius);
//	XMFLOAT3 reversedDirectionVector(((v2.x - v1.x) / v1Length) * radius,
//		((v2.y - v1.y) / v1Length) * radius,
//		((v2.z - v1.z) / v1Length) * radius);
//
//	//we prolung the line to create half circle of radius
//	XMFLOAT3 leftHalfCircleEndPoint(v1.x + directionVector.x, v1.y + directionVector.y, v1.z + directionVector.z);
//	XMFLOAT3 rightHalfCircleEndPoint(v2.x + reversedDirectionVector.x, v2.y + reversedDirectionVector.y, v2.z + reversedDirectionVector.z);
//
//	Vertex * vertexes = new Vertex[12];
//	vertexes[0] = Vertex(v1.x, v1.y, v1.z,
//		0.0f, 0.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, -1.0f,
//		0.0f, 0.0f, 0.0f,
//		0.0f, 0.0f, 0.0f,
//		0.25f, 0.75f,
//		v2.x, v2.y, v2.z);
//	vertexes[1] = Vertex(v1.x, v1.y, v1.z,
//		0.0f, 0.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, 1.0f,
//		0.0f, 0.0f, 0.0f,
//		0.0f, 0.0f, 0.0f,
//		0.25f, 0.25f,
//		v2.x, v2.y, v2.z);
//	vertexes[2] = Vertex(v2.x, v2.y, v2.z,
//		0.0f, 0.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, -1.0f,
//		0.0f, 0.0f, 0.0f,
//		0.0f, 0.0f, 0.0f,
//		0.75f, 0.25f,
//		v1.x, v1.y, v1.z);
//	vertexes[3] = Vertex(v2.x, v2.y, v2.z,
//		0.0f, 0.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, 1.0f,
//		0.0f, 0.0f, 0.0f,
//		0.0f, 0.0f, 0.0f,
//		0.75f, 0.75f,
//		v1.x, v1.y, v1.z);
//	//left halfcircle
//	vertexes[4] = Vertex(leftHalfCircleEndPoint.x, leftHalfCircleEndPoint.y, leftHalfCircleEndPoint.z,
//		1.0f, 0.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, -1.0f,
//		0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, -1.0f,
//		1.0f, 0.0f,
//		v1.x, v1.y, v1.z);
//	vertexes[5] = Vertex(leftHalfCircleEndPoint.x, leftHalfCircleEndPoint.y, leftHalfCircleEndPoint.z,
//		1.0f, 0.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, 1.0f,
//		0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, -1.0f,
//		0.0f, 0.0f,
//		v1.x, v1.y, v1.z);
//	vertexes[6] = Vertex(v1.x, v1.y, v1.z,
//		1.0f, 0.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, -1.0f,
//		0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, -1.0f,
//		0.0f, 0.5f,
//		leftHalfCircleEndPoint.x, leftHalfCircleEndPoint.y, leftHalfCircleEndPoint.z);
//	vertexes[7] = Vertex(v1.x, v1.y, v1.z,
//		1.0f, 0.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, 1.0f,
//		0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, -1.0f,
//		1.0f, 0.5f,
//		leftHalfCircleEndPoint.x, leftHalfCircleEndPoint.y, leftHalfCircleEndPoint.z);
//	//right halfcircle
//	vertexes[8] = Vertex(rightHalfCircleEndPoint.x, rightHalfCircleEndPoint.y, rightHalfCircleEndPoint.z,
//		0.0f, 1.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, -1.0f,
//		0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, -1.0f,
//		1.0f, 0.0f,
//		v2.x, v2.y, v2.z);
//	vertexes[9] = Vertex(rightHalfCircleEndPoint.x, rightHalfCircleEndPoint.y, rightHalfCircleEndPoint.z,
//		0.0f, 1.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, 1.0f,
//		0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, -1.0f,
//		0.0f, 0.0f,
//		v2.x, v2.y, v2.z);
//	vertexes[10] = Vertex(v2.x, v2.y, v2.z,
//		0.0f, 1.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, -1.0f,
//		0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, -1.0f,
//		0.0f, 0.5f,
//		rightHalfCircleEndPoint.x, rightHalfCircleEndPoint.y, rightHalfCircleEndPoint.z);
//	vertexes[11] = Vertex(v2.x, v2.y, v2.z,
//		0.0f, 1.0f, 0.0f, 1.0f,
//		1.0f, 1.0f, 1.0f,
//		0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, -1.0f,
//		1.0f, 0.5f,
//		rightHalfCircleEndPoint.x, rightHalfCircleEndPoint.y, rightHalfCircleEndPoint.z);
//	return vertexes;
//}
//void drawRoundedLine(XMFLOAT3 v1, XMFLOAT3 v2, float radius, float line_width, XMFLOAT4 color) {
//
//	Vertex * ver = createRoundedLine(v1, v2, radius);
//	drawObject(&WorldRoundedLine, ver,
//		12, rounded_line_indeces, ARRAYSIZE(rounded_line_indeces), line_width * 10, color);
//	//**************setting marker to 1 which means this is a dashed line************************
//	cbPerObj.MARKER = 2;
//	d3d11DevCon->UpdateSubresource(cbPerObjectBuffer, 0, NULL, &cbPerObj, 0, 0);
//	d3d11DevCon->VSSetConstantBuffers(0, 1, &cbPerObjectBuffer);
//	d3d11DevCon->PSSetConstantBuffers(0, 1, &cbPerObjectBuffer);
//	//***************************************************************************************
//	d3d11DevCon->PSSetShaderResources(0, 1, &CubesTexture);
//	d3d11DevCon->PSSetSamplers(0, 1, &CubesTexSamplerState);
//	//******************************************************************************************
//	//ID3D11BlendState bs;
//	//d3d11DevCon->OMSetBlendState(&bs, 0);
//	//*****************************************************************************************
//	d3d11DevCon->DrawIndexed(sizeof(rounded_line_indeces), 0, 0);
//}
//
//bool InitializeDirect3d11App(HINSTANCE hInstance)
//{
//
//	//Describe our SwapChain Buffer
//	DXGI_MODE_DESC bufferDesc;
//
//	ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));
//
//	bufferDesc.Width = Width;
//	bufferDesc.Height = Height;
//	bufferDesc.RefreshRate.Numerator = 60;
//	bufferDesc.RefreshRate.Denominator = 1;
//	bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
//	bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
//	bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
//
//
//	//Describe our SwapChain
//	DXGI_SWAP_CHAIN_DESC swapChainDesc;
//	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
//	swapChainDesc.BufferDesc = bufferDesc;
//	swapChainDesc.SampleDesc.Count = 1;
//	swapChainDesc.SampleDesc.Quality = 0;
//	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
//	swapChainDesc.BufferCount = 1;
//	swapChainDesc.OutputWindow = hwnd;
//	swapChainDesc.Windowed = TRUE;
//	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
//
//	static const D3D_FEATURE_LEVEL lvl[] = {
//		D3D_FEATURE_LEVEL_9_1
//	};
//	D3D_FEATURE_LEVEL featureLevel;
//	//Create our SwapChain
//	hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, lvl, 1,
//		D3D11_SDK_VERSION, &swapChainDesc, &SwapChain, &d3d11Device, &featureLevel, &d3d11DevCon);
//
//	//hr = d3d11Device->CheckMultisampleQualityLevels();
//	//Create our BackBuffer
//	ID3D11Texture2D* BackBuffer;
//	hr = SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&BackBuffer);
//
//	//Create our Render Target
//	hr = d3d11Device->CreateRenderTargetView(BackBuffer, NULL, &renderTargetView);
//	BackBuffer->Release();
//
//	//Describe our Depth/Stencil Buffer
//	D3D11_TEXTURE2D_DESC depthStencilDesc;
//
//	depthStencilDesc.Width = Width;
//	depthStencilDesc.Height = Height;
//	depthStencilDesc.MipLevels = 1;
//	depthStencilDesc.ArraySize = 1;
//	depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
//	depthStencilDesc.SampleDesc.Count = 1;
//	depthStencilDesc.SampleDesc.Quality = 0;
//	depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;
//	depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
//	depthStencilDesc.CPUAccessFlags = 0;
//	depthStencilDesc.MiscFlags = 0;
//
//	////Create the Depth/Stencil View
//	d3d11Device->CreateTexture2D(&depthStencilDesc, NULL, &depthStencilBuffer);
//	d3d11Device->CreateDepthStencilView(depthStencilBuffer, NULL, &depthStencilView);
//
//	//Set our Render Target
//	d3d11DevCon->OMSetRenderTargets(1, &renderTargetView, depthStencilView);
//
//#pragma region stencil buffer is here
//	//***************************STENCIL BUFFER IS HERE*********************
//	//*******************************************
//	// Initialize a depth stencil buffere suitable for glows.
//	D3D11_TEXTURE2D_DESC descDepth;
//	descDepth.Width = Width;
//	descDepth.Height = Height;
//	descDepth.MipLevels = 1;
//	descDepth.ArraySize = 1;
//
//	// "S8" reserves eight of the thirty-two bits for stenciling.
//
//	ID3D11Texture2D* g_pDepthStencil = NULL;
//	descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
//	descDepth.SampleDesc.Count = 1;
//	descDepth.SampleDesc.Quality = 0;
//	descDepth.Usage = D3D11_USAGE_DEFAULT;
//	descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
//	descDepth.CPUAccessFlags = 0;
//	descDepth.MiscFlags = 0;
//	d3d11Device->CreateTexture2D(&descDepth, NULL, &g_pDepthStencil);
//
//	// Set up a view for the depth stencil buffer.
//	D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
//	ID3D11DepthStencilView* g_pDSView = NULL;
//	ZeroMemory(&descDSV, sizeof(D3D11_DEPTH_STENCIL_VIEW_DESC));
//	descDSV.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
//	descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
//	descDSV.Texture2D.MipSlice = 0;
//	d3d11Device->CreateDepthStencilView
//		(g_pDepthStencil, &descDSV, &g_pDSView);
//
//	// Create depth stencil state corresponding to step one of the article.
//	D3D11_DEPTH_STENCIL_DESC dsDesc;
//	dsDesc.DepthEnable = true;
//	dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
//	dsDesc.DepthFunc = D3D11_COMPARISON_LESS;
//
//	// Stencil test parameters
//	dsDesc.StencilEnable = true;
//	dsDesc.StencilReadMask = 0xFF;
//	dsDesc.StencilWriteMask = 0xFF;
//#pragma region stencil operations
//	// Stencil operations if pixel is front-facing.
//
//	// Keep original value on fail.
//	dsDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
//	dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
//	// Write to the stencil on pass.
//	dsDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_INCR_SAT;
//	dsDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
//
//	// Stencil operations if pixel is back-facing.
//	// Since we do not care about back-facing pixels, always keep original value.
//	dsDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
//	dsDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
//	dsDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
//	dsDesc.BackFace.StencilFunc = D3D11_COMPARISON_NEVER;
//	
//	// Create the depth stencil state.
//
//	d3d11Device->CreateDepthStencilState(&dsDesc, &g_pDSState);
//
//	// Create depth stencil state corresponding to step two of the article.
//	dsDesc.DepthEnable = true;
//	dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
//	dsDesc.DepthFunc = D3D11_COMPARISON_LESS;
//
//	dsDesc.StencilEnable = true;
//	dsDesc.StencilReadMask = 0xFF;
//	dsDesc.StencilWriteMask = 0xFF;
//
//	// It does not matter what we write since we are not using the values after this step.
//	// In other words, we are only using the values to mask pixels.
//	dsDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
//	dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
//	dsDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
//	// The stencil test passes if the passed parameter is equal to value in the buffer.
//	dsDesc.FrontFace.StencilFunc = D3D11_COMPARISON_EQUAL;
//
//	// Again, we do not care about back-facing pixels.
//	dsDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
//	dsDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
//	dsDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
//	dsDesc.BackFace.StencilFunc = D3D11_COMPARISON_NEVER;
//	// Create the depth stencil state.
//	d3d11Device->CreateDepthStencilState(&dsDesc, &g_pDSStateOutline);
//
//#pragma endregion
//
//
//
//	dsDesc.DepthEnable = false;
//	dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
//	dsDesc.DepthFunc = D3D11_COMPARISON_NEVER;
//
//
//	dsDesc.StencilEnable = false;
//	d3d11Device->CreateDepthStencilState(&dsDesc, &g_pDSStateNoStencil);
//	//*******************************************
//#pragma endregion
//	checkMultisampleQualityLevels();
////#pragma region creating second and third render targets
////	// Set up the second and third render targets.
////	D3D11_TEXTURE2D_DESC desc;
////	ZeroMemory(&desc, sizeof(desc));
////	desc.Width = Width;
////	desc.Height = Height;
////	desc.MipLevels = 1;
////	desc.ArraySize = 1;
////	desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
////	desc.SampleDesc.Count = 1;
////	desc.Usage = D3D11_USAGE_DEFAULT;
////	desc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
////
////	d3d11Device->CreateTexture2D(&desc, NULL, &g_pSecondRenderTarget);
////	d3d11Device->CreateTexture2D(&desc, NULL, &g_pThirdRenderTarget);
////#pragma endregion
////#pragma region Set up the resource view for the second and third render targets
////	// Set up the resource view for the second and third render targets.
////	D3D11_RENDER_TARGET_VIEW_DESC rtDesc;
////	rtDesc.Format = desc.Format;
////	rtDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
////	rtDesc.Texture2D.MipSlice = 0;
////
////	d3d11Device->CreateRenderTargetView(g_pSecondRenderTarget, &rtDesc, &g_pSecondRenderTargetRTView);
////	d3d11Device->CreateRenderTargetView(g_pThirdRenderTarget, &rtDesc, &g_pThirdRenderTargetRTView);
////
////	// Set up the shader resource view for the second and third render targets.
////	D3D11_SHADER_RESOURCE_VIEW_DESC srDesc;
////	srDesc.Format = desc.Format;
////	srDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
////	srDesc.Texture2D.MostDetailedMip = 0;
////	srDesc.Texture2D.MipLevels = 1;
////
////	d3d11Device->CreateShaderResourceView(g_pSecondRenderTarget, &srDesc, &g_pSecondRenderTargetSRView);
////	d3d11Device->CreateShaderResourceView(g_pThirdRenderTarget, &srDesc, &g_pThirdRenderTargetSRView);
////#pragma endregion
//	return true;
//}
//
//void CleanUp()
//{
//	//Release the COM Objects we created
//	SwapChain->Release();
//	d3d11Device->Release();
//	d3d11DevCon->Release();
//	renderTargetView->Release();
//	squareVertBuffer->Release();
//	squareIndexBuffer->Release();
//	VS->Release();
//	PS->Release();
//	VS_Buffer->Release();
//	PS_Buffer->Release();
//	vertLayout->Release();
//
//	depthStencilView->Release();
//	depthStencilBuffer->Release();
//	///////////////**************new**************////////////////////
//	cbPerObjectBuffer->Release();
//	DIKeyboard->Release();
//	DIMouse->Release();
//	///////////////**************new**************////////////////////
//	SwapChain->SetFullscreenState(false, NULL);
//	PostMessage(hwnd, WM_DESTROY, 0, 0);
//}
//
//bool InitScene()
//{
////#pragma region ADDING SPECIAL EFFECT (special way in directx 11)
////	// Compile effect from HLSL file into binary Blob in memory
////	ID3D10Blob *effectBlob = 0, *errorsBlob = 0;
////	HRESULT hr = D3DX11CompileFromFile(L"StencilGlow.fx", 0, 0, 0, "fx_4_0", 0, 0, 0, &effectBlob, &errorsBlob, 0);
////	assert(SUCCEEDED(hr) && effectBlob);
////	if (errorsBlob) {
////		errorsBlob->Release();
////	}
////
////	// Create D3DX11 effect from compiled binary memory block
////	ID3DX11Effect *g_Effect;
////	LPVOID a = effectBlob->GetBufferPointer();
////	SIZE_T s = effectBlob->GetBufferSize();
////	hr = D3DX11CreateEffectFromMemory(
////		effectBlob->GetBufferPointer(), effectBlob->GetBufferSize(), 0, d3d11Device, &g_Effect);
////	//assert(SUCCEEDED(hr));
////	effectBlob->Release();
////
////	////The effect itself is not enough.You need to retrieve object that represents "pass" to use it.
////	////So you get a technique from the effect(by index or by name) and then the pass from the technique.
////	//ID3DX11EffectTechnique *g_EffectTechnique; // No need to be Release()-d.
////	//g_EffectTechnique = g_Effect->GetTechniqueByIndex(0);
////	////assert(g_EffectTechnique && g_EffectTechnique->IsValid());
////
////	//ID3DX11EffectPass *g_EffectPass; // No need to be Release()-d.
////	//g_EffectPass = g_EffectTechnique->GetPassByIndex(0);
////	////assert(g_EffectPass && g_EffectPass->IsValid());
////#pragma endregion
//
//	//Compile Shaders from shader file
//	hr = D3DX11CompileFromFile(L"Source.fx", 0, 0, "VS", "vs_4_0_level_9_1", 0, 0, 0, &VS_Buffer, 0, 0);
//	hr = D3DX11CompileFromFile(L"Source.fx", 0, 0, "PS", "ps_4_0_level_9_1", 0, 0, 0, &PS_Buffer, 0, 0);
//
//	//Create the Shader Objects
//	hr = d3d11Device->CreateVertexShader(VS_Buffer->GetBufferPointer(), VS_Buffer->GetBufferSize(), NULL, &VS);
//	hr = d3d11Device->CreatePixelShader(PS_Buffer->GetBufferPointer(), PS_Buffer->GetBufferSize(), NULL, &PS);
//
//	//Set Vertex and Pixel Shaders
//	d3d11DevCon->VSSetShader(VS, 0, 0);
//	d3d11DevCon->PSSetShader(PS, 0, 0);
//	
//	//Create the Viewport
//	D3D11_VIEWPORT viewport;
//	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));
//
//	viewport.TopLeftX = 0;
//	viewport.TopLeftY = 0;
//	viewport.Width = Width;
//	viewport.Height = Height;
//	viewport.MinDepth = 0.0f;
//	viewport.MaxDepth = 1.0f;
//
//	//Set the Viewport
//	d3d11DevCon->RSSetViewports(1, &viewport);
//
//	///////////////**************new**************////////////////////
//	//Create the buffer to send to the cbuffer in effect file
//	D3D11_BUFFER_DESC cbbd;
//	ZeroMemory(&cbbd, sizeof(D3D11_BUFFER_DESC));
//
//	cbbd.Usage = D3D11_USAGE_DEFAULT;
//	cbbd.ByteWidth = sizeof(cbPerObject);
//	cbbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
//	cbbd.CPUAccessFlags = 0;
//	cbbd.MiscFlags = 0;
//
//	hr = d3d11Device->CreateBuffer(&cbbd, NULL, &cbPerObjectBuffer);
//
//	//Camera information
//	camPosition = XMVectorSet(-1.99f, 3.0f, -5.0f, 0.0f);
//	camTarget = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
//	camUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
//
//	//Set the View matrix
//	camView = XMMatrixLookAtLH(camPosition, camTarget, camUp);
//
//	//Set the Projection matrix
//	camProjection = XMMatrixPerspectiveFovLH(0.4f*3.14f, (float)Width / Height, 1.0f, 1000.0f);
//	///////////////**************new**************////////////////////
//
//#pragma region add textures
//	/////////////////**************new**************////////////////////
//	D3DX11_IMAGE_LOAD_INFO loadInfo;
//	loadInfo.Width = D3DX11_DEFAULT;
//	loadInfo.Height = D3DX11_DEFAULT;
//	loadInfo.Depth = D3DX11_DEFAULT; 
//	loadInfo.FirstMipLevel = D3DX11_DEFAULT;
//	loadInfo.MipLevels = D3DX11_DEFAULT;
//	loadInfo.Usage = D3D11_USAGE_IMMUTABLE;
//	loadInfo.BindFlags = D3D11_BIND_SHADER_RESOURCE;
//	loadInfo.CpuAccessFlags = 0;
//	loadInfo.MiscFlags = 0;
//	
//	//loadInfo.Format = DXGI_FORMAT_B8G8R8X8_UNORM_SRGB;
//	loadInfo.Format = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
//	//loadInfo.Filter = D3DX11_FILTER_SRGB_IN | D3DX11_FILTER_SRGB_OUT | D3DX11_FILTER_NONE;
//	loadInfo.Filter = D3DX10_FILTER_LINEAR;
//	loadInfo.MipFilter = D3DX11_DEFAULT;
//	loadInfo.pSrcInfo = NULL;
//
//	hr = D3DX11CreateShaderResourceViewFromFile(d3d11Device, L"circle_texture_for_line.dds",
//		NULL, NULL, &CubesTexture, NULL);
//
//
//	//ID3D11BlendState* blendState;
//	//D3D11_BLEND_DESC blendStateDesc;
//	ZeroMemory(&blendStateDesc, sizeof(D3D11_BLEND_DESC));
//	blendStateDesc.RenderTarget[0].BlendEnable = TRUE;
//	blendStateDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
//	blendStateDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
//	blendStateDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
//	blendStateDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_DEST_ALPHA;
//	blendStateDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_DEST_ALPHA;
//	blendStateDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
//	blendStateDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
//	//float* factor = 0.5f;
//	d3d11Device->CreateBlendState(&blendStateDesc, &blendState);
//	blendStateDesc.RenderTarget[0].BlendEnable = FALSE;
//	d3d11Device->CreateBlendState(&blendStateDesc, &blendStateNone);
//	//d3d11DevCon->OMSetBlendState(blendState, NULL, 0xFFFFFF);
//	/////////////////**************new**************////////////////////
//#pragma endregion
//	return true;
//}
//
//void UpdateScene()
//{
//	//Reset cube1World
//	//World1 = XMMatrixIdentity();
//
//	////Define cube1's world space matrix
//	/////////////////**************new**************////////////////////
//	//Scale = XMMatrixScaling(500.0f, 10.0f, 500.0f);
//	//Translation = XMMatrixTranslation(0.0f, 10.0f, 0.0f);
//
//	////Set cube1's world space using the transformations
//	//World1 = Scale * Translation;
//
//	//*****************RasterizerState*******************
//	ID3D11RasterizerState * rasterizerStateWireFrame;
//	D3D11_RASTERIZER_DESC rd;
//	ZeroMemory(&rd, sizeof(rd));
//	rd.AntialiasedLineEnable = false;
//	rd.CullMode = D3D11_CULL_BACK;
//	rd.DepthBias = 0;
//	rd.DepthBiasClamp = 0.0f;
//	rd.DepthClipEnable = true;
//	rd.FillMode = D3D11_FILL_SOLID;
//	rd.FrontCounterClockwise = false;
//	rd.MultisampleEnable = false;
//	rd.ScissorEnable = false;
//	rd.SlopeScaledDepthBias = 0.0f;
//
//	d3d11Device->CreateRasterizerState(&rd, &rasterizerStateWireFrame);
//	d3d11DevCon->RSSetState(rasterizerStateWireFrame);
//	//*************************************************
//	//ID3D11RasterizerState * g_pRasterState;
//
//	//D3D11_RASTERIZER_DESC rasterizerState;
//	//rasterizerState.FillMode = D3D11_FILL_SOLID;
//	//rasterizerState.CullMode = D3D11_CULL_NONE;
//	//rasterizerState.FrontCounterClockwise = true;
//	//rasterizerState.DepthBias = false;
//	//rasterizerState.DepthBiasClamp = 0;
//	//rasterizerState.SlopeScaledDepthBias = 0;
//	//rasterizerState.DepthClipEnable = false;
//	//rasterizerState.ScissorEnable = false;
//	//rasterizerState.MultisampleEnable = true;
//	//rasterizerState.AntialiasedLineEnable = true;
//	//d3d11Device->CreateRasterizerState(&rasterizerState, &g_pRasterState);
//	//d3d11DevCon->RSSetState(g_pRasterState);
//}
//
//void DrawScene()
//{
//	d3d11DevCon->OMSetBlendState(blendStateNone, NULL, 0xFFFFFF);
//	//Clear our backbuffer
//	float bgColor[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
//	d3d11DevCon->ClearRenderTargetView(renderTargetView, bgColor);
//
//	//Refresh the Depth/Stencil view
//	d3d11DevCon->ClearDepthStencilView(depthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
//
//	//Set the World/View/Projection matrix, then send it to constant buffer in effect file
//	World1 = XMMatrixIdentity();
//	Translation = XMMatrixTranslation(-1.0f, 0.0f, 0.0f);
//	World1 *= Translation;
//
//	worldLine = XMMatrixIdentity();
//	Translation = XMMatrixTranslation(-1.0f, 0.0f, 0.0f);
//	worldLine *= Translation;
//
//	World1outline = XMMatrixIdentity();
//	Translation = XMMatrixTranslation(-1.05f, 0.05f, 0.05f);
//	World1outline *= Translation;
//
//	WorldFatLine = XMMatrixIdentity();
//	Translation = XMMatrixTranslation(-2.0f, 0.5f, 0.5f);
//	WorldFatLine *= Translation;
//
//	WorldRoundedLine = XMMatrixIdentity();
//	Translation = XMMatrixTranslation(-1.0f, 0.0f, 0.0f);
//	WorldRoundedLine *= Translation;
//
//#pragma region set outlines translation
//	worldOutline1 = XMMatrixIdentity();
//	Translation = XMMatrixTranslation(1.0f, -1.0f, 1.0f);
//	worldOutline1 *= Translation;
//
//	worldOutline2 = XMMatrixIdentity();
//	worldOutline2 *= Translation;
//
//	worldOutline3 = XMMatrixIdentity();
//	worldOutline3 *= Translation;
//
//	worldOutline4 = XMMatrixIdentity();
//	worldOutline4 *= Translation;
//
//	worldOutline5 = XMMatrixIdentity();
//	worldOutline5 *= Translation;
//
//	worldOutline6 = XMMatrixIdentity();
//	worldOutline6 *= Translation;
//
//	worldOutline7 = XMMatrixIdentity();
//	worldOutline7 *= Translation;
//
//	worldOutline8 = XMMatrixIdentity();
//	worldOutline8 *= Translation;
//
//	worldOutline9 = XMMatrixIdentity();
//	worldOutline9 *= Translation;
//
//	worldOutline10 = XMMatrixIdentity();
//	worldOutline10 *= Translation;
//
//	worldOutline11 = XMMatrixIdentity();
//	worldOutline11 *= Translation;
//
//	worldOutline12 = XMMatrixIdentity();
//	worldOutline12 *= Translation;
//
//	worldOutline13 = XMMatrixIdentity();
//	worldOutline13 *= Translation;
//#pragma endregion
//	//drawObject(&World1, v1, 8, indices1, 36);
//
//#pragma region DRAW DASHED LINE
//	float line_width = 0.025f;
//	XMFLOAT4 color = { 0.0f, 0.0f, 0.0f, 1.0f };
//
//	////drawObject(&WorldFatLine, fat_line_vertexes, 4, fat_line_indeces, 12, line_width*4, color);
//	//////**************setting marker to 1 which means this is a dashed line************************
//	////cbPerObj.MARKER = 1;
//	////d3d11DevCon->UpdateSubresource(cbPerObjectBuffer, 0, NULL, &cbPerObj, 0, 0);
//	////d3d11DevCon->VSSetConstantBuffers(0, 1, &cbPerObjectBuffer);
//	////d3d11DevCon->PSSetConstantBuffers(0, 1, &cbPerObjectBuffer);
//	//////*****************************************************************************************
//	////d3d11DevCon->DrawIndexed(12, 0, 0);
//
//	////******************Draw textured line**************************************
//	d3d11DevCon->OMSetBlendState(blendState, NULL, 0xFFFFFF);
//	drawRoundedLine({ -5.0f, 5.0f, -1.0f }, { 5.0f, 1.0f, -1.0f }, 0.5f, line_width, color);
//	//drawRoundedLine({ -1.0f, 1.0f, -1.0f }, { -1.0f, -1.0f, -1.0f }, 0.1f, line_width, color);
//	//drawRoundedLine({ -1.0f, 1.0f, -1.0f }, { -1.0f, 1.0f, 1.0f }, 0.1f, line_width, color);
//
//	//drawRoundedLine({ -1.0f, 1.0f, -1.0f }, { -1.0f, 1.0f, 1.0f }, 0.1f, line_width, color);
//	d3d11DevCon->OMSetBlendState(blendStateNone, NULL, 0xFFFFFF);
//	//****************************************************************************
//
//	////drawObject(&WorldRoundedLine, line_vertexes, 4, line_indeces, sizeof(line_indeces), line_width * 10, color);
//	////d3d11DevCon->DrawIndexed(sizeof(line_indeces), 0, 0);
//#pragma endregion
//
//#pragma region Store Original DSState
//	// Store Original DSState
//	ID3D11DepthStencilState* pOrigDSState;
//	UINT pDSRef;
//	d3d11DevCon->OMGetDepthStencilState(&pOrigDSState, &pDSRef);
//#pragma endregion
//
//#pragma region Store Original RT.
//	// Store Original RT.
//	ID3D11RenderTargetView* pOrigRTView;
//	d3d11DevCon->OMGetRenderTargets(1, &pOrigRTView, NULL);
//#pragma endregion
//	d3d11DevCon->OMSetDepthStencilState(g_pDSState, 0);
//	drawObject(&worldOutline1, outline1, 4, outline1indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//	drawObject(&worldOutline2, outline2, 4, outline2indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//	drawObject(&worldOutline3, outline3, 4, outline3indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//	drawObject(&worldOutline4, outline4, 4, outline4indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//	drawObject(&worldOutline5, outline5, 4, outline5indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//	drawObject(&worldOutline6, outline6, 4, outline6indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//	drawObject(&worldOutline7, outline7, 4, outline7indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//	drawObject(&worldOutline8, outline8, 4, outline8indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//	drawObject(&worldOutline9, outline9, 4, outline9indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//	drawObject(&worldOutline10, outline10, 4, outline10indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//	drawObject(&worldOutline11, outline11, 4, outline11indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//	drawObject(&worldOutline13, outline13, 4, outline13indices, 12, line_width, color);
//	d3d11DevCon->DrawIndexed(12, 0, 0);
//
//#pragma region Stencil Code
//#pragma region ARTICLE: step 1 Render the model into the frame, depth, and stencil buffers.
//	// Set the stencil state corresponding to step 1 of the article.
//	d3d11DevCon->OMSetDepthStencilState(g_pDSState, 0);
//	drawObject(&World1, v1, 8, indices1, 36);
//	d3d11DevCon->PSSetShaderResources(0, 1, &CubesTexture);
//	d3d11DevCon->PSSetSamplers(0, 1, &CubesTexSamplerState);
//	d3d11DevCon->DrawIndexed(36, 0, 0);
//
//#pragma endregion
//#pragma region ARTICLE: step 2 Render a larger scale of the model into the frame and depth buffers while masking pixels against values currently in the stencil buffer.
//	// Set the stencil state corresponding to step 2 of the article.
//	d3d11DevCon->OMSetDepthStencilState(g_pDSStateOutline, 0);
//	drawObject(&World1outline, v1outline, 8, indices1outline, 36);
//	d3d11DevCon->DrawIndexed(36, 0, 0);
//#pragma endregion
//#pragma region Restore the original DS state and view
//	// Restore the original DS state.
//	d3d11DevCon->OMSetDepthStencilState(pOrigDSState, pDSRef);
//
//	//TODO:WHAT is g_pDSView;
//	// Restore the orignal DS view.
//	//3,000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000d3d11DevCon->OMSetRenderTargets(1, &pOrigRTView, g_pDSView);
//#pragma endregion
//#pragma region Release the pointers
//	//pOrigDSState->Release();
//	pOrigRTView->Release();
//#pragma endregion
//#pragma endregion
//	//Present the backbuffer to the screen
//	SwapChain->Present(0, 0);
//}
//
//
////void draw
//void drawObject(XMMATRIX * world, Vertex * v, size_t size_v, DWORD * indeces, size_t size_indeces,	
//	float line_width, XMFLOAT4 color)
//{
//	#pragma region VSSetConstantBuffers 
//		WVP = (*world) * camView * camProjection;
//		cbPerObj.WVP = XMMatrixTranspose(WVP);
//		//cbPerObj.WVP = WVP;
//		WV = (*world) * camView;
//		P = camProjection;
//		cbPerObj.WV = XMMatrixTranspose(WV);
//		//cbPerObj.WV = WV;
//		cbPerObj.P = XMMatrixTranspose(P);
//		//cbPerObj.P = P;
//		cbPerObj.COLOR = color;
//		cbPerObj.LINE_WIDTH = line_width;
//		cbPerObj.MARKER = 0.0f;
//
//
//		d3d11DevCon->UpdateSubresource(cbPerObjectBuffer, 0, NULL, &cbPerObj, 0, 0);
//		d3d11DevCon->VSSetConstantBuffers(0, 1, &cbPerObjectBuffer);
//		d3d11DevCon->PSSetConstantBuffers(0, 1, &cbPerObjectBuffer);
//	#pragma endregion
//
//	#pragma region IASetInputLayout
//		//Create the Input Layout
//		hr = d3d11Device->CreateInputLayout(layout, numElements, VS_Buffer->GetBufferPointer(),
//			VS_Buffer->GetBufferSize(), &vertLayout);
//
//		//Set the Input Layout
//		d3d11DevCon->IASetInputLayout(vertLayout);
//	#pragma endregion
//
//	#pragma region IASetVertexBuffers
//		D3D11_BUFFER_DESC vertexBufferDesc;
//		ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));
//
//		vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
//		vertexBufferDesc.ByteWidth = sizeof(Vertex)* size_v;
//		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
//		vertexBufferDesc.CPUAccessFlags = 0;
//		vertexBufferDesc.MiscFlags = 0;
//
//		D3D11_SUBRESOURCE_DATA vertexBufferData;
//
//		ZeroMemory(&vertexBufferData, sizeof(vertexBufferData));
//		vertexBufferData.pSysMem = v;
//		hr = d3d11Device->CreateBuffer(&vertexBufferDesc, &vertexBufferData, &squareVertBuffer);
//
//		//Set the vertex buffer
//		UINT stride = sizeof(Vertex);
//		UINT offset = 0;
//		d3d11DevCon->IASetVertexBuffers(0, 1, &squareVertBuffer, &stride, &offset);
//	#pragma endregion
//
//	#pragma region IASetIndexBuffer
//		D3D11_BUFFER_DESC indexBufferDesc;
//		ZeroMemory(&indexBufferDesc, sizeof(indexBufferDesc));
//
//		indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
//		indexBufferDesc.ByteWidth = sizeof(DWORD)* size_indeces;
//		indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
//		indexBufferDesc.CPUAccessFlags = 0;
//		indexBufferDesc.MiscFlags = 0;
//
//		D3D11_SUBRESOURCE_DATA iinitData;
//
//		iinitData.pSysMem = indeces;
//		d3d11Device->CreateBuffer(&indexBufferDesc, &iinitData, &squareIndexBuffer);
//
//		d3d11DevCon->IASetIndexBuffer(squareIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
//	#pragma endregion 
//
//	#pragma region IASetPrimitiveTopology
//		d3d11DevCon->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
//	#pragma endregion
//
//	////Draw the triangle
//	//d3d11DevCon->DrawIndexed(size_indeces, 0, 0);
//}
//
//#pragma region moving camera code
//bool InitDirectInput(HINSTANCE hInstance)
//{
//	hr = DirectInput8Create(hInstance,
//		DIRECTINPUT_VERSION,
//		IID_IDirectInput8,
//		(void**)&DirectInput,
//		NULL);
//
//	hr = DirectInput->CreateDevice(GUID_SysKeyboard,
//		&DIKeyboard,
//		NULL);
//
//	hr = DirectInput->CreateDevice(GUID_SysMouse,
//		&DIMouse,
//		NULL);
//
//	hr = DIKeyboard->SetDataFormat(&c_dfDIKeyboard);
//	hr = DIKeyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
//
//	hr = DIMouse->SetDataFormat(&c_dfDIMouse);
//	hr = DIMouse->SetCooperativeLevel(hwnd, DISCL_EXCLUSIVE | DISCL_NOWINKEY | DISCL_FOREGROUND);
//
//	return true;
//}
//
//void UpdateCamera()
//{
//	camRotationMatrix = XMMatrixRotationRollPitchYaw(camPitch, camYaw, 0);
//	camTarget = XMVector3TransformCoord(DefaultForward, camRotationMatrix);
//	camTarget = XMVector3Normalize(camTarget);
//
//	char s[256];
//	sprintf(s, "camYaw is %d \n", camYaw);
//	OutputDebugStringA(s);
//
//	XMMATRIX RotateYTempMatrix;
//	RotateYTempMatrix = XMMatrixRotationY(camPitch);
//
//	camRight = XMVector3TransformCoord(DefaultRight, RotateYTempMatrix);
//	camUp = XMVector3TransformCoord(camUp, RotateYTempMatrix);
//	camForward = XMVector3TransformCoord(DefaultForward, RotateYTempMatrix);
//
//	camPosition += moveLeftRight*camRight;
//	camPosition += moveBackForward*camForward;
//
//	moveLeftRight = 0.0f;
//	moveBackForward = 0.0f;
//
//	camTarget = camPosition + camTarget;
//
//	camView = XMMatrixLookAtLH(camPosition, camTarget, camUp);
//}
//
//void DetectInput()
//{
//	DIMOUSESTATE mouseCurrState;
//
//	BYTE keyboardState[256];
//
//	DIKeyboard->Acquire();
//	DIMouse->Acquire();
//
//	DIMouse->GetDeviceState(sizeof(DIMOUSESTATE), &mouseCurrState);
//
//	DIKeyboard->GetDeviceState(sizeof(keyboardState), (LPVOID)&keyboardState);
//
//	if (keyboardState[DIK_ESCAPE] & 0x80)
//		PostMessage(hwnd, WM_DESTROY, 0, 0);
//
//	float speed = 15.0f * 0.001;
//
//	if (keyboardState[DIK_A] & 0x80)
//	{
//		moveLeftRight -= speed;
//	}
//	if (keyboardState[DIK_D] & 0x80)
//	{
//		moveLeftRight += speed;
//	}
//	if (keyboardState[DIK_W] & 0x80)
//	{
//		moveBackForward += speed;
//	}
//	if (keyboardState[DIK_S] & 0x80)
//	{
//		moveBackForward -= speed;
//	}
//	if ((mouseCurrState.lX != mouseLastState.lX) || (mouseCurrState.lY != mouseLastState.lY))
//	{
//		camYaw += mouseLastState.lX * 0.001f;
//
//		camPitch += mouseCurrState.lY * 0.001f;
//
//		mouseLastState = mouseCurrState;
//	}
//
//	UpdateCamera();
//
//	return;
//}
//#pragma endregion 
//
//int messageloop(){
//	MSG msg;
//	ZeroMemory(&msg, sizeof(MSG));
//	while (true)
//	{
//		BOOL PeekMessageL(
//			LPMSG lpMsg,
//			HWND hWnd,
//			UINT wMsgFilterMin,
//			UINT wMsgFilterMax,
//			UINT wRemoveMsg
//			);
//
//		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
//		{
//			if (msg.message == WM_QUIT)
//				break;
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//		else{
//			// run game code 
//
//			DetectInput();
//			UpdateScene();
//			DrawScene();
//		}
//	}
//	return msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd,
//	UINT msg,
//	WPARAM wParam,
//	LPARAM lParam)
//{
//	switch (msg)
//	{
//	case WM_KEYDOWN:
//		if (wParam == VK_ESCAPE){
//			DestroyWindow(hwnd);
//		}
//		return 0;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return DefWindowProc(hwnd,
//		msg,
//		wParam,
//		lParam);
//}
//
//
//#pragma region renderBlur
////HRESULT RenderBlur(ID3D10Device* pd3dDevice, ID3D10RenderTargetView* pOrigRTV)
////{
////	HRESULT hr = S_OK;
////
////	//const DXGI_SURFACE_DESC *pSwapChainDesc;
////	//pSwapChainDesc = DXUTGetDXGIBackBufferSurfaceDesc();
////	//DWORD height = (DWORD)(pSwapChainDesc->Height) / 2;
////	//DWORD width = (DWORD)(pSwapChainDesc->Width) / 2;
////	DWORD height = Width / 2;
////	DWORD width = Width / 2;
////
////
////	// Horizontal Blur
////	{
////		D3DXVECTOR4 afSampleOffsets[15];
////		D3DXVECTOR4 afSampleWeights[15];
////		hr = GetBlurOffsets(width, afSampleOffsets, afSampleWeights, 3.0f, 1.25f);
////		for (unsigned i = 0; i < 15; i++)
////		{
////			afSampleOffsets[i] = D3DXVECTOR4(afSampleOffsets[i][0], 0.0f, 0.0f, 0.0f);
////		}
////		g_pBlurOffsets->SetFloatVectorArray((float*)afSampleOffsets, 0, 15);
////		g_pBlurWeights->SetFloatVectorArray((float*)afSampleWeights, 0, 15);
////
////		ID3D11RenderTargetView* aRTViews[1] = { g_pThirdRenderTargetRTView };
////		//pd3dDevice->OMSetRenderTargets(1, aRTViews, NULL);
////
////		g_pBlurDiffuseVariable->SetResource(g_pSecondRenderTargetSRView);
////
////		// Render the horizontal portion of the blur.
////		D3D10_VIEWPORT vpOld[D3D10_VIEWPORT_AND_SCISSORRECT_MAX_INDEX];
////		UINT nViewPorts = 1;
////		pd3dDevice->RSGetViewports(&nViewPorts, vpOld);
////
////		// Setup the viewport to match the backbuffer
////		D3D10_VIEWPORT vp;
////		vp.Width = pSwapChainDesc->Width;
////		vp.Height = pSwapChainDesc->Height;
////		vp.MinDepth = 0.0f;
////		vp.MaxDepth = 1.0f;
////		vp.TopLeftX = 0;
////		vp.TopLeftY = 0;
////		pd3dDevice->RSSetViewports(1, &vp);
////
////		UINT strides = sizeof(ScreenVertex);
////		UINT offsets = 0;
////		ID3D10Buffer* pBuffers[1] = { g_pScreenQuadVB };
////
////		pd3dDevice->IASetInputLayout(g_pBlurVertexLayout);
////		pd3dDevice->IASetVertexBuffers(0, 1, pBuffers, &strides, &offsets);
////		pd3dDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
////
////		D3D10_TECHNIQUE_DESC techDesc;
////		g_pBlurTechnique->GetDesc(&techDesc);
////
////		for (UINT p = 0; p < techDesc.Passes; ++p)
////		{
////			g_pBlurTechnique->GetPassByIndex(p)->Apply(0);
////			pd3dDevice->Draw(4, 0);
////		}
////
////		// Restore the Old viewport
////		pd3dDevice->RSSetViewports(nViewPorts, vpOld);
////
////		ID3D10ShaderResourceView* pViewsNull[4] = { 0, 0, 0, 0 };
////		pd3dDevice->PSSetShaderResources(0, 4, pViewsNull);
////	}
////
////	// Vertical Blur
////	{
////		D3DXVECTOR4 afSampleOffsets[15];
////		D3DXVECTOR4 afSampleWeights[15];
////		hr = GetBlurOffsets(height, afSampleOffsets, afSampleWeights, 3.0f, 1.25f);
////		for (unsigned i = 0; i < 15; i++)
////		{
////			afSampleOffsets[i] = D3DXVECTOR4(0.0f, afSampleOffsets[i][0], 0.0f, 0.0f);
////		}
////		g_pBlurOffsets->SetFloatVectorArray((float*)afSampleOffsets, 0, 15);
////		g_pBlurWeights->SetFloatVectorArray((float*)afSampleWeights, 0, 15);
////
////		ID3D10RenderTargetView* aRTViews[1] = { g_pSecondRenderTargetRTView };
////		pd3dDevice->OMSetRenderTargets(1, aRTViews, NULL);
////
////		g_pBlurDiffuseVariable->SetResource(g_pThirdRenderTargetSRView);
////
////		// Render the horizontal portion of the blur.
////		D3D10_VIEWPORT vpOld[D3D10_VIEWPORT_AND_SCISSORRECT_MAX_INDEX];
////		UINT nViewPorts = 1;
////		pd3dDevice->RSGetViewports(&nViewPorts, vpOld);
////
////		// Setup the viewport to match the backbuffer
////		D3D10_VIEWPORT vp;
////		vp.Width = pSwapChainDesc->Width;
////		vp.Height = pSwapChainDesc->Height;
////		vp.MinDepth = 0.0f;
////		vp.MaxDepth = 1.0f;
////		vp.TopLeftX = 0;
////		vp.TopLeftY = 0;
////		pd3dDevice->RSSetViewports(1, &vp);
////
////		UINT strides = sizeof(ScreenVertex);
////		UINT offsets = 0;
////		ID3D10Buffer* pBuffers[1] = { g_pScreenQuadVB };
////
////		pd3dDevice->IASetInputLayout(g_pBlurVertexLayout);
////		pd3dDevice->IASetVertexBuffers(0, 1, pBuffers, &strides, &offsets);
////		pd3dDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
////
////		D3D10_TECHNIQUE_DESC techDesc;
////		g_pBlurTechnique->GetDesc(&techDesc);
////
////		for (UINT p = 0; p < techDesc.Passes; ++p)
////		{
////			g_pBlurTechnique->GetPassByIndex(p)->Apply(0);
////			pd3dDevice->Draw(4, 0);
////		}
////
////		// Restore the Old viewport
////		pd3dDevice->RSSetViewports(nViewPorts, vpOld);
////
////		ID3D10ShaderResourceView* pViewsNull[4] = { 0, 0, 0, 0 };
////		pd3dDevice->PSSetShaderResources(0, 4, pViewsNull);
////	}
////
////	return hr;
////}
//float GaussianDistribution(float x, float y, float rho)
//{
//	float g = 1.0f / sqrtf(2.0f * D3DX_PI * rho * rho);
//	g *= expf(-(x * x + y * y) / (2 * rho * rho));
//
//	return g;
//}
//HRESULT GetBlurOffsets(DWORD dwD3DTexSize,
//	D3DXVECTOR4 afTexCoordOffset[15],
//	D3DXVECTOR4 avColorWeight[15],
//	float fDeviation, float fMultiplier)
//{
//	int i = 0;
//	float tu = 1.0f / (float)dwD3DTexSize;
//
//	// Fill the center texel
//	float weight = 1.0f * GaussianDistribution(0, 0, fDeviation);
//	avColorWeight[7] = D3DXVECTOR4(weight, weight, weight, weight);
//
//	afTexCoordOffset[7][0] = 0.0f;
//
//	// Fill one side
//	for (i = 1; i < 8; i++)
//	{
//		weight = fMultiplier * GaussianDistribution((float)i, 0, fDeviation);
//		afTexCoordOffset[7 - i][0] = -i * tu;
//
//		avColorWeight[7 - i] = D3DXVECTOR4(weight, weight, weight, weight);
//	}
//
//	// Copy to the other side
//	for (i = 8; i < 15; i++)
//	{
//		avColorWeight[i] = avColorWeight[14 - i];
//		afTexCoordOffset[i] = -afTexCoordOffset[14 - i];
//	}
//
//	return S_OK;
//}
//
//
//#pragma endregion
