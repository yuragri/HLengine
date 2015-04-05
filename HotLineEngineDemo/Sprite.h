#pragma once
#include "d3dUtil.h"
#include "xnacollision.h"
#include <stdio.h>
#include "OrientationFactories.h"

using namespace XNA;

namespace HotLine
{
	static D3D11_VIEWPORT * screen_view_port;

	enum Orientation
	{
		top, bottom, front, back, right, left
	};
	//TODO: refactoring!!!
	class Sprite
	{
	public:
		//top left coord and bottom right coord are texture coordinates
		Sprite(float width, float height, XMFLOAT2 topLeftCoord, XMFLOAT2 bottomRightCoord,
			ID3D11Device* device, Orientation orient = top);
		~Sprite();

		void setWorldPosition(XMFLOAT3 pos);

		void Draw(ID3D11DeviceContext* context, ID3D11ShaderResourceView* texture, XMMATRIX& viewProj);

		//top left and bottom right texture coordinates are set in one method because this causes recreation of vertex buffer
		void setTextureCoordinatesAndCreateBuffers(XMFLOAT2 topLeftCoord, XMFLOAT2 bottomRightCoord);
		XMFLOAT2 getTopLeftTextureCoordinate()const;
		XMFLOAT2 getBottomRightTextureCoordinate()const;
	
		XMFLOAT3 getWorldPosition()const;

		void setClockWiseRotation(float r);
		float getClockWiseRotation()const;

		//void setScaleRate(float r);
		//float getScaleRate()const;

		XMFLOAT2 GetScreenPosition(XMMATRIX & viewProj, D3D11_VIEWPORT screenViewport);

	private:
		float sWidth;
		float sHeight;
		float sLevel;
		//the coordinate of the texture that shoud be drawn in the topLeft of the rectangle
		XMFLOAT2 sTopLeftTextureCoordinate;
		//the coordinate of the texture that shoud be drawn in the bottomRight of the rectangle
		XMFLOAT2 sBottomRightTextureCoordinate;

		//special matrix that shows position
		XMMATRIX sWorld;

		//world position of the sprite`s center
		XMFLOAT3 sPosition;
		//the angle the sprite was clockwise rotated relatively to the initial state
		float sRotationAngle;
		//the scale rate relatively to sprite`s initial size
		float sScaleRate;

		//coordinates of the texture
		XMFLOAT2 sTopLeftCoord;
		XMFLOAT2 sBottomRightCoord;

		//position of sprite in spcae (actually it determaines weather it is a part of the floor or a part of the wall etc.)
		Orientation orientation;
		void setWorldMatrix(Orientation O);

		//some rendering variables
		ID3D11Buffer* sVB;
		ID3D11Buffer* sIB;
		ID3DX11EffectTechnique* sTech;
		ID3D11Device* sDevice;

		XMVECTOR _vector_up;
	};
}