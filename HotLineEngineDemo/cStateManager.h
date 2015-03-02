#pragma once
#include <vector>
#include "BaseState.h"

namespace HotLine
{ 
	class cStateManager : public std::vector<BaseState*>
	{
	public:
		cStateManager() {};
		~cStateManager() {};


		void addState(BaseState* b)
		{
			if (back() == b) { return; }
			for (int i = 1; i < size(); ++i)
			{
				if (at(i) == b)
				{
					erase(begin() + i);
				}
			}
			push_back(b);
		}

		void removeState(BaseState* b)
		{
			//TODO:
		}

		//call each time before rendering
		//pauses everything but the last state
		void prepare() 
		{
			for (int i = 0; i < size()-1; ++i)
			{
				at(i)->pauseState();
			}
			back()->unpauseState();
		}
	};
}
