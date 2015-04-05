#pragma once
#include "BaseAnimation.h"
#include "TextureAnimationStateInfo.h"
#include "SpriteObject.h"
#include "d3dUtil.h"

namespace HotLine
{
	//-------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------THE CLASS COMMITS ALL THE TEXTURE CHANGES OF THE SPRITES---------------------
	//-------------------------------------------------------------------------------------------------------------------------
	class TextureAnimation : public BaseAnimation
	{
	public:
		TextureAnimation();

		~TextureAnimation();

		void SetTextureAnimationStateInfo(TextureAnimationStateInfo * info);
		bool HasSameTexturesWith(TextureAnimation* anim);
		bool HasSameTexturesWith(TextureAnimationStateInfo* info);
		void JumpToFrame(int i);
		void Restart();
		virtual bool ReachedEnd();

		virtual bool NextFrame(double deltaTime);
	
		inline const int GetIndex() const { return _info->_index; };
		inline const int GetSpeed() const { return _info->_speed; };
		inline const bool GetLooped() const { return _info->_looped; };
		inline const double GetTimePassed() const { return _info->_time_passed; };
		inline const std::vector<ID3D11ShaderResourceView*> * GetTextures() const { return _info->_textures; };
		inline const SpriteObject* GetSpriteObject() const { return _info->_obj; }

		inline void SetLooped(bool b) { _info->_looped = b; };

		__event void OnAnimationFinished();

	protected:
		TextureAnimationStateInfo * _info;
	};
}