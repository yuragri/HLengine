#include "InputLayouts.h"
#include "Effects.h"

const D3D11_INPUT_ELEMENT_DESC InputLayoutDesc::Vertex[3] =
{
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 }
};

ID3D11InputLayout* InputLayouts::VertexLayout = 0;

void InputLayouts::InitAll(ID3D11Device* device)
{
	D3DX11_PASS_DESC passDesc;

	Effects::BasicFX->Light1Tech->GetPassByIndex(0)->GetDesc(&passDesc);
	HR(device->CreateInputLayout(InputLayoutDesc::Vertex, 3, passDesc.pIAInputSignature,
		passDesc.IAInputSignatureSize, &VertexLayout));
}

void InputLayouts::DestroyAll()
{
	ReleaseCOM(VertexLayout);
}
