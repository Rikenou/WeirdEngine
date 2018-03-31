#pragma once
#include "SystemType.h"
#include "Scene.h"
#include "inputs.h"
#include <SDL.h>
#undef main

namespace WEIRD {

	class System
	{
	public:
		System(SystemType Type);
		~System();

		bool init();
		void update(float deltaTime);
		void render(Scene* currentScene);
		bool shutdown();

		SDL_Event event;

		SystemType getType();

		input inputs;

	protected:
		SystemType Type;
		bool KMS = false;

		void events();

		SDL_Window* window = NULL; 
		SDL_Renderer* screenRender = NULL;

	};

}