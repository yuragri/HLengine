#pragma once
#include "BaseState.h"
#include "TextureAnimation.h"
#include "SpriteObject.h"
#include "AnimatedHuman.h"
#include "Camera.h"

namespace HotLine
{
	class TestState : public BaseState
	{
	public:
		TestState(ID3D11Device*, Camera* camera);
		~TestState();

		virtual void addObjetcsToScene();
		virtual void addProcesses();
		virtual void addAnimations();

		void removeAllObjects();
		void removeAllProcesses();

		//controls----------------------
		void resolveKeyDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj);
		void resolveKeyUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj);
		void resolveMouseMove(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort);
		void resolveLMouseUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort);
		void resolveLMouseDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort);
		void resolveRMouseUp(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort);
		void resolveRMouseDown(WPARAM btnState, int x, int y, XMMATRIX& viewProj, D3D11_VIEWPORT viewPort);

		void pauseState();
		void unpauseState();

		SpriteObject* getPlayerBodySprite() { return player->GetBodySprite(); }
	protected:
		AnimatedHuman * player;
		std::vector<SpriteObject *> * walls;
		std::vector<SpriteObject *> * floor;

		Camera* cam;
	};
}