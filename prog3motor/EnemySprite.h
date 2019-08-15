#ifndef ENEMYSPRITE_H
#define ENEMYSPRITE_H
#include "AnimatedMovingSprite.h"

namespace prog3motor {
	class EnemySprite : public AnimatedMovingSprite {
	public:
		static EnemySprite* getInstance(SDL_Surface* surf, SDL_Surface* secondSurf, int x, int y, int w, int h, int speed, std::string dir);
	private:

	protected:
		EnemySprite(SDL_Surface* surf, SDL_Surface* secondSurf, int x, int y, int w, int h, int speed, std::string dir);
	};


}


#endif