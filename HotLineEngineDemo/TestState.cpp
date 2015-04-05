#pragma once
#include "TestState.h"
#include "BaseState.h"

#include "DrawAllProcess.h"
using namespace HotLine;

//--------------------------------------------------------------------------------
// Helper function for printing info in output window
void _TRACE(const wchar_t* szFormat, ...)
{
	wchar_t szBuff[1024] = { 0 };
	va_list arg;
	va_start(arg, szFormat);
	_vsnwprintf_s(&szBuff[0], _countof(szBuff), _TRUNCATE, szFormat, arg);
	va_end(arg);

	OutputDebugString(szBuff);
};
//--------------------------------------------------------------------------------

TestState::TestState(ID3D11Device* device, Camera* camera) : cam(camera), BaseState(device)
{
	walls = new std::vector<SpriteObject*>();
	floor = new std::vector<SpriteObject*>();
}

TestState::~TestState()
{
	delete(player);
	delete(walls);
	delete(floor);
}

void TestState::addObjetcsToScene()
{
	//adding a player---------------------------------------------------------------------------------------
	ID3D11ShaderResourceView* texture;
	D3DX11CreateShaderResourceViewFromFile(device, L"Textures/char.dds", 0, 0, &texture, 0);

	player = new AnimatedHuman(device, texture, 2.f, 2.f, XMFLOAT2(0, 0), XMFLOAT2(1.0f, 1.0f));
	player->GetBodySprite()->setWorldPosition({ 0, 1, 0 });
	player->GetLegsSprite()->setWorldPosition({ 0, 1, 0 });

	//adding walls------------------------------------------------------------------------------------------
	D3DX11CreateShaderResourceViewFromFile(device, L"sprites/wall-block.dds", 0, 0, &texture, 0);

	SpriteObject * obj = new SpriteObject(device, texture, 1.f, 10.f, XMFLOAT2(0, 0), XMFLOAT2(0.5f, 5.0f));
	obj->setWorldPosition({ 4, 1, 0 });
	walls->push_back(obj);

	obj = new SpriteObject(device, texture, 1.f, 10.f, XMFLOAT2(0, 0), XMFLOAT2(0.5f, 5.0f));
	obj->setWorldPosition({ -4, 1, 0 });
	walls->push_back(obj);

	//obj = new SpriteObject(device, texture, 10.f, 1.f, XMFLOAT2(0, 0), XMFLOAT2(5.0f, 0.5f));
	//obj->setWorldPosition({ 0, 1, -4 });
	//walls->push_back(obj);

	////for (int i = 0; i < 1000; ++i)
	////{
	//	obj = new SpriteObject(device, texture, 3.5f, 1.f, XMFLOAT2(0, 0), XMFLOAT2(1.75f, 0.5f));
	//	obj->setWorldPosition({ 2.5, 1, 4 });
	//	walls->push_back(obj);
	////}

	////adding floor-----------------------------------------------------------------------------------------
	//D3DX11CreateShaderResourceViewFromFile(device, L"sprites/floor.dds", 0, 0, &texture, 0);

	//obj = new SpriteObject(device, texture, 8.f, 8.f, XMFLOAT2(0, 0), XMFLOAT2(4.0f, 4.0f));
	//obj->setWorldPosition({ 0, 0, 0 });
	//floor->push_back(obj);
	//-----------------------------------------------------------------------------------------


	//creating the vector of objects which collide
	std::vector<SpriteObject*> * collide = new 	std::vector<SpriteObject*>();
	for (int i = 0; i < walls->size(); ++i)
	{
		collide->push_back(walls->at(i));
	}
	collide->push_back(player->GetBodySprite());

	//adding to move animation the collided objects
	MoveAnimation::setCollidableObjects(collide);
}

void TestState::addProcesses()
{
	//adding a process which draws everything---------------------------------------------------------------------------------
	std::vector<BaseObject*> * objects = new std::vector<BaseObject*>();
	for (int i = 0; i < floor->size(); ++i)
	{
		objects->push_back(floor->at(i));
	}
	for (int i = 0; i < walls->size(); ++i)
	{
		objects->push_back(walls->at(i));
	}
	objects->push_back(player->GetBodySprite());
	objects->push_back(player->GetLegsSprite());

	DrawAllProcess * proc = new DrawAllProcess(objects);

	//addAnimation(player->getWalkForwardTextureAnimation());

	//YOU HAVE TO CALL THIS FUNCTION TO ADD A PROCESS TO STATE
	addProcess(proc);
	//------------------------------------------------------------------------------------------------------------------------
}

void TestState::addAnimations(){}

//-------------------------------------------------------------------------------------------------------------
//resolve inputs-----------------------------------------------------------------------------------------------
void TestState::resolveKeyDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj)
{
	std::vector<BaseAnimation*> animationstoadd;

	switch (btnState)
	{
	case (0x57) ://W
	{
		animationstoadd = player->StartWalkForwardState();
		break;
	}
	case (0x41)://A
	{
		animationstoadd = player->StartWalkLeftState();
		break;
	}
	case (0x53) ://S
	{
		animationstoadd = player->StartWalkBackwardState();
		break;
	}
	case (0x44) ://D
	{
		animationstoadd = player->StartWalkRightState();
		break;
	}

	case (0x46) ://F
	{
		player->AddRotateAnimation(-1.5f);
		std::vector<BaseAnimation*> vec;
		vec.push_back(player->rotateAnimation);
		animationstoadd = vec;
		break;
	}
	case (0x47) ://G
	{
		player->AddRotateAnimation(1.5f);
		std::vector<BaseAnimation*> vec;
		vec.push_back(player->rotateAnimation);
		animationstoadd = vec;
		break;
	}
	case (0x48) :
	{
		//player->GetBodySprite()->SetRotation(-1.0f);
		break;
	}
	}

	for each (BaseAnimation * anim in animationstoadd)
	{
		addAnimation(anim);
	}
}

void TestState::resolveKeyUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj)
{
	std::vector<BaseAnimation*> animationstoremove;

	switch (btnState)
	{
	case (0x57) ://W
	{
		animationstoremove = player->StopWalkForwardState();
		break;
	}
	case (0x41) ://A
	{
		animationstoremove = player->StopWalkLeftState();
		break;
	}
	case (0x53) ://S
	{
		animationstoremove = player->StopWalkBackwardState();
		break;
	}
	case (0x44) ://D
	{
		animationstoremove = player->StopWalkRightState();
		break;
	}
	case (0x43) ://C
	{
		if (boundedStates->size() > 0)
		{
			resultingState = boundedStates->at(0);
		}
		break;
	}
	}

	for each (BaseAnimation * anim in animationstoremove)
	{
		removeAnimation(anim);
	}
}

void TestState::resolveMouseMove(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort)
{
	XMFLOAT2 screenPos = player->GetBodySprite()->GetScreenPosition(viewProj, viewPort);
	XMFLOAT2 vector = {
		x - screenPos.x,
		y - screenPos.y
	};

	float length = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
	vector.x /= length;
	vector.y /= length;

	if (length > 0)
	{
		float angle = acos(-vector.y);

		float coef = 1;
		if (vector.x < 0)  coef = -1;
		player->GetBodySprite()->SetRotation(angle * coef);
		player->GetLegsSprite()->SetRotation(angle * coef);

		_TRACE(L"%f\tScreenPos:%f %f\t vector:%f %f\t length:%f\tplayerRotation:%f\tmousePosition:%i %i\n",
			angle, screenPos.x, screenPos.y, vector.x, vector.y, length, player->GetBodySprite()->GetRotation(), x, y);
	}

}

void TestState::resolveLMouseUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort)
{

}
void TestState::resolveLMouseDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort)
{

}
void TestState::resolveRMouseUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort)
{

}
void TestState::resolveRMouseDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort)
{

}

void TestState::removeAllObjects()
{

}

void TestState::removeAllProcesses()
{

}
//-------------------------------------------------------------------------------------------------------------
//resolve inputs-----------------------------------------------------------------------------------------------


void TestState::pauseState()
{
	if (!isPaused)
	{
		isPaused = true;
		player->GetBodySprite()->visible = false;
		for (int i = 0; i < walls->size(); ++i)
		{
			walls->at(i)->visible = false;
		}

		for (int i = 0; i < floor->size(); ++i)
		{
			floor->at(i)->visible = false;
		}

		MoveAnimation::setCollidableObjects(new std::vector<SpriteObject*>());
	}
}
void TestState::unpauseState()
{
	if (isPaused)
	{
		isPaused = false;
		player->GetBodySprite()->visible = true;
		for (int i = 0; i < walls->size(); ++i)
		{
			walls->at(i)->visible = true;
		}

		for (int i = 0; i < floor->size(); ++i)
		{
			floor->at(i)->visible = true;
		}
		
		//creating the vector of objects which collide
		std::vector<SpriteObject*> * collide = new 	std::vector<SpriteObject*>();
		for (int i = 0; i < walls->size(); ++i)
		{
			collide->push_back(walls->at(i));
		}
		collide->push_back(player->GetBodySprite());
		//adding to move animation the collided objects
		MoveAnimation::setCollidableObjects(collide);
	}
}