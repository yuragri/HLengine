#pragma once
#include "ProcessManager.h"
#include "Time.h"


namespace HotLine
{
	class BaseAnimation
	{
	public:
		BaseAnimation(std::vector<double> * frameTimes, bool loop, 
			int StartOfTheLoop = 0) {}
		
		BaseAnimation() {};
		virtual ~BaseAnimation() {};
		
		virtual bool NextFrame(double deltaTime) = 0;
		virtual bool ReachedEnd() = 0;
	protected:
	};
}