#pragma once
#include "BaseAnimation.h"
#include "SpriteObject.h"
#include "d3dUtil.h"

namespace HotLine
{
	//-------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------THE CLASS COMMITS ALL THE MOVINGS OF THE SPRITES-----------------------------
	//-------------------------------------------------------------------------------------------------------------------------
	class MoveAnimation : public BaseAnimation
	{
	public:
		MoveAnimation(SpriteObject* obj, XMFLOAT3 step, float speed, float target_distance = -1);

		~MoveAnimation();

		virtual bool NextFrame(double deltaTime);

		virtual bool ReachedEnd();
		void Restart();

		static void setCollidableObjects(std::vector<SpriteObject*> * collObjs);
	protected:
		XMFLOAT3 MakeMove(double deltaTime, XMFLOAT3 oldposition);
		bool CollisionCheck(XMFLOAT3 newposition);
		float CountIntendedMoveDistance(double deltaTime);

		static std::vector<SpriteObject*> * collObjects;

		SpriteObject * _obj;
		XMFLOAT3 _step;
		float _speed;
		float _target_distance;
		float _reached_distance;
	};
}