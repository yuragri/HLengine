#pragma once
#include "BaseProcess.h"
#include "BaseObject.h"
namespace HotLine
{
	class DrawAllProcess : public BaseProcess
	{
	public:
		DrawAllProcess(std::vector<BaseObject*> * objs) : objects(objs) {};
		~DrawAllProcess();

		void process(ID3D11DeviceContext* context, XMMATRIX& viewProj);

		std::vector<BaseObject*>* objects;
	};
}