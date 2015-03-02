#pragma once
#include "TestState.h"
#include "BaseState.h"

#include "DrawAllProcess.h"
using namespace HotLine;

TestState::TestState(ID3D11Device* device) : BaseState(device)
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
	D3DX11CreateShaderResourceViewFromFile(device, L"Textures/runPose1.dds", 0, 0, &texture, 0);

	player = new Player(device, texture, 4.f, 4.f, XMFLOAT2(0, 0), XMFLOAT2(1.0f, 1.0f));
	player->setWorldPosition({ 0, 1, 0 });

	//adding walls------------------------------------------------------------------------------------------
	D3DX11CreateShaderResourceViewFromFile(device, L"Textures/bricks.dds", 0, 0, &texture, 0);

	SpriteObject * obj = new SpriteObject(device, texture, 1.f, 10.f, XMFLOAT2(0, 0), XMFLOAT2(1.0f, 10.0f));
	obj->setWorldPosition({ 4, 1, 0 });
	walls->push_back(obj);

	obj = new SpriteObject(device, texture, 1.f, 10.f, XMFLOAT2(0, 0), XMFLOAT2(1.0f, 10.0f));
	obj->setWorldPosition({ -4, 1, 0 });
	walls->push_back(obj);

	obj = new SpriteObject(device, texture, 10.f, 1.f, XMFLOAT2(0, 0), XMFLOAT2(10.0f, 1.0f));
	obj->setWorldPosition({ 0, 1, -4 });
	walls->push_back(obj);

	//for (int i = 0; i < 1000; ++i)
	//{
		obj = new SpriteObject(device, texture, 3.5f, 1.f, XMFLOAT2(0, 0), XMFLOAT2(4.0f, 1.0f));
		obj->setWorldPosition({ 2.5, 1, 4 });
		walls->push_back(obj);
	//}

	//adding floor-----------------------------------------------------------------------------------------
	D3DX11CreateShaderResourceViewFromFile(device, L"Textures/floor.dds", 0, 0, &texture, 0);

	obj = new SpriteObject(device, texture, 8.f, 8.f, XMFLOAT2(0, 0), XMFLOAT2(1.0f, 1.0f));
	obj->setWorldPosition({ 0, 0, 0 });
	floor->push_back(obj);
	//-----------------------------------------------------------------------------------------


	//creating the vector of objects which collide
	std::vector<SpriteObject*> * collide = new 	std::vector<SpriteObject*>();
	for (int i = 0; i < walls->size(); ++i)
	{
		collide->push_back(walls->at(i));
	}
	collide->push_back(player);
	//adding to move animation the collided objects
	MoveAnimation::setCollidedObjects(collide);
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
	objects->push_back(player);

	DrawAllProcess * proc = new DrawAllProcess(objects);

	//YOU HAVE TO CALL THIS FUNCTION TO ADD A PROCESS TO STATE
	addProcess(proc);
	//------------------------------------------------------------------------------------------------------------------------
}

void TestState::addAnimations()
{}

//-------------------------------------------------------------------------------------------------------------
//resolve inputs-----------------------------------------------------------------------------------------------
void TestState::resolveKeyDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj)
{
	switch (btnState)
	{
	case (0x57) ://W
	{
		addAnimation(player->getWalkForwardMoveAnimation());
		addAnimation(player->getWalkForwardTextureAnimation());
		break;
	}
	case (0x41)://A
	{
		addAnimation(player->getWalkLeftMoveAnimation());
		addAnimation(player->getWalkLeftTextureAnimation());
		break;
	}
	case (0x53) ://S
	{
		addAnimation(player->getWalkBackwardMoveAnimation());
		addAnimation(player->getWalkBackwardTextureAnimation());
		break;
	}
	case (0x44) ://D
	{
		addAnimation(player->getWalkRightMoveAnimation());
		addAnimation(player->getWalkRightTextureAnimation());
		break;
	}
	}
}

void TestState::resolveKeyUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj)
{
	
	switch (btnState)
	{
	case (0x57) ://W
	{
		removeAnimation(player->getWalkForwardMoveAnimation());
		removeAnimation(player->getWalkForwardTextureAnimation());
		break;
	}
	case (0x41) ://A
	{
		removeAnimation(player->getWalkLeftMoveAnimation());
		removeAnimation(player->getWalkLeftTextureAnimation());
		break;
	}
	case (0x53) ://S
	{
		removeAnimation(player->getWalkBackwardMoveAnimation());
		removeAnimation(player->getWalkBackwardTextureAnimation());
		break;
	}
	case (0x44) ://D
	{
		removeAnimation(player->getWalkRightMoveAnimation());
		removeAnimation(player->getWalkRightTextureAnimation());
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
}

void TestState::resolveMouseMove(WPARAM btnState, int x, int y, XMMATRIX& viewProj)
{

}

void TestState::resolveLMouseUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj)
{

}
void TestState::resolveLMouseDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj)
{

}
void TestState::resolveRMouseUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj)
{

}
void TestState::resolveRMouseDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj)
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
		player->visible = false;
		for (int i = 0; i < walls->size(); ++i)
		{
			walls->at(i)->visible = false;
		}

		for (int i = 0; i < floor->size(); ++i)
		{
			floor->at(i)->visible = false;
		}

		MoveAnimation::setCollidedObjects(new std::vector<SpriteObject*>());
	}
}
void TestState::unpauseState()
{
	if (isPaused)
	{
		isPaused = false;
		player->visible = true;
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
		collide->push_back(player);
		//adding to move animation the collided objects
		MoveAnimation::setCollidedObjects(collide);
	}
}