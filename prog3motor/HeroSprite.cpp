#include "Sprite.h"
#include "HeroSprite.h"
#include "MovingSprite.h"
#include <SDL.h>
#include <System.h>
namespace prog3motor {
	HeroSprite::HeroSprite(SDL_Surface* surf, int x, int y, int w, int h) : MovingSprite(surf, x, y, w, h, 0, ""), Sprite(surf, x, y, w, h) {

	}

	HeroSprite* HeroSprite::getInstance(SDL_Surface* surf, int x, int y, int w, int h) {
		return new HeroSprite(surf, x, y, w, h);
	}

}