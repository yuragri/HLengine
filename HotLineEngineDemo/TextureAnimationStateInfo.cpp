#pragma once
#include "TextureAnimationStateInfo.h"

using namespace HotLine;

//-------------------------------------------------------------------------------------------------------------------------
TextureAnimationStateInfo::TextureAnimationStateInfo(SpriteObject* obj, std::vector<ID3D11ShaderResourceView*> * textures,
	int textures_per_second, bool looped) : _obj(obj), _textures(textures), _speed(textures_per_second),
	_looped(looped), _index(0), _time_passed(0) {}
//-------------------------------------------------------------------------------------------------------------------------
TextureAnimationStateInfo::TextureAnimationStateInfo() : _obj(NULL), _textures(NULL), _speed(0), _looped(false), _index(0), _time_passed(0) {}
//-------------------------------------------------------------------------------------------------------------------------
TextureAnimationStateInfo::~TextureAnimationStateInfo()
{
	delete(_textures);
}
//-------------------------------------------------------------------------------------------------------------------------


