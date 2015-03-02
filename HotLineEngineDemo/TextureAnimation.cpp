#pragma once
#include "TextureAnimation.h"

using namespace HotLine;


TextureAnimation::TextureAnimation(std::vector<double> * frameTimes,
	std::vector<ID3D11ShaderResourceView*> * frameTextures, bool loop, 
	SpriteObject* object,
	int StartOfTheLoop)
	:BaseAnimation(frameTimes, loop, StartOfTheLoop), textures(frameTextures), obj(object)
{
	assert(time->size() == textures->size());
}

TextureAnimation::~TextureAnimation()
{
	delete(textures);
}

bool TextureAnimation::nextFrame()
{
	//if animation is not on it`s start
	if (onStart)
	{
		MARKTIME(t1);
		//the animation started so it is no longer in the state of onStart
		onStart = false;
	}
	else
	{
		MARKTIME(t2);
		bool textureChanged = false;
		//t2 holds how much time has passed since previous screen frame
		t2 -= t1;

		//check if enough time has elapsed to go to the next frame of animation
		while (t2 >= time->at(currentFrame))
		{
			t2 -= time->at(currentFrame);
			currentFrame += 1;
			if (currentFrame == time->size())
			{
				//if we reached the last frame we put the counter to start
				currentFrame = startOfTheLoop;
				if (!isLoop){
					//the animation ended so it is again in the state onStart
					onStart = true;
					//false means there is no next frames
					return false;
				}
			}
			textureChanged = true;
		}
		if (textureChanged)
		{
			MARKTIME(t1);
			obj->setCurrentTexture(textures->at(currentFrame));
		}
	}
	return true;
}


