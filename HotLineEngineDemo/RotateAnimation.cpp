#pragma once
#include "RotateAnimation.h"

#define _USE_MATH_DEFINES
#include <math.h>

using namespace HotLine;

//-------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------THE CLASS COMMITS ALL THE MOVINGS OF SPRITES---------------------------------
//-------------------------------------------------------------------------------------------------------------------------
std::vector<SpriteObject*> * RotateAnimation::collObjects = new std::vector<SpriteObject*>();
//-------------------------------------------------------------------------------------------------------------------------
RotateAnimation::RotateAnimation(SpriteObject* object, float step, float speed, bool has_target_angle, float angle)
	: _obj(object), _step(step), _speed(speed), _target_angle(angle), _has_target_angle(has_target_angle), _reached_angle(0) {}
//-------------------------------------------------------------------------------------------------------------------------
RotateAnimation::~RotateAnimation(){}
//-------------------------------------------------------------------------------------------------------------------------
bool RotateAnimation::NextFrame(double deltaTime)
{
	assert(_reached_angle<M_PI * 2);
	assert(_reached_angle>-M_PI * 2);
	float oldangle = _obj->GetRotation();
	float newangle = MakeMove(deltaTime, _obj->GetRotation());

	//float newangle = oldangle + 0.01;

/*	if (CollisionCheck(newangle))
		_obj->SetRotation(oldangle);
		else*/ _obj->SetRotation(newangle);

	return true;
}
//-------------------------------------------------------------------------------------------------------------------------
bool RotateAnimation::CollisionCheck(float newposition)
{
	//AxisAlignedBox * b1 = _obj->getBoundingBox();
	//AxisAlignedBox testbox;
	//testbox.Extents = _obj->getBoundingBox()->Extents;
	//testbox.Center = newposition;

	//if (b1 != NULL)
	//{
	//	for (int i = 0; i < collObjects->size(); ++i)
	//	{
	//		AxisAlignedBox * b2 = collObjects->at(i)->getBoundingBox();
	//		if ((b2 != NULL) && (b1 != b2))//TODO:this is a place were we may have to compare the ID but not the pointers
	//		{
	//			if (IntersectAxisAlignedBoxAxisAlignedBox(&testbox, b2))
	//			{
	//				return true;
	//			}
	//		}
	//	}
	//}
	return false;
}
//-------------------------------------------------------------------------------------------------------------------------
void RotateAnimation::setCollidableObjects(std::vector<SpriteObject*> * collObjs)
{
	if (collObjs != NULL)
	{
		delete(collObjects);
		collObjects = collObjs;
	}
}
//-------------------------------------------------------------------------------------------------------------------------
float RotateAnimation::MakeMove(double deltaTime, float oldangle)
{
	float angleintent = CountIntendedMoveDistance(deltaTime);

	float coef = 1;
	if ((abs(_target_angle - _reached_angle) < abs(angleintent)) && (_has_target_angle))
	{
		coef = (_target_angle - _reached_angle) / angleintent;
	};

	oldangle += _speed * deltaTime * _step * coef;

	_reached_angle += angleintent*coef;

	return oldangle;
}
//-------------------------------------------------------------------------------------------------------------------------
float RotateAnimation::CountIntendedMoveDistance(double deltaTime)
{
	return _speed * deltaTime * _step;
}
//-------------------------------------------------------------------------------------------------------------------------
bool RotateAnimation::ReachedEnd()
{
	return (_reached_angle >= _target_angle);
}
//-------------------------------------------------------------------------------------------------------------------------
void RotateAnimation::Restart()
{
	_reached_angle = 0;
}
//-------------------------------------------------------------------------------------------------------------------------