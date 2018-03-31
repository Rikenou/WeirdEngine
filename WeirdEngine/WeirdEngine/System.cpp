#include "stdafx.h"
#include "System.h"
#include <iostream>
#include <SDL_image.h>

using namespace WEIRD;

System::System(SystemType newType)
{

	if (newType.Type == "Window")
		Type = newType;

	else if (newType.Type == "Input")
		Type = newType;

	else
		KMS = true;

}


System::~System()
{

}

bool WEIRD::System::init()
{

	if (Type.Type == "Window") {

		window = SDL_CreateWindow("Weird Engine 0.1 alpha",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			1280, 720, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			fprintf(stderr, "Window could not be created: %s\n", SDL_GetError());
			return 1;
		}
		
		int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			return 1;
		}


		screenRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		SDL_SetRenderDrawColor(screenRender, 255, 255, 255, 255);

	}

	else if (Type.Type == "Input") {


	}

	return true;
}

void WEIRD::System::update(float deltaTime)
{

	if (Type.Type == "Input") {

		events();

	}

}

void WEIRD::System::render(Scene* currentScene)
{

	if (Type.Type == "Window") {

		if (screenRender == NULL) {
			printf("Could not create Render");
			return;
		}

		SDL_RenderClear(screenRender);
		currentScene->render(screenRender);
		SDL_RenderPresent(screenRender);

	}

}

bool WEIRD::System::shutdown()
{

	if(KMS)
		SDL_Quit();
	
	return KMS;
}

SystemType WEIRD::System::getType()
{
	return Type;
}

void WEIRD::System::events()
{

	while (SDL_PollEvent(&event)) {
		switch (event.type) {

		case SDL_EventType::SDL_QUIT:
			KMS = true;
			return;

		case SDL_EventType::SDL_KEYDOWN:
			switch (event.key.keysym.sym) {

			case SDLK_ESCAPE:
				KMS = true;
				return;

			case SDLK_w:
				inputs.w = true;
				return;

			case SDLK_a:
				inputs.a = true;
				return;

			case SDLK_s:
				inputs.s = true;
				return;

			case SDLK_d:
				inputs.d = true;
				return;

			}

		case SDL_EventType::SDL_KEYUP:
			switch (event.key.keysym.sym) {

			case SDLK_w:
				inputs.w = false;
				return;

			case SDLK_a:
				inputs.a = false;
				return;

			case SDLK_s:
				inputs.s = false;
				return;

			case SDLK_d:
				inputs.d = false;
				return;

			}

		default:
			return;
		}
	}
	
}