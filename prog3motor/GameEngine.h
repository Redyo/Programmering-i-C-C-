#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <Sprite.h>
#include <vector>
#include <SDL.h>

namespace prog3motor {

	class GameEngine
	{
	public:
		void run();
		bool collisionDetection(SDL_Rect a, SDL_Rect b);
		void setHero(Sprite* hero);
		void setEnemies(std::vector<Sprite*> enemies);
		void addEnemy();
		void add(Sprite* s);
		void remove(int i);
		bool outside(Sprite* s);
		bool exists(Sprite* s);
		GameEngine(std::string name, int width, int height, SDL_Surface* surface, int _fps, int speed, bool right, bool left, bool up, bool down);
		~GameEngine();
	private:
		std::vector<Sprite*> sprites;
		std::vector<Sprite*> enemies;
		int fps;
		int speed;
		bool right, left, up, down;
	};

}
#endif