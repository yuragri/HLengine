#pragma once
#include <queue>
#include <vector>
#include "BaseProcess.h"
using namespace std;


namespace HotLine
{
	class ProcessManager : public vector<BaseProcess*>
	{
	public:
		ProcessManager() {};
		~ProcessManager() {};

		void process(ID3D11DeviceContext* context, XMMATRIX& viewProj);
	};
}