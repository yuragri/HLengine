#pragma once
#include "BaseState.h"

using namespace HotLine;


void BaseState::addProcess(HotLine::BaseProcess* proc)
{
	processes->push_back(proc);
}

void BaseState::addAnimation(HotLine::BaseAnimation* anim)
{
	bool contains = false;
	for (int i = 0; i < animations->size(); ++i)
	{
		if (animations->at(i) == anim)
		{
			contains = true;
		}
	}	
	if (!contains) animations->push_back(anim);
	//TRACE(L"SIZE:%i\n", animations->size());
}

void BaseState::removeProcess(BaseProcess* proc)
{

}
void BaseState::removeAnimation(BaseAnimation* anim)
{
	for (int i = 0; i < animations->size(); ++i)
	{
		if (animations->at(i) == anim)
		{
			animations->erase(animations->begin() + i);
			i--;
		}
	}
}

void BaseState::addBoundedState(BaseState* ba)
{
	boundedStates->push_back(ba);
}
void BaseState::removeBoundedState(BaseState* ba)
{
	for (int i = 0; i < boundedStates->size(); ++i)
	{
		if (boundedStates->at(i) == ba)
		{
			boundedStates->erase(boundedStates->begin() + i);
			i--;
		}
	}
}

BaseState* BaseState::render(ID3D11DeviceContext* context, XMMATRIX& viewProj)
{
	//resolve animations

	//camera and effects

	//draw all objects


	//for (int i = 0; i < animations->size(); ++i)
	//{
	//	bool hasNextFrame = animations->at(i)->nextFrame();
	//	if (!hasNextFrame)
	//	{
	//		animations->erase(animations->begin() + i);
	//		i--;
	//	}
	//}

	for (int i = 0; i < processes->size(); ++i)
	{
		processes->at(i)->process(context, viewProj);
	}

	//for (int i = 0; i < objects->size(); ++i)
	//{
	//	if (objects->at(i)->visible)
	//	{
	//		objects->at(i)->Draw(context, viewProj);
	//	}
	//}

	BaseState* res = resultingState;
	resultingState = NULL;
	return res;
}