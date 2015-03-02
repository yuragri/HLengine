#include "TestFace.h"

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

using namespace HotLine;
//
//TestFace::TestFace(float size, XMFLOAT2 topLeftCoord, XMFLOAT2 bottomRightCoord,
//	ID3D11Device* device, Orientation orient) : BaseObject()
//{
//	sprite = new Sprite(size, size, topLeftCoord, bottomRightCoord, device, orient);
//	HR(D3DX11CreateShaderResourceViewFromFile(device, L"Textures/face.dds", 0, 0, &texture, 0));
//}
//
//void TestFace::Draw(ID3D11DeviceContext* context, XMMATRIX& viewProj)
//{
//	sprite->Draw(context, texture, viewProj);
//}
	
