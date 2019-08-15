#include "System.h"
#include <SDL.h>

namespace prog3motor {

	void System::initialize(std::string name, int w, int h, SDL_Surface* surface) {
		height = h;
		width = w;
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		text = SDL_CreateTextureFromSurface(ren, surface);
	}

	SDL_Renderer* System::getRenderer() const {
		return ren;
	}

	SDL_Texture* System::getTexture() const {
		return text;
	}

	int System::getWindowWidth() const {
		return width;
	}

	int System::getWindowHeight() const {
		return height;
	}
	
	System::~System()
	{
		SDL_DestroyWindow(win);
		SDL_DestroyTexture(text);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}
	System sys;
}

