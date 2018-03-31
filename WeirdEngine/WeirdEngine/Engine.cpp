#include "stdafx.h"
#include "Engine.h"
#include <iostream>
#include <SDL.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 4
#define DEPTH 32

using namespace WEIRD;

std::unique_ptr<Engine> Engine::engine(nullptr);

Engine::Engine()
{
}

Engine::~Engine()
{
	IMG_Quit;
	SDL_QUIT;
	isRunning = false;
}

Engine * Engine::startEngine()
{
	engine.reset(new Engine);
	return engine.get();
}

int Engine::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "SDL video init failed: %s\n", SDL_GetError());
		return 1;
	}

	deltaTime = 0;

	isRunning = true;
	framerate = 60;

	manager.init();

	return 0;

}

int Engine::Run()
{

	timePrev = SDL_GetTicks();
	timeNow = SDL_GetTicks();

	while (isRunning) {

		timePrev = timeNow;
		timeNow = SDL_GetTicks();

		deltaTime = static_cast<float>(timeNow - timePrev) / 1000.0f;

		manager.update(deltaTime);
		manager.render();

		if (manager.shutdown()) {

			isRunning = false;
			break;

		}
		
		if (1000 / 60 - (SDL_GetTicks() - timeNow) > 1000 / 60)
			SDL_Delay(1000 / 60);
		else
			SDL_Delay(1000 / 60 - (SDL_GetTicks() - timeNow));
			
	}

	return 0;
	
}
