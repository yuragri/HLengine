#pragma once
#include "TextureAnimation.h"



using namespace HotLine;
//-------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------THE CLASS COMMITS ALL THE TEXTURE CHANGES OF THE SPRITES---------------------
//-------------------------------------------------------------------------------------------------------------------------
//TextureAnimation::TextureAnimation(SpriteObject* obj, std::vector<ID3D11ShaderResourceView*> * textures,
//	int textures_per_second, bool looped) : _obj(obj), _textures(textures), _speed(textures_per_second), 
//	_looped(looped), _index(0), _time_passed(0) {}
//-------------------------------------------------------------------------------------------------------------------------
TextureAnimation::TextureAnimation() : _info() {}
//-------------------------------------------------------------------------------------------------------------------------
TextureAnimation::~TextureAnimation() {}
//-------------------------------------------------------------------------------------------------------------------------
bool TextureAnimation::NextFrame(double deltaTime)
{
	_info->_time_passed += deltaTime;

	_info->_index = (int)(_info->_time_passed*_info->_speed);
	if (_info->_looped)
		_info->_index = _info->_index % _info->_textures->size();
	else if (_info->_index>_info->_textures->size() - 1) {
		__raise OnAnimationFinished();
		return false;
	}
	_info->_obj->setCurrentTexture(_info->_textures->at(_info->_index));

	return true;
}
//-------------------------------------------------------------------------------------------------------------------------
void TextureAnimation::Restart()
{
	_info->_time_passed = 0;
	_info->_index = 0;
}
//-------------------------------------------------------------------------------------------------------------------------
bool TextureAnimation::ReachedEnd()
{
	return (_info->_index > _info->_textures->size() - 1);
}
//-------------------------------------------------------------------------------------------------------------------------
bool TextureAnimation::HasSameTexturesWith(TextureAnimation* anim)
{
	if (_info->_textures->size() != anim->GetTextures()->size()) return false;
	for (int i = 0; i < _info->_textures->size(); ++i)
	{
		if (_info->_textures->at(i) != anim->GetTextures()->at(i)) return false;
	}
	return true;
}
//-------------------------------------------------------------------------------------------------------------------------
bool TextureAnimation::HasSameTexturesWith(TextureAnimationStateInfo* info)
{
	if (_info->_textures->size() != info->_textures->size()) return false;
	for (int i = 0; i < _info->_textures->size(); ++i)
	{
		if (_info->_textures->at(i) != info->_textures->at(i)) return false;
	}
	return true;
}
//-------------------------------------------------------------------------------------------------------------------------
void TextureAnimation::JumpToFrame(int i)
{
	double frameoffset = _info->_time_passed - _info->_index;
	_info->_time_passed = (double)i / (double)_info->_speed + frameoffset;
}
//-------------------------------------------------------------------------------------------------------------------------
void TextureAnimation::SetTextureAnimationStateInfo(TextureAnimationStateInfo *info)
{
	_info = info;
}