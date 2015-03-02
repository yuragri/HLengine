#pragma once
#include "BaseAnimation.h"
#include "SpriteObject.h"
#include "d3dUtil.h"

namespace HotLine
{
	class MoveAnimation : public BaseAnimation
	{
	public:
		MoveAnimation(std::vector<double> * frameTimes,
			std::vector<XMFLOAT3> * frameTextures, bool loop,
			SpriteObject* obj,
			int StartOfTheLoop = 0);
		~MoveAnimation();


		bool nextFrame();

		static void setCollidedObjects(std::vector<SpriteObject*> * collObjs);
		static std::vector<SpriteObject*> * collObjects;
	protected:
		std::vector<XMFLOAT3> * moves;
		SpriteObject * obj;
	};
}