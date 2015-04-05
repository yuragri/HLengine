#include "SpriteObject.h"

using namespace HotLine;

SpriteObject::SpriteObject(ID3D11Device* device, ID3D11ShaderResourceView* text, float width, float height, XMFLOAT2 topLeftCoord, XMFLOAT2 bottomRightCoord,
	 Orientation orient) : BaseObject(), defaultTexture(text), currentTexture(text)
{
	sprite = new Sprite(width, height, topLeftCoord, bottomRightCoord, device, orient);

	switch (orient)
	{
	case HotLine::top:
	{
		boundingBox = new AxisAlignedBox();
		boundingBox->Extents = XMFLOAT3(width / 2, 1, height / 2);
		break;
	}
	case HotLine::bottom:
	{
		boundingBox = new AxisAlignedBox();
		boundingBox->Extents = XMFLOAT3(width / 2, 1, height / 2);
		break;
	}
	case HotLine::front:
		boundingBox = new AxisAlignedBox();
		boundingBox->Extents = XMFLOAT3(width / 2, 1, height / 2);
		break;
	case HotLine::back:
		boundingBox = new AxisAlignedBox();
		boundingBox->Extents = XMFLOAT3(width / 2, 1, height / 2);
		break;
	case HotLine::right:
		boundingBox = new AxisAlignedBox();
		boundingBox->Extents = XMFLOAT3(width / 2, 1, height / 2);
		break;
	case HotLine::left:
		boundingBox = new AxisAlignedBox();
		boundingBox->Extents = XMFLOAT3(width / 2, 1, height / 2);
		break;
	default:
		break;
	};
}

void SpriteObject::Draw(ID3D11DeviceContext* context, XMMATRIX& viewProj)
{
	sprite->Draw(context, currentTexture, viewProj);
}