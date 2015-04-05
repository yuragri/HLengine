#include "AnimatedHuman.h"

using namespace HotLine;

AnimatedHuman::AnimatedHuman(ID3D11Device* device, ID3D11ShaderResourceView* texture, float width, float height,
	XMFLOAT2 topLeftCoord, XMFLOAT2 bottomRightCoord,
	Orientation orient)
{
	ID3D11ShaderResourceView* texture_body;
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/char.dds", 0, 0, &texture_body, 0);

	ID3D11ShaderResourceView* texture_legs;
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/char.dds", 0, 0, &texture_legs, 0);

	_sprite_body = new SpriteObject(device, texture_body, width, height, topLeftCoord, bottomRightCoord, orient);
	_sprite_legs = new SpriteObject(device, NULL, width, height-0.1, topLeftCoord, bottomRightCoord, orient);

	int textures_per_second = 20;

	//adding walk texture animation---------------------------------------------------------------------
	//extract textures from the texture folder
	ID3D11ShaderResourceView* texture11;
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/body-21.dds", 0, 0, &texture11, 0);

	ID3D11ShaderResourceView* texture12;
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/body-22.dds", 0, 0, &texture12, 0);

	ID3D11ShaderResourceView* texture21;
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/body-11.dds", 0, 0, &texture21, 0);

	ID3D11ShaderResourceView* texture22;
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/body-12.dds", 0, 0, &texture22, 0);

	ID3D11ShaderResourceView* chartxt;
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/char.dds", 0, 0, &chartxt, 0);

	std::vector<ID3D11ShaderResourceView*> * tx_left = new std::vector<ID3D11ShaderResourceView*>();
	tx_left->push_back(texture11);
	tx_left->push_back(texture21);
	tx_left->push_back(texture11);
	tx_left->push_back(chartxt);

	std::vector<ID3D11ShaderResourceView*> * tx_right = new std::vector<ID3D11ShaderResourceView*>();
	tx_right->push_back(texture12);
	tx_right->push_back(texture22);
	tx_right->push_back(texture12);
	tx_right->push_back(chartxt);
	//------------------------
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/legs-21.dds", 0, 0, &texture11, 0);
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/legs-22.dds", 0, 0, &texture12, 0);
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/legs-11.dds", 0, 0, &texture21, 0);
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/legs-12.dds", 0, 0, &texture22, 0);

	std::vector<ID3D11ShaderResourceView*> * tx_left_leg = new std::vector<ID3D11ShaderResourceView*>();
	tx_left_leg->push_back(texture11);
	tx_left_leg->push_back(texture21);
	tx_left_leg->push_back(texture11);
	tx_left_leg->push_back(chartxt);

	std::vector<ID3D11ShaderResourceView*> * tx_right_leg = new std::vector<ID3D11ShaderResourceView*>();
	tx_right_leg->push_back(texture12);
	tx_right_leg->push_back(texture22);
	tx_right_leg->push_back(texture12);
	tx_right_leg->push_back(chartxt);

	walkLeftStepBodyTexture = new TextureAnimationStateInfo(_sprite_body, tx_left, textures_per_second, false);
	walkRightStepBodyTexture = new TextureAnimationStateInfo(_sprite_body, tx_right, textures_per_second, false);

	walkLeftStepLegsTexture = new TextureAnimationStateInfo(_sprite_legs, tx_left_leg, textures_per_second, false);
	walkRightStepLegsTexture = new TextureAnimationStateInfo(_sprite_legs, tx_right_leg, textures_per_second, false);

	float speed_of_walking = 13.0f;
	walkForwardMoveAnimation = new MoveAnimation(_sprite_body, forward, speed_of_walking);
	walkBackwardMoveAnimation = new MoveAnimation(_sprite_body, backward, speed_of_walking);
	walkLeftMoveAnimation = new MoveAnimation(_sprite_body, left, speed_of_walking);
	walkRightMoveAnimation = new MoveAnimation(_sprite_body, right, speed_of_walking);

	rotateAnimation = NULL;

	walkTextureBodyAnimation = new TextureAnimation();
	__hook(&TextureAnimation::OnAnimationFinished, walkTextureBodyAnimation, &AnimatedHuman::ChangeLeg);
	walkTextureBodyAnimation->SetTextureAnimationStateInfo(walkLeftStepBodyTexture);

	walkTextureLegsAnimation = new TextureAnimation();
	walkTextureLegsAnimation->SetTextureAnimationStateInfo(walkLeftStepLegsTexture);

	_walks_forward = false;
	_walks_backward = false;
	_walks_left = false;
	_walks_right = false;
}

void AnimatedHuman::AddRotateAnimation(float angle)
{
	//speed_of_rotation == number of steps per second
	float speed_of_rotation = 4.0f;
	float r = _sprite_body->GetRotation();
	float step = (angle<0?-1.0f:1.0f);
	rotateAnimation = new RotateAnimation(_sprite_body, step, speed_of_rotation, true, angle);
}

void AnimatedHuman::ChangeLeg()
{
	if ((state == WALK_FORWARD) || (state == WALK_BACKWARD) || (state == WALK_LEFT) || (state == WALK_RIGHT))
	{
		if (walkTextureBodyAnimation->HasSameTexturesWith(walkLeftStepBodyTexture))
		{
			walkTextureBodyAnimation->SetTextureAnimationStateInfo(walkRightStepBodyTexture);
			walkTextureLegsAnimation->SetTextureAnimationStateInfo(walkRightStepLegsTexture);
		}
		else
		{
			walkTextureBodyAnimation->SetTextureAnimationStateInfo(walkLeftStepBodyTexture);
			walkTextureLegsAnimation->SetTextureAnimationStateInfo(walkLeftStepLegsTexture);
		}
		GetWalkTextureBodyAnimation()->Restart();
		GetWalkTextureLegsAnimation()->Restart();
	}
}

void AnimatedHuman::SetIdleState() 
{ 
	//check if human walks
	int counter = 0;
	if (_walks_forward) counter++;
	if (_walks_backward) counter++;
	if (_walks_left) counter++;
	if (_walks_right) counter++;

	if (counter == 0)
	{
		if (state != IDLE)
		{
			state = IDLE;
			if (walkTextureBodyAnimation->GetIndex() == 0) {
				walkTextureBodyAnimation->JumpToFrame(2);
			}
		}
	}
}

void AnimatedHuman::SetWalkState(){}

std::vector<BaseAnimation*> AnimatedHuman::StartWalkForwardState()
{
	state = WALK_FORWARD;
	_walks_forward = true;

	std::vector<BaseAnimation*> animations;
	animations.push_back(GetWalkTextureBodyAnimation());
	//animations.push_back(GetWalkTextureLegsAnimation());

	animations.push_back(getWalkForwardMoveAnimation());
	

	return animations;
}
std::vector<BaseAnimation*> AnimatedHuman::StartWalkBackwardState()
{
	std::vector<BaseAnimation*> animations;
	animations.push_back(GetWalkTextureBodyAnimation());
	//animations.push_back(GetWalkTextureLegsAnimation());
	animations.push_back(getWalkBackwardMoveAnimation());

	state = WALK_BACKWARD;
	_walks_backward = true;

	return animations;
}
std::vector<BaseAnimation*> AnimatedHuman::StartWalkLeftState()
{
	std::vector<BaseAnimation*> animations;
	animations.push_back(GetWalkTextureBodyAnimation());
	//animations.push_back(GetWalkTextureLegsAnimation());
	animations.push_back(getWalkLeftMoveAnimation());

	state = WALK_LEFT;
	_walks_left = true;

	return animations;
}
std::vector<BaseAnimation*> AnimatedHuman::StartWalkRightState()
{
	std::vector<BaseAnimation*> animations;
	animations.push_back(GetWalkTextureBodyAnimation());
	//animations.push_back(GetWalkTextureLegsAnimation());
	animations.push_back(getWalkRightMoveAnimation());

	state = WALK_RIGHT;
	_walks_right = true;

	return animations;
}

std::vector<BaseAnimation*> AnimatedHuman::StopWalkForwardState()
{
	std::vector<BaseAnimation*> animations;
	animations.push_back(getWalkForwardMoveAnimation());
	if (rotateAnimation != NULL)
	{
		animations.push_back(rotateAnimation);
	}

	_walks_forward = false;
	SetIdleState();

	return animations;
}
std::vector<BaseAnimation*> AnimatedHuman::StopWalkBackwardState()
{
	std::vector<BaseAnimation*> animations;
	animations.push_back(getWalkBackwardMoveAnimation());

	_walks_backward = false;
	SetIdleState();

	return animations;
}
std::vector<BaseAnimation*> AnimatedHuman::StopWalkLeftState()
{
	std::vector<BaseAnimation*> animations;
	animations.push_back(getWalkLeftMoveAnimation());

	_walks_left = false;
	SetIdleState();

	return animations;
}
std::vector<BaseAnimation*> AnimatedHuman::StopWalkRightState()
{
	std::vector<BaseAnimation*> animations;
	animations.push_back(getWalkRightMoveAnimation());

	_walks_right = false;
	SetIdleState();

	return animations;
}

AnimatedHuman::~AnimatedHuman()
{
	if (walkForwardMoveAnimation != NULL) delete(walkForwardMoveAnimation);
	if (walkBackwardMoveAnimation != NULL) delete(walkBackwardMoveAnimation);
	if (walkLeftMoveAnimation != NULL) delete(walkLeftMoveAnimation);
	if (walkRightMoveAnimation != NULL) delete(walkForwardMoveAnimation);
}