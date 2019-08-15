#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <string>
namespace prog3motor {
	class System
	{
	public:
		SDL_Renderer* getRenderer() const;
		SDL_Texture* getTexture() const;
		int getWindowWidth() const;
		int getWindowHeight() const;
		void initialize(std::string name, int width, int height, SDL_Surface* surface);
		~System();
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		SDL_Texture* text;
		int width;
		int height;
	};
	extern System sys;
}


#endif