#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <SDL.h>
#include <Sprite.h>

namespace prog3motor {
	class AnimatedSprite : virtual public Sprite
	{
	public:
		void draw() override;
		void tick() override;
		virtual ~AnimatedSprite();

	private:
		bool change = true;
		int i = 0;
		SDL_Surface* secondSurf;

	protected:
		AnimatedSprite(SDL_Surface* surf, SDL_Surface* secondSurf, int x, int y, int w, int h);
		
	};
}


#endif