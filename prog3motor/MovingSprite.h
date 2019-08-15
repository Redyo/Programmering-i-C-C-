#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include <SDL.h>
#include "Sprite.h"
#include <string>


namespace prog3motor {
	class MovingSprite : virtual public Sprite
	{
	public:
		void tick() override;
		void draw() override;
		int getSpeed() const;
		void moveLeft(int x);
		void moveRight(int x);
		void moveUp(int y);
		void moveDown(int y);
		virtual ~MovingSprite();
	private:
		int speed;
		std::string direction;
	protected:
		MovingSprite(SDL_Surface* s, int x, int y, int w, int h, int speed, std::string dir);
	};


}

#endif