#include "TestState.h"

namespace HotLine
{
	//-An example of state overriding.
	//-All the behavior of base class (except for objects 
	//-------------on the scene created by overriden method addObjetcsToScene()) remains the same.
	class TestStateDerrivative : public TestState
	{
	public:
		TestStateDerrivative(ID3D11Device* d) : TestState(d) {};
		~TestStateDerrivative();


		//overriden method
		void addObjetcsToScene()
		{
			//adding a player---------------------------------------------------------------------------------------
			ID3D11ShaderResourceView* texture;
			D3DX11CreateShaderResourceViewFromFile(device, L"Textures/runPose1.dds", 0, 0, &texture, 0);

			player = new Player(device, texture, 4.f, 4.f, XMFLOAT2(0, 0), XMFLOAT2(1.0f, 1.0f));
			player->setWorldPosition({ 0, 1, 0 });
		}
	};
}