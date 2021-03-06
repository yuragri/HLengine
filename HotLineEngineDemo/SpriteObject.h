#pragma once
#include "BaseObject.h"

namespace HotLine
{
	class SpriteObject : public BaseObject
	{
	public:
		SpriteObject(ID3D11Device* device, ID3D11ShaderResourceView* texture, float width, float hfeight, 
			XMFLOAT2 topLeftCoord,  XMFLOAT2 bottomRightCoord,
			 Orientation orient = Orientation::top);
		~SpriteObject(){};

		void Draw(ID3D11DeviceContext* context, XMMATRIX& viewProj);

		void setCurrentTexture(ID3D11ShaderResourceView* texture) { if (texture!=NULL) currentTexture = texture; }
		void setDefaultTexture() { assert(defaultTexture != NULL); currentTexture = defaultTexture; };

		AxisAlignedBox * getBoundingBox() const { return boundingBox; }

		XMFLOAT3 getWorldPosition() const { return sprite->getWorldPosition(); }
		void setWorldPosition(XMFLOAT3 pos) { if (boundingBox!=NULL) boundingBox->Center = pos; sprite->setWorldPosition(pos); }

		void SetRotation(float angle) { sprite->setClockWiseRotation(angle); }
		float GetRotation() { return sprite->getClockWiseRotation(); }

		XMFLOAT2 GetScreenPosition(XMMATRIX& viewProj, D3D11_VIEWPORT screenViewport) { return sprite->GetScreenPosition(viewProj, screenViewport); }
	protected:
		AxisAlignedBox * boundingBox;
		ID3D11ShaderResourceView* currentTexture;
		ID3D11ShaderResourceView* defaultTexture;

		Sprite* sprite;
	};
}

