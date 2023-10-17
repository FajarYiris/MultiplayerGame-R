#include "Game.hpp"

SDL_Texture* mobiltex;
SDL_Rect srcR, destR;


Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystem intialized!...." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			std::cout << "Renderer created!" << std::endl;
		}
		isrunning = true;
	}
	else {
		isrunning = false;
	}

	SDL_Surface* tmpsurface = IMG_Load("Asset/mobil.png");
	mobiltex = SDL_CreateTextureFromSurface(renderer, tmpsurface);
	SDL_FreeSurface(tmpsurface);
}

void Game::HandleEvents() 
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isrunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			// Move the car up
			destR.y -= moveSpeed;
			break;
		case SDLK_DOWN:
			// Move the car down
			destR.y += moveSpeed;
			break;
		case SDLK_LEFT:
			// Move the car left
			destR.x -= moveSpeed;
			break;
		case SDLK_RIGHT:
			// Move the car right
			destR.x += moveSpeed;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
}
void Game::update() 
{
	count++;
	destR.h = 64;
	destR.w = 64;
}
void Game::render() 
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, mobiltex, NULL, &destR);
	//add stuff to render
	SDL_RenderPresent(renderer);
}
void Game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleared" << std::endl;
}
