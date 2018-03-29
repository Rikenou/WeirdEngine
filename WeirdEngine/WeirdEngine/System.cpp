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

		window = SDL_CreateWindow("Weird Engine 0.01 Not even Pre-Alpha...",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			1280, 720, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			fprintf(stderr, "Window could not be created: %s\n", SDL_GetError());
			return 1;
		}

		screenSurface = SDL_GetWindowSurface(window);

		if (!screenSurface) {
			fprintf(stderr, "Screen surface could not be created: %s\n", SDL_GetError());
			SDL_Quit();
			return 1;
		}

		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			return 1;
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
		}

	}

	else if (Type.Type == "Input") {


	}

	return true;
}

void WEIRD::System::update()
{

	if (Type.Type == "Window") {

	}

	else if (Type.Type == "Input") {

		events();

	}
}

void WEIRD::System::render(Scene* currentScene)
{

	if (Type.Type == "Window") {

		SDL_Surface* bg = SDL_CreateRGBSurface(0, 1280, 720, 32, 0, 0, 0, 0);

		SDL_FillRect(bg, NULL, SDL_MapRGB(bg->format, 255, 255, 255));

		SDL_BlitSurface(bg, NULL, screenSurface, NULL);

		for (size_t i = 0; i < currentScene->sceneObjects.size(); i++) {
			
			SDL_Surface* optimizedSurface = NULL;

			SDL_Surface* image;
			
			image = currentScene->sceneObjects[i]->getImage();

			if (image != NULL)
			{
				//Convert surface to screen format
				optimizedSurface = SDL_ConvertSurface(image, screenSurface->format, NULL);
				if (optimizedSurface == NULL)
				{
					printf("Unable to optimize image");
				}

				SDL_Rect position;
				position.x = currentScene->sceneObjects[i]->getPos().x;
				position.y = currentScene->sceneObjects[i]->getPos().y;
				position.w = image->w;
				position.h = image->h;

				SDL_BlitSurface(optimizedSurface, NULL, screenSurface, &position);

			}

			else
				printf("There is no image");

		}

		SDL_FreeSurface(bg);

	}

	SDL_UpdateWindowSurface(window);

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