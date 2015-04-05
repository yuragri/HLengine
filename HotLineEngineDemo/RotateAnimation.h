#pragma once
#include "BaseAnimation.h"
#include "SpriteObject.h"
#include "d3dUtil.h"

namespace HotLine
{
	//-------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------THE CLASS COMMITS ALL THE ROTATIONS OF THE SPRITES---------------------------
	//-------------------------------------------------------------------------------------------------------------------------
	class RotateAnimation : public BaseAnimation
	{
	public:
		RotateAnimation(SpriteObject* obj, float step, float speed, bool has_target_angle = false, float target_angle = -1);
		~RotateAnimation();

		virtual bool NextFrame(double deltaTime);

		virtual bool ReachedEnd();
		void Restart();

		static void setCollidableObjects(std::vector<SpriteObject*> * collObjs);
	protected:
		float MakeMove(double deltaTime, float oldangle);
		bool CollisionCheck(float newposition);
		float CountIntendedMoveDistance(double deltaTime);

		static std::vector<SpriteObject*> * collObjects;

		SpriteObject * _obj;
		float _step;
		float _speed;
		float _target_angle;
		float _reached_angle;
		bool _has_target_angle;
	};
}