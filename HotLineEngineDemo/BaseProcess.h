#pragma once
#include "d3dUtil.h"

namespace HotLine
{
	class BaseProcess
	{
	public:
		BaseProcess() : isActive(true){};
		~BaseProcess() {};

		bool isActive;
		virtual void process(ID3D11DeviceContext* context, XMMATRIX& viewProj) = 0;
	};
}