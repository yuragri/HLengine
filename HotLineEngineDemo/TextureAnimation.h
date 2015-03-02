#pragma once
#include "BaseAnimation.h"
#include "SpriteObject.h"
#include "d3dUtil.h"

namespace HotLine
{
	class TextureAnimation : public BaseAnimation
	{
	public:
		TextureAnimation(std::vector<double> * frameTimes,
			std::vector<ID3D11ShaderResourceView*> * frameTextures, 
			bool loop, 
			SpriteObject* obj, int StartOfTheLoop = 0);
		~TextureAnimation();

		bool nextFrame();
	protected:
		std::vector<ID3D11ShaderResourceView*> * textures;
		SpriteObject * obj;
	};
}