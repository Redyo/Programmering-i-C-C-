#ifndef HEROSPRITE_H
#define HEROSPRITE_H
#include "MovingSprite.h"

namespace prog3motor {

	class HeroSprite : public MovingSprite
	{
	public:
		static HeroSprite* getInstance(SDL_Surface* surf, int x, int y, int w, int h);
		
		
	protected:
		HeroSprite(SDL_Surface* surf, int x, int y, int w, int h);
	};


}

#endif