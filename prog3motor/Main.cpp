#include <GameEngine.h>
#include <vld.h>
#include <System.h>
#include <SDL.h>
#include <Sprite.h>
#include <HeroSprite.h>
#include <EnemySprite.h>
#include <SDL_image.h>

#define FPS 30
#define W_WIDTH 600
#define W_HEIGHT 400

using namespace prog3motor;
std::vector<Sprite*> sprites;
SDL_Surface* enemySurf;
SDL_Surface* enemySecondSurf;
SDL_Surface* heroSurf;
SDL_Surface* bgSurf;
HeroSprite* hero;

// Katt som är rädd för fiskar och måste undvika dem
void firstGame() {
	bgSurf = SDL_LoadBMP("media/bg.bmp");
	// Namn, bred, höjd, bakgrundsbild, fps, speed på hjälten, höger, vänster, upp, ned
	GameEngine ge = GameEngine("Gaem", W_WIDTH, W_HEIGHT, bgSurf, FPS, 10, false, false, true, true);
	heroSurf = SDL_LoadBMP("media/brasse.bmp");
	hero = HeroSprite::getInstance(heroSurf, 0, 250, 50, 50);

	enemySurf = SDL_LoadBMP("media/fish2.bmp");
	enemySecondSurf = SDL_LoadBMP("media/fish.bmp");

	Uint32 white = SDL_MapRGB(enemySecondSurf->format, 255, 255, 255);
	SDL_SetColorKey(enemySecondSurf, true, white);

	EnemySprite* e1 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 540, 250, 50, 50, 2, "left");
	EnemySprite* e2 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 540, 225, 50, 50, 2, "left");
	EnemySprite* e3 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 540, 300, 50, 50, 2, "left");
	EnemySprite* e4 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 540, 150, 50, 50, 2, "left");

	EnemySprite* e5 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 540, 75, 50, 50, 2, "left");
	EnemySprite* e6 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 540, 150, 50, 50, 2, "left");
	EnemySprite* e7 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 540, 250, 50, 50, 2, "left");
	EnemySprite* e8 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 540, 25, 50, 50, 2, "left");

	sprites.push_back(e1);
	sprites.push_back(e2);
	sprites.push_back(e3);
	sprites.push_back(e4);
	sprites.push_back(e5);
	sprites.push_back(e6);
	sprites.push_back(e7);
	sprites.push_back(e8);

	ge.setHero(hero);
	ge.setEnemies(sprites);
	ge.run();
}


// Fisk som måste undvika katter!
void secondGame() {
	bgSurf = SDL_LoadBMP("media/bg.bmp");
	// Namn, bred, höjd, bakgrundsbild, fps, speed på hjälten, höger, vänster, upp, ned
	GameEngine ge = GameEngine("Gaem", W_WIDTH, W_HEIGHT, bgSurf, FPS, 10, true, true, false, false);
	heroSurf = SDL_LoadBMP("media/fish2.bmp");
	hero = HeroSprite::getInstance(heroSurf, 250, 0, 50, 50);

	enemySurf = SDL_LoadBMP("media/brasse.bmp");
	enemySecondSurf = SDL_LoadBMP("media/brasse2.bmp");

	Uint32 white = SDL_MapRGB(enemySecondSurf->format, 255, 255, 255);
	SDL_SetColorKey(enemySecondSurf, true, white);

	EnemySprite* e1 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 450, 350, 50, 50, 2, "up");
	EnemySprite* e2 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 300, 350, 50, 50, 2, "up");
	EnemySprite* e3 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 75, 350, 50, 50, 2, "up");
	EnemySprite* e4 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 25, 350, 50, 50, 2, "up");

	EnemySprite* e5 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 250, 350, 50, 50, 2, "up");
	EnemySprite* e6 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 125, 350, 50, 50, 2, "up");
	EnemySprite* e7 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 175, 350, 50, 50, 2, "up");
	EnemySprite* e8 = EnemySprite::getInstance(enemySurf, enemySecondSurf, 280, 350, 50, 50, 4, "up");

	sprites.push_back(e1);
	sprites.push_back(e2);
	sprites.push_back(e3);
	sprites.push_back(e4);
	sprites.push_back(e5);
	sprites.push_back(e6);
	sprites.push_back(e7);
	sprites.push_back(e8);

	ge.setHero(hero);
	ge.setEnemies(sprites);
	ge.run();
}



int main(int argc, char** argv) {
	//firstGame();
	secondGame();
	return 0;
}