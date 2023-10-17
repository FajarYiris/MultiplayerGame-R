
#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include <iostream>
#include "SDL_image.h"

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void HandleEvents();

	void update();
	void render();
	void clean();

	bool running()
	{
		return isrunning;
	};

private:
	bool isrunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int count = 0;
	int moveSpeed = 10;
};

#endif // !Game_hpp