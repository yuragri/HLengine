#pragma once
#include "ProcessManager.h"
#include "AnimationManager.h"
#include "SpriteObject.h"


namespace HotLine
{
	class BaseState
	{
	public:
		BaseState(ID3D11Device* md3dDevice) : device(md3dDevice)
		{
			processes = new std::vector<BaseProcess*>();
			animations = new std::vector<BaseAnimation*>();
			boundedStates = new std::vector<BaseState*>();
			resultingState = NULL;
			isPaused = false;
			GUID guid;
			HRESULT hCreateGuid = CoCreateGuid(&guid);
		}
		~BaseState() {};

		void _release()
		{
			removeAllObjects();
			removeAllProcesses();

			delete(processes);
			delete(animations);
		}

		void init()
		{
			addObjetcsToScene();
			addProcesses();
			addAnimations();
		}

		virtual void addObjetcsToScene()=0;
		virtual void addProcesses()=0;
		virtual void addAnimations()=0;

		virtual void pauseState() = 0;
		virtual void unpauseState() = 0;

		void addProcess(BaseProcess*);
		void removeProcess(BaseProcess*);
		void addAnimation(BaseAnimation*);
		void removeAnimation(BaseAnimation*);
		void addBoundedState(BaseState*);
		void removeBoundedState(BaseState*);

		BaseState* render(ID3D11DeviceContext* context, XMMATRIX& viewProj);

		virtual void removeAllObjects() = 0;
		virtual void removeAllProcesses() = 0;

		virtual void resolveKeyDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj) = 0;
		virtual void resolveKeyUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj) = 0;
		virtual void resolveMouseMove(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort) = 0;
		virtual void resolveLMouseUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort) = 0;
		virtual void resolveLMouseDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort) = 0;
		virtual void resolveRMouseUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort) = 0;
		virtual void resolveRMouseDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort) = 0;

		virtual SpriteObject* getPlayerBodySprite() = 0;

		bool isPaused;

		GUID guid;

		std::vector<BaseProcess*> * processes;
		std::vector<BaseAnimation*> * animations;
	protected:
		ID3D11Device* device;


		//some states which can be returned by render() method
		std::vector<BaseState*> * boundedStates;
		//some states which is returned by render() method
		BaseState* resultingState;
	private:



	};
}