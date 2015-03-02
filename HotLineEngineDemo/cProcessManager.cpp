#include "ProcessManager.h"
using namespace HotLine;

void ProcessManager::process(ID3D11DeviceContext* context, XMMATRIX& viewProj)
{
	for (vector<BaseProcess*>::iterator it = begin(); it != end(); ++it)
	{
		if ((*it)->isActive)
		{
			(*it)->process(context, viewProj);
		}
	}
}