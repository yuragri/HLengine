#include "Sprite.h"
#include "Effects.h"
#include "InputLayouts.h"
using namespace HotLine;

#define ReleaseCOM(x) { if(x){ x->Release(); x = 0; } }

Sprite::Sprite(float width, float height, XMFLOAT2 topLeftCoord, XMFLOAT2 bottomRightCoord, ID3D11Device* device,
	Orientation orient)
	: sWidth(width), sHeight(height), sDevice(device), sVB(0), sIB(0), sPosition({ 0.0f, 0.0f, 0.0f }),
	sRotationAngle(0)
{
	setTextureCoordinatesAndCreateBuffers(topLeftCoord, bottomRightCoord);
	sTech = Effects::BasicFX->Light0TexAlphaClip;
	orientation = orient;
	setWorldMatrix(orient);
}

//TODO: finish the switch
void Sprite::setWorldMatrix(Orientation O)
{
	sWorld = XMMatrixIdentity();
	switch (O)
	{
	case Orientation::top:
	{
		break;
	}
	case Orientation::left:
	{
		XMVECTOR v = { 0, 0, 1 };
		sWorld *= XMMatrixRotationAxis(v, MathHelper::Pi / 2);
		break;
	}
	case Orientation::right:
	{
		XMVECTOR v = { 0, 0, 1 };
		sWorld *= XMMatrixRotationAxis(v, -MathHelper::Pi / 2);
		break;
	}
	case Orientation::bottom:
	{
		XMVECTOR v = { 0, 0, 1 };
		sWorld *= XMMatrixRotationAxis(v, MathHelper::Pi);
		break;
	}
	}
}

Sprite::~Sprite()
{
	//maybe we should use safe_release macros?
	ReleaseCOM(sVB);
	ReleaseCOM(sIB);
}

void Sprite::setTextureCoordinatesAndCreateBuffers(XMFLOAT2 topLeftCoord, XMFLOAT2 bottomRightCoord)
{
	ReleaseCOM(sVB);
	ReleaseCOM(sIB);

	sTopLeftCoord = topLeftCoord;
	sBottomRightCoord = bottomRightCoord;

	// Create vertex buffer
	Vertex vertices[] =
	{
		{ XMFLOAT3(-sWidth / 2, 0, -sHeight / 2), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(sTopLeftCoord.x, sBottomRightCoord.y) },
		{ XMFLOAT3(-sWidth / 2, 0, +sHeight / 2), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(sTopLeftCoord.x, sTopLeftCoord.y) },
		{ XMFLOAT3(+sWidth / 2, 0, +sHeight / 2), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(sBottomRightCoord.x, sTopLeftCoord.y) },
		{ XMFLOAT3(+sWidth / 2, 0, -sHeight / 2), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(sBottomRightCoord.x, sBottomRightCoord.y) }
	};

	D3D11_BUFFER_DESC vbd;
	vbd.Usage = D3D11_USAGE_IMMUTABLE;
	vbd.ByteWidth = sizeof(Vertex) * ARRAYSIZE(vertices);
	vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbd.CPUAccessFlags = 0;
	vbd.MiscFlags = 0;
	vbd.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA vinitData;
	vinitData.pSysMem = vertices;
	HR(sDevice->CreateBuffer(&vbd, &vinitData, &sVB));

	// Create the index buffer
	UINT indices[] = {
		0, 1, 2,
		0, 2, 3,
	};

	D3D11_BUFFER_DESC ibd;
	ibd.Usage = D3D11_USAGE_IMMUTABLE;
	ibd.ByteWidth = sizeof(UINT) * ARRAYSIZE(indices);
	ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	ibd.CPUAccessFlags = 0;
	ibd.MiscFlags = 0;
	ibd.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA iinitData;
	iinitData.pSysMem = indices;
	HR(sDevice->CreateBuffer(&ibd, &iinitData, &sIB));
}

void Sprite::Draw(ID3D11DeviceContext* context, ID3D11ShaderResourceView* texture, XMMATRIX& viewProj)
{
	context->IASetInputLayout(InputLayouts::VertexLayout);
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	//set perframe constants
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	context->IASetVertexBuffers(0, 1, &sVB, &stride, &offset);
	context->IASetIndexBuffer(sIB, DXGI_FORMAT_R32_UINT, 0);

	XMMATRIX worldInvTranspose = MathHelper::InverseTranspose(sWorld);
	XMMATRIX worldViewProj = sWorld*viewProj;

	Effects::BasicFX->SetWorld(sWorld);
	Effects::BasicFX->SetWorldInvTranspose(worldInvTranspose);
	Effects::BasicFX->SetWorldViewProj(worldViewProj);
	Effects::BasicFX->SetTexTransform(XMMatrixIdentity());
	Effects::BasicFX->SetDiffuseMap(texture);

	D3DX11_TECHNIQUE_DESC techDesc;
	sTech = Effects::BasicFX->Light0TexAlphaClip;
	sTech->GetDesc(&techDesc);

	for (UINT p = 0; p < techDesc.Passes; ++p)
	{
		sTech->GetPassByIndex(p)->Apply(0, context);

		// 6 indices for the square. (maybe it is not so good???)
		context->DrawIndexed(6, 0, 0);
	}
}

void Sprite::setWorldPosition(XMFLOAT3 pos)
{
	sPosition = pos;
	setWorldMatrix(orientation);
	sWorld *= XMMatrixTranslation(pos.x, pos.y, pos.z);
}

XMFLOAT3 Sprite::getWorldPosition()const
{
	return sPosition;
}

void Sprite::setClockWiseRotation(float r)
{
	sRotationAngle = r;
	XMVECTOR v = { 0, 1, 0 };
	sWorld *= XMMatrixRotationAxis(v, r);
}

float Sprite::getClockWiseRotation() const 
{
	return sRotationAngle;
}

//TODO: add orientations
void Sprite::setScaleRate(float r)
{
	sScaleRate = r;
	sWorld *= XMMatrixScaling(r, 1, r);
}

float Sprite::getScaleRate()const
{
	return sScaleRate;
}