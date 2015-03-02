#include "DrawAllProcess.h"
using namespace HotLine;

void DrawAllProcess::process(ID3D11DeviceContext* context, XMMATRIX& viewProj)
{
	for (int i = 0; i < objects->size(); ++i)
	{
		if (objects->at(i)->visible)
		{
			objects->at(i)->Draw(context, viewProj);
		}
	}
}