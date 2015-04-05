#pragma once
#include "MoveAnimation.h"

using namespace HotLine;

//-------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------THE CLASS COMMITS ALL THE MOVINGS OF SPRITES---------------------------------
//-------------------------------------------------------------------------------------------------------------------------
std::vector<SpriteObject*> * MoveAnimation::collObjects = new std::vector<SpriteObject*>();
//-------------------------------------------------------------------------------------------------------------------------
MoveAnimation::MoveAnimation(SpriteObject* object, XMFLOAT3 step, float speed, float distance)
	: _obj(object), _step(step), _speed(speed), _target_distance(distance), _reached_distance(0) {}
//-------------------------------------------------------------------------------------------------------------------------
MoveAnimation::~MoveAnimation(){}
//-------------------------------------------------------------------------------------------------------------------------
bool MoveAnimation::NextFrame(double deltaTime)
{
	XMFLOAT3 oldpos = _obj->getWorldPosition();
	//if the step or fps is huge - walking through the walls is possible!!!
	XMFLOAT3 newpos = MakeMove(deltaTime, _obj->getWorldPosition());

	if (CollisionCheck(newpos))
		_obj->setWorldPosition(oldpos);
	else _obj->setWorldPosition(newpos);

	return true;
}
//-------------------------------------------------------------------------------------------------------------------------
bool MoveAnimation::CollisionCheck(XMFLOAT3 newposition)
{
	AxisAlignedBox * b1 = _obj->getBoundingBox();
	AxisAlignedBox testbox;
	testbox.Extents = _obj->getBoundingBox()->Extents;
	testbox.Center = newposition;

	if (b1 != NULL)
	{
		for (int i = 0; i < collObjects->size(); ++i)
		{
			AxisAlignedBox * b2 = collObjects->at(i)->getBoundingBox();
			if ((b2 != NULL) && (b1 != b2))//TODO:this is a place were we may have to compare the ID but not the pointers
			{
				if (IntersectAxisAlignedBoxAxisAlignedBox(&testbox, b2))
				{
					return true;
				}
			}
		}
	}
	return false;
}
//-------------------------------------------------------------------------------------------------------------------------
void MoveAnimation::setCollidableObjects(std::vector<SpriteObject*> * collObjs)
{
	if (collObjs != NULL)
	{
		delete(collObjects);
		collObjects = collObjs;
	}
}
//-------------------------------------------------------------------------------------------------------------------------
XMFLOAT3 MoveAnimation::MakeMove(double deltaTime, XMFLOAT3 oldposition)
{
	float distintent = CountIntendedMoveDistance(deltaTime);

	float coef = 1;
	if ((_target_distance - _reached_distance < distintent) && (_target_distance>0))
	{
		coef = (_target_distance - _reached_distance) / distintent;
	};

	oldposition.x += _speed * deltaTime * _step.x * coef;
	oldposition.y += _speed * deltaTime * _step.y * coef;
	oldposition.z += _speed * deltaTime * _step.z * coef;

	_reached_distance += distintent*coef;

	return oldposition;
}
//-------------------------------------------------------------------------------------------------------------------------
float MoveAnimation::CountIntendedMoveDistance(double deltaTime)
{
	return sqrt(pow(_speed * deltaTime * _step.x, 2) 
		+ pow(_speed * deltaTime * _step.y, 2) + pow(_speed * deltaTime * _step.z, 2));
}
//-------------------------------------------------------------------------------------------------------------------------
bool MoveAnimation::ReachedEnd()
{
	return (_reached_distance >= _target_distance);
}
//-------------------------------------------------------------------------------------------------------------------------
void MoveAnimation::Restart()
{
	_reached_distance = 0;
}
//-------------------------------------------------------------------------------------------------------------------------