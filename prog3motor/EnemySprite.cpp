#include "EnemySprite.h"
#include "AnimatedMovingSprite.h"
#include "SDL.h"

namespace prog3motor {
	EnemySprite::EnemySprite(SDL_Surface* surf, SDL_Surface* secondSurf, int x, int y, int w, int h, int speed, std::string dir) : AnimatedMovingSprite(surf, secondSurf, x, y, w, h, speed, dir), Sprite(surf, x, y, w, h) {

	}

	EnemySprite* EnemySprite::getInstance(SDL_Surface* surf, SDL_Surface* secondSurf, int x, int y, int w, int h, int speed, std::string dir) {
		return new EnemySprite(surf, secondSurf, x, y, w, h, speed, dir);
	}

}
