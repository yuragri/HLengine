#pragma once
#include "BaseAnimation.h"
#include "SpriteObject.h"
#include "d3dUtil.h"

namespace HotLine
{
	class TextureAnimationStateInfo
	{
		friend class TextureAnimation;

	public:
		TextureAnimationStateInfo(SpriteObject* obj, std::vector<ID3D11ShaderResourceView*> * textures,
			int textures_per_second, bool looped = false);
		TextureAnimationStateInfo();
		~TextureAnimationStateInfo();

	protected:
		SpriteObject * _obj;
		std::vector<ID3D11ShaderResourceView*> * _textures;
		int _index;
		int _speed;
		bool _looped;
		double _time_passed;
	};
}