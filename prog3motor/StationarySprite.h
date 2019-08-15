#ifndef STATIONARYSPRITE_H
#define STATIONARYSPRITE_H
#include <SDL.h>
#include <Sprite.h>


namespace prog3motor {
	class StationarySprite : public Sprite
	{
	public:
		virtual ~StationarySprite();
	protected:
		StationarySprite(SDL_Surface* s, int x, int y, int w, int h);
	};

}

#endif