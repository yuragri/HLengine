#include "Grid.h"
using namespace HotLine;

Grid::Grid(ID3D11Device* device)
{
	visible = false;
	//18.9 is just high enough - this may change
	float levelPosition = 5.0;

	int index = 0;

	//X
	sprites[index] = new Sprite(100.f, 0.32f, XMFLOAT2(0, 0), XMFLOAT2(10, 10), device);
	sprites[index]->setWorldPosition(XMFLOAT3(0, levelPosition, 0));
	index++;

	//Y
	sprites[index] = new Sprite(0.32f, 100.f, XMFLOAT2(0, 0), XMFLOAT2(10, 10), device);
	sprites[index]->setWorldPosition(XMFLOAT3(0, levelPosition, 0));
	index++;

	HR(D3DX11CreateShaderResourceViewFromFile(device, L"Textures/Texture1.dds", 0, 0, &mCubeMapSRV2, 0));

	for (int i = -10; i < 10; ++i)
	{
		sprites[index] = new Sprite(0.02f, 100.0f, XMFLOAT2(0, 0), XMFLOAT2(10, 10), device);
		sprites[index]->setWorldPosition(XMFLOAT3(1 * i, levelPosition, 0));
		index++;
	}
	for (int i = -10; i < 10; ++i)
	{
		sprites[index] = new Sprite(100.0f, 0.02f, XMFLOAT2(0, 0), XMFLOAT2(10, 10), device);
		sprites[index]->setWorldPosition(XMFLOAT3(0, levelPosition, 1 * i));
		index++;
	}
	for (int i = -2; i <= 2; ++i)
	{
		sprites[index] = new Sprite(0.08f, 100.0f, XMFLOAT2(0, 0), XMFLOAT2(10, 10), device);
		sprites[index]->setWorldPosition(XMFLOAT3(1 * i * 5, levelPosition, 0));
		index++;
	}
	for (int i = -2; i <= 2; ++i)
	{
		sprites[index] = new Sprite(100.0f, 0.08f, XMFLOAT2(0, 0), XMFLOAT2(10, 10), device);
		sprites[index]->setWorldPosition(XMFLOAT3(0, levelPosition, 1 * i * 5));
		index++;
	}
}

Grid::~Grid()
{
	ReleaseCOM(mCubeMapSRV2);
	//for (int i = 0; i < 52; ++i)
	//{
	//	//sprites[i]->~Sprite();
	//}
}

void Grid::Draw(ID3D11DeviceContext* context, XMMATRIX& viewProj)
{
	for (int i = 0; i < 52; ++i)
	{
		sprites[i]->Draw(context, mCubeMapSRV2, viewProj);
	}
}