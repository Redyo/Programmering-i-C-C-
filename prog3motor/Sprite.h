#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
namespace prog3motor {

	class Sprite
	{
	public:
		virtual ~Sprite();
		virtual void draw() = 0;
		virtual void tick() = 0;
		SDL_Texture* getTexture() const;
		SDL_Rect getRect() const;
		void setX(int i);
		void setY(int i);
		int getX() const;
		int getY() const;
		int getWidth() const;
		int getHeight() const;

	private:
		const Sprite& operator=(const Sprite& rhs) = delete;
		Sprite(const Sprite& other) = delete;
	protected:
		Sprite(SDL_Surface* s, int x, int y, int w, int h);
		SDL_Rect rect;
		SDL_Texture* texture;
		SDL_Surface* surf;
	};

}
#endif
