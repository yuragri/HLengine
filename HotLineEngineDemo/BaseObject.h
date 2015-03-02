#pragma once
#include "d3dUtil.h"
#include "Sprite.h"

namespace HotLine
{ 
	class BaseObject
	{
	public:
		BaseObject() : visible(true){};
		~BaseObject(){};

		bool visible;
		virtual void Draw(ID3D11DeviceContext* context, XMMATRIX& viewProj)=0;

		//Sprite* sprite;
		//ID3D11ShaderResourceView* texture;
	};
}