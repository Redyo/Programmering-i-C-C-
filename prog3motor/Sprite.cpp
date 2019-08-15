#include "Sprite.h"
#include <System.h>

namespace prog3motor {

	Sprite::Sprite(SDL_Surface* s, int x, int y, int w, int h): surf(s) {
		rect = { x,y,w,h };
		texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surf);
	}

	void Sprite::setX(int i) {
		rect.x = i;
	}

	void Sprite::setY(int i) {
		rect.y = i;
	}

	int Sprite::getX() const {
		return rect.x;
	}

	int Sprite::getY() const {
		return rect.y;
	}

	int Sprite::getWidth() const {
		return rect.w;
	}

	int Sprite::getHeight() const {
		return rect.h;
	}

	SDL_Rect Sprite::getRect() const {
		return rect;
	}

	SDL_Texture* Sprite::getTexture() const {
		return texture;
	}

	Sprite::~Sprite()
	{
		SDL_DestroyTexture(texture);
	}
}