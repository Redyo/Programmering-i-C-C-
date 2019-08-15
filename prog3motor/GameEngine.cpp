#include <SDL.h>
#include "GameEngine.h"
#include <System.h>
#include <Sprite.h>
#include <HeroSprite.h>

namespace prog3motor {
	SDL_Texture* heroText;
	SDL_Rect heroRect;
	Sprite* heroSprite;
	GameEngine::GameEngine(std::string name, int width, int height, SDL_Surface* surf, int _fps, int speed, bool r, bool l, bool u, bool d): fps(_fps), speed(speed), right(r), left(l), up(u), down(d){
		sys.initialize(name, width, height, surf);
	}

	void GameEngine::setHero(Sprite* hero) {
		heroRect = hero->getRect();
		heroText = hero->getTexture();
		heroSprite = hero;
	}

	void GameEngine::setEnemies(std::vector<Sprite*> enemySprites) {
		enemies = enemySprites;
	}

	void GameEngine::addEnemy() {
		int i = rand() % enemies.size();
		while (exists(enemies[i]) && sprites.size() != enemies.size()) {
			i = rand() % enemies.size();
		}

		if (!exists(enemies[i])) {
			add(enemies[i]);
		}
	}

	bool GameEngine::exists(Sprite* s) {
		for (Sprite* sprite : sprites) {
			if (sprite == s) {
				return true;
			}
		}
		return false;
	}

	// Kolla om utanför och om, byt x/y värden.
	bool GameEngine::outside(Sprite* s) {
		// Från höger 
		if (s->getX() < 0) {
			s->setX(550);
			return true;
		}
		// Från vänster
		if (s->getX() > 550) {
			s->setX(0);
			return true;
		}
		 //Från botten
		if (s->getY() < 0) {
			s->setY(550);
			return true;
		}
		// Från topp
		if (s->getY() > 550) {
			s->setY(0);
			return true;
		}

		return false;
	}


	void GameEngine::remove(int i) {
		sprites.erase(sprites.begin() + i--);
	}

	void GameEngine::add(Sprite* s) { 
		sprites.push_back(s);
	}


	void GameEngine::run() {
		const int tickInterval = 1000 / fps;
		bool quit = false;
		int i = 0;
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_KEYDOWN:
					switch (eve.key.keysym.sym) {	
					case SDLK_RIGHT: 
						if (right) {
							if (heroRect.x != sys.getWindowWidth() - 50) {
								heroRect.x = heroRect.x + speed;
								
							}
						} break;
					case SDLK_LEFT:
						if (left) {
							if (heroRect.x != 0) {
								heroRect.x = heroRect.x - speed;

							}
						} break;
					case SDLK_UP:
						if (up) {
							if (heroRect.y != 0) {
								heroRect.y = heroRect.y - speed;
							}
						} break;
					case SDLK_DOWN: 
						if (down) {
							if (heroRect.y != sys.getWindowHeight() - 50) {
								heroRect.y = heroRect.y + speed;
							}
						} break;
						 
					}
				} // switch
			}// inre while

			SDL_RenderClear(sys.getRenderer());
			// Bakgrunden
			SDL_RenderCopy(sys.getRenderer(), sys.getTexture(), NULL, NULL);
			// Hjälten
			SDL_RenderCopy(sys.getRenderer(), heroText, NULL, &heroRect);
			// Presentera nya sprites
			
			for (int i = 0; i < sprites.size(); i++) {
				SDL_Rect rect = sprites[i]->getRect();
				sprites[i]->tick();
				sprites[i]->draw();
				rect = sprites[i]->getRect();

				if (outside(sprites[i])) {
					remove(i);
				}
				if (collisionDetection(rect, heroRect)) {
					quit = true;
				}
			}
			
			SDL_RenderPresent(sys.getRenderer());
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				i++;

			if (i % fps == 0){
				addEnemy();
			}
			SDL_Delay(delay);
		} // yttre while
		
	}


	bool GameEngine::collisionDetection(SDL_Rect spriteRect, SDL_Rect heroRect) {
		int leftSpriteRect, leftHeroRect;
		int rightSpriteRect, rightHeroRect;
		int topSpriteRect, topHeroRect;
		int bottomSpriteRect, bottomHeroRect;


		leftSpriteRect = spriteRect.x;
		rightSpriteRect = spriteRect.x + spriteRect.w;
		topSpriteRect = spriteRect.y;
		bottomSpriteRect = spriteRect.y + spriteRect.h;

		leftHeroRect = heroRect.x;
		rightHeroRect = heroRect.x + heroRect.w;
		topHeroRect = heroRect.y;
		bottomHeroRect = heroRect.y + heroRect.h;

		if (bottomSpriteRect <= topHeroRect)
		{
			return false;
		}

		if (topSpriteRect >= bottomHeroRect)
		{
			return false;
		}

		if (rightSpriteRect <= leftHeroRect)
		{
			return false;
		}

		if (leftSpriteRect >= rightHeroRect)
		{
			return false;
		}
		return true;
	}

	GameEngine::~GameEngine() {
		SDL_DestroyTexture(heroText);
		for (Sprite* s : enemies) {
			delete s;
		}
		delete heroSprite;

	}


}

