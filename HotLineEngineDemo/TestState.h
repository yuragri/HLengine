#pragma once
#include "BaseState.h"
#include "TextureAnimation.h"
#include "SpriteObject.h"
#include "Player.h"

namespace HotLine
{
	class TestState : public BaseState
	{
	public:
		TestState(ID3D11Device*);
		~TestState();

		virtual void addObjetcsToScene();
		virtual void addProcesses();
		virtual void addAnimations();

		void removeAllObjects();
		void removeAllProcesses();

		//controls----------------------
		void resolveKeyDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj);
		void resolveKeyUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj);
		void resolveMouseMove(WPARAM btnState, int x, int y, XMMATRIX& viewProj);
		void resolveLMouseUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj);
		void resolveLMouseDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj);
		void resolveRMouseUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj);
		void resolveRMouseDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj);

		void pauseState();
		void unpauseState();


		SpriteObject* getPlayer() { return player; }
	protected:
		Player * player;
		std::vector<SpriteObject *> * walls;
		std::vector<SpriteObject *> * floor;
	};
}