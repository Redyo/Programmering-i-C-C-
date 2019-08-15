#include "MovingSprite.h"
#include "System.h"


namespace prog3motor {

	MovingSprite::MovingSprite(SDL_Surface* s, int x, int y, int w, int h, int speed, std::string dir) : Sprite(s, x, y, w, h), speed(speed), direction(dir)
	{
		
	}

	int MovingSprite::getSpeed() const {
		return speed;
	}

	void MovingSprite::moveRight(int x) {
		rect.x = rect.x + x;
	}

	void MovingSprite::moveLeft(int x) {
		rect.x = rect.x - x;
	}

	void MovingSprite::moveUp(int y) {
		rect.y = rect.y - y;
	}

	void MovingSprite::moveDown(int y) {
		rect.y = rect.y + y;
	}

	void MovingSprite::tick() {

		if (direction == "right") {
			moveRight(speed);
		}
		if (direction == "left") {
			moveLeft(speed);
		}

		if (direction == "up") {
			moveUp(speed);
		}

		if (direction == "down") {
			moveDown(speed);
		}
	}

	void MovingSprite::draw(){
		SDL_RenderCopy(sys.getRenderer(), texture, NULL, &rect);
	}

	MovingSprite::~MovingSprite()
	{
		
	}

}
