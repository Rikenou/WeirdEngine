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

	isRunning = true;
	framerate = 60;

	manager.init();

	return 0;

}

int Engine::Run()
{

	while (isRunning) {

		manager.update();
		manager.render();

		if (manager.shutdown()) {

			SDL_QUIT;
			isRunning = false;
			break;

		}

	}

	return 0;
	
}
