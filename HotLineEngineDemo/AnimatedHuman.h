#include "SpriteObject.h"
#include "TextureAnimation.h"
#include "MoveAnimation.h"
#include "RotateAnimation.h"

namespace HotLine
{
	enum State
	{
		IDLE,
		WALK_FORWARD,
		WALK_BACKWARD,
		WALK_LEFT,
		WALK_RIGHT
	};

	class AnimatedHuman
	{
	public:
		AnimatedHuman(ID3D11Device* device, ID3D11ShaderResourceView* texture, float width, float height,
			XMFLOAT2 topLeftCoord, XMFLOAT2 bottomRightCoord,
			Orientation orient = Orientation::top);
		~AnimatedHuman();

		MoveAnimation * getWalkForwardMoveAnimation() { return walkForwardMoveAnimation; }
		MoveAnimation * getWalkBackwardMoveAnimation() { return walkBackwardMoveAnimation; }
		MoveAnimation * getWalkLeftMoveAnimation() { return walkLeftMoveAnimation; }
		MoveAnimation * getWalkRightMoveAnimation() { return walkRightMoveAnimation; }

		TextureAnimation * GetWalkTextureBodyAnimation() { return walkTextureBodyAnimation; }
		TextureAnimation * GetWalkTextureLegsAnimation() { return walkTextureLegsAnimation; }

		void SetIdleState();
		void SetWalkState();

		std::vector<BaseAnimation*> StartWalkForwardState();
		std::vector<BaseAnimation*> StartWalkBackwardState();
		std::vector<BaseAnimation*> StartWalkLeftState();
		std::vector<BaseAnimation*> StartWalkRightState();

		std::vector<BaseAnimation*> StopWalkForwardState();
		std::vector<BaseAnimation*> StopWalkBackwardState();
		std::vector<BaseAnimation*> StopWalkLeftState();
		std::vector<BaseAnimation*> StopWalkRightState();

		SpriteObject * GetBodySprite() { return _sprite_body; }
		SpriteObject * GetLegsSprite() { return _sprite_legs; }

		std::vector<SpriteObject*> GetAllSprites()
		{
			std::vector<SpriteObject*> sprts;
			sprts.push_back(_sprite_body);
			sprts.push_back(_sprite_legs);
			return sprts;
		}

		RotateAnimation * rotateAnimation;

		void AddRotateAnimation(float angle);

	private:
		TextureAnimation * walkTextureBodyAnimation;
		TextureAnimation * walkTextureLegsAnimation;

		bool _walks_forward;
		bool _walks_backward;
		bool _walks_left;
		bool _walks_right;

		TextureAnimationStateInfo * walkLeftStepBodyTexture;
		TextureAnimationStateInfo * walkRightStepBodyTexture;

		TextureAnimationStateInfo * walkLeftStepLegsTexture;
		TextureAnimationStateInfo * walkRightStepLegsTexture;

		MoveAnimation * walkForwardMoveAnimation;
		MoveAnimation * walkBackwardMoveAnimation;
		MoveAnimation * walkLeftMoveAnimation;
		MoveAnimation * walkRightMoveAnimation;

		XMFLOAT3 forward = XMFLOAT3(0,0,1.0f);
		XMFLOAT3 backward = XMFLOAT3(0, 0, -1.0f);
		XMFLOAT3 right = XMFLOAT3(1.0f, 0, 0);
		XMFLOAT3 left = XMFLOAT3(-1.0f, 0, 0);

		State state;

		SpriteObject * _sprite_body;
		SpriteObject * _sprite_legs;

		void ChangeLeg();
	};
}