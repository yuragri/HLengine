#pragma once
#include "ProcessManager.h"
#include "Time.h"


namespace HotLine
{
	class BaseAnimation
	{
	public:
		BaseAnimation(std::vector<double> * frameTimes, bool loop, 
			int StartOfTheLoop = 0) : time(frameTimes), startOfTheLoop(StartOfTheLoop),
			t2(0), currentFrame(0),
			isLoop(loop), onStart(true){}
		~BaseAnimation(){
			delete(time);
		}

		virtual bool nextFrame() = 0;

		//this var is true when the animation has not started yet
		bool onStart;

	protected:
		double t1;
		double t2;
		int currentFrame;
		bool isLoop;
		int startOfTheLoop;

		std::vector<double> * time;
	};
}