#include "SpriteObject.h"
#include "TextureAnimation.h"
#include "MoveAnimation.h"

namespace HotLine
{
	class Player : public SpriteObject
	{
	public:
		Player(ID3D11Device* device, ID3D11ShaderResourceView* texture, float width, float height,
			XMFLOAT2 topLeftCoord, XMFLOAT2 bottomRightCoord,
			Orientation orient = Orientation::top);
		~Player();

		//animations getters
		TextureAnimation * getWalkForwardTextureAnimation() { return walkForwardTextureAnimation; }
		TextureAnimation * getWalkBackwardTextureAnimation() { return walkBackwardTextureAnimation; }
		TextureAnimation * getWalkLeftTextureAnimation() { return walkLeftTextureAnimation; }
		TextureAnimation * getWalkRightTextureAnimation() { return walkRightTextureAnimation; }

		MoveAnimation * getWalkForwardMoveAnimation() { return walkForwardMoveAnimation; }
		MoveAnimation * getWalkBackwardMoveAnimation() { return walkBackwardMoveAnimation; }
		MoveAnimation * getWalkLeftMoveAnimation() { return walkLeftMoveAnimation; }
		MoveAnimation * getWalkRightMoveAnimation() { return walkRightMoveAnimation; }


	private:
		TextureAnimation * walkForwardTextureAnimation;
		TextureAnimation * walkBackwardTextureAnimation;
		TextureAnimation * walkLeftTextureAnimation;
		TextureAnimation * walkRightTextureAnimation;

		MoveAnimation * walkForwardMoveAnimation;
		MoveAnimation * walkBackwardMoveAnimation;
		MoveAnimation * walkLeftMoveAnimation;
		MoveAnimation * walkRightMoveAnimation;

		XMFLOAT3 forward = XMFLOAT3(0,0,0.01);
		XMFLOAT3 backward = XMFLOAT3(0, 0, -0.01);
		XMFLOAT3 right = XMFLOAT3(0.01, 0, 0);
		XMFLOAT3 left = XMFLOAT3(-0.01, 0, 0);
	};
}