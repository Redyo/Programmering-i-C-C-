#ifndef ANIMATEDMOVINGSPRITE_H
#define ANIMATEDMOVINGSPRITE_H
#include <SDL.h>
#include "AnimatedSprite.h"
#include "MovingSprite.h"
namespace prog3motor {
	class AnimatedMovingSprite : public MovingSprite, public AnimatedSprite
	{
	public:
		void draw() override;
		void tick() override;
		virtual ~AnimatedMovingSprite();
	private:

	protected:
		AnimatedMovingSprite(SDL_Surface* surf, SDL_Surface* secondSurf, int x, int y, int w, int h, int speed, std::string dir);
	};

}

#endif