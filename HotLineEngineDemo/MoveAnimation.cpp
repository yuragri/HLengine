#pragma once
#include "MoveAnimation.h"

using namespace HotLine;

std::vector<SpriteObject*> * MoveAnimation::collObjects = new std::vector<SpriteObject*>();

// Helper function for printing info in output window

void TRACE(const wchar_t* szFormat, ...)
{
	wchar_t szBuff[1024] = { 0 };
	va_list arg;
	va_start(arg, szFormat);
	_vsnwprintf_s(&szBuff[0], _countof(szBuff), _TRUNCATE, szFormat, arg);
	va_end(arg);

	OutputDebugString(szBuff);
};
//--------------------------------------------------------------------------------
MoveAnimation::MoveAnimation(std::vector<double> * frameTimes,
	std::vector<XMFLOAT3> * frameTextures, bool loop,
	SpriteObject* object,
	int StartOfTheLoop)
	:BaseAnimation(frameTimes, loop, StartOfTheLoop), moves(frameTextures), obj(object)
{
	assert(time->size() == moves->size());
}

MoveAnimation::~MoveAnimation()
{
	delete(moves);
	TRACE(L"Animation Killed");
}

bool MoveAnimation::nextFrame()
{
	//if animation is not on it`s start
	if (onStart)
	{
		MARKTIME(t1);
		//the animation started so it is no longer in the state of onStart
		onStart = false;
	}
	else
	{
		MARKTIME(t2);
		
		bool positionChanged = false;
		//t2 holds how much time has passed since previous screen frame
		t2 -= t1;

		//check if enough time has elapsed to go to the next frame of animation
		while (t2 > time->at(currentFrame))
		{
			t2 -= time->at(currentFrame);
			currentFrame += 1;
			if (currentFrame == time->size())
			{
				//if we reached the last frame we put the counter to start
				currentFrame = startOfTheLoop;
				if (!isLoop){
					//the animation ended so it is again in the state onStart
					onStart = true;
					//false means there is no next frames
					return false;
				}
			}

			XMFLOAT3 oldPosition = obj->getWorldPosition();
			XMFLOAT3 newPosition = obj->getWorldPosition();
			newPosition.x += moves->at(currentFrame).x;
			newPosition.y += moves->at(currentFrame).y;
			newPosition.z += moves->at(currentFrame).z;
			TRACE(L"Time:%f, x=%f,y=%f,z=%f\n", t2, newPosition.x, newPosition.y, newPosition.z);
			obj->setWorldPosition(newPosition);

			positionChanged = true;

			//check for collision
			//we cancel move if collision occurs
			AxisAlignedBox * b1 = obj->getBoundingBox();
			if (b1 != NULL)
			{
				for (int i = 0; i < collObjects->size(); ++i)
				{
					AxisAlignedBox * b2 = collObjects->at(i)->getBoundingBox();
					if ((b2 != NULL) && (b1!=b2))//TODO:this is a place were we may have to compare the ID but not the pointers
					{
						if (IntersectAxisAlignedBoxAxisAlignedBox(b1, b2))
						{
							obj->setWorldPosition(oldPosition);
							break;
						}
					}
				}
			}

		}
		if (positionChanged)
		{
			TRACE(L"FrameEnded------------------------------------------------\n");
			MARKTIME(t1);
		}
	}
	return true;
}



void MoveAnimation::setCollidedObjects(std::vector<SpriteObject*> * collObjs)
{

	if (collObjs != NULL)
	{
		delete(collObjects);
		collObjects = collObjs;
	}
}

