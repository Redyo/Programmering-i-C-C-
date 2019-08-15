#include "AnimatedMovingSprite.h"

namespace prog3motor {

	AnimatedMovingSprite::AnimatedMovingSprite(SDL_Surface* surf, SDL_Surface* secondSurf, int x, int y, int w, int h, int speed, std::string dir) : Sprite(surf, x, y, w, h), MovingSprite(surf,x, y, w, h, speed, dir), AnimatedSprite(surf,secondSurf, x,y,w,h){
		
	}

	void AnimatedMovingSprite::tick() {
		MovingSprite::tick();
		AnimatedSprite::tick();
	}

	void AnimatedMovingSprite::draw() {
		AnimatedSprite::draw();
	}

	AnimatedMovingSprite::~AnimatedMovingSprite(){
	
	}

}

