#include "Player.h"

using namespace HotLine;

Player::Player(ID3D11Device* device, ID3D11ShaderResourceView* texture, float width, float height,
	XMFLOAT2 topLeftCoord, XMFLOAT2 bottomRightCoord,
	Orientation orient) :
	SpriteObject(device, texture, width, height, topLeftCoord, bottomRightCoord, orient)
{
	//adding walk texture animation---------------------------------------------------------------------
	//extract textures from the texture folder
	ID3D11ShaderResourceView* texture1;
	D3DX11CreateShaderResourceViewFromFile(device, L"Textures/runPose1.dds", 0, 0, &texture1, 0);

	ID3D11ShaderResourceView* texture2;
	D3DX11CreateShaderResourceViewFromFile(device, L"Textures/runPose2.dds", 0, 0, &texture2, 0);

	ID3D11ShaderResourceView* texture3;
	D3DX11CreateShaderResourceViewFromFile(device, L"Textures/floor.dds", 0, 0, &texture3, 0);

	ID3D11ShaderResourceView* texture4;
	D3DX11CreateShaderResourceViewFromFile(device, L"Textures/MENU.dds", 0, 0, &texture4, 0);

	//time for frames
	double timeOfMoveFrame = 0.001;
	double timeOfTextureFrame = 0.1;

	//creating vector of textures for frame
	std::vector<ID3D11ShaderResourceView*> * tx = new std::vector<ID3D11ShaderResourceView*>();
	tx->push_back(texture1);
	tx->push_back(texture2);
	//tx->push_back(texture3);
	//tx->push_back(texture4);

	//creating vector of time for each frame
	std::vector<double> * t = new std::vector<double>();
	for (int i = 0; i < tx->size(); ++i)
	{
		t->push_back(timeOfTextureFrame);
	}

	//creating animation for the object
	walkForwardTextureAnimation = new TextureAnimation(t, tx, true, this);
	walkBackwardTextureAnimation = new TextureAnimation(t, tx, true, this);
	walkLeftTextureAnimation = new TextureAnimation(t, tx, true, this);
	walkRightTextureAnimation = new TextureAnimation(t, tx, true, this);

	//creating move animation

	std::vector<double> * mvt = new std::vector<double>();
	mvt->push_back(timeOfMoveFrame);

	std::vector<XMFLOAT3> * mvForward = new std::vector<XMFLOAT3>();
	mvForward->push_back(forward);

	std::vector<XMFLOAT3> * mvBackward = new std::vector<XMFLOAT3>();
	mvBackward->push_back(backward);

	std::vector<XMFLOAT3> * mvRight = new std::vector<XMFLOAT3>();
	mvRight->push_back(right);

	std::vector<XMFLOAT3> * mvLeft = new std::vector<XMFLOAT3>();
	mvLeft->push_back(left);

	walkForwardMoveAnimation = new MoveAnimation(mvt, mvForward, true, this);
	walkBackwardMoveAnimation = new MoveAnimation(mvt, mvBackward, true, this);
	walkLeftMoveAnimation = new MoveAnimation(mvt, mvLeft, true, this);
	walkRightMoveAnimation = new MoveAnimation(mvt, mvRight, true, this);
}

Player::~Player()
{
	if (walkForwardTextureAnimation != NULL) delete(walkForwardTextureAnimation); 
	if (walkBackwardTextureAnimation != NULL) delete(walkBackwardTextureAnimation);
	if (walkLeftTextureAnimation != NULL) delete(walkLeftTextureAnimation);
	if (walkRightTextureAnimation != NULL) delete(walkForwardTextureAnimation);

	if (walkForwardMoveAnimation != NULL) delete(walkForwardMoveAnimation);
	if (walkBackwardMoveAnimation != NULL) delete(walkBackwardMoveAnimation);
	if (walkLeftMoveAnimation != NULL) delete(walkLeftMoveAnimation);
	if (walkRightMoveAnimation != NULL) delete(walkForwardMoveAnimation);
}