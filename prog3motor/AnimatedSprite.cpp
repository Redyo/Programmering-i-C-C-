#include "AnimatedSprite.h"
#include "System.h"

namespace prog3motor {
	
	AnimatedSprite::AnimatedSprite(SDL_Surface* surf, SDL_Surface* secondSurf, int x, int y, int w, int h): Sprite(surf,x,y,w,h), secondSurf(secondSurf){

	}

	void AnimatedSprite::tick() {
		i++;
		if (change && i % 25 == 0) {
			texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surf);
			change = false;
		}
		else {
			if (i % 25 == 0) {
				texture = SDL_CreateTextureFromSurface(sys.getRenderer(), secondSurf);
				change = true;
			}
		}
	}

	void AnimatedSprite::draw(){
		SDL_RenderCopy(sys.getRenderer(), texture, NULL, &rect);
	}

	AnimatedSprite::~AnimatedSprite()
	{

	}


}
