#pragma once
#include "SceneManager.h"
#include "SystemManager.h"

namespace WEIRD {

	class Manager
	{

	public:
		Manager();
		~Manager();

		bool init();
		void update(float deltaTime);
		const void render();
		bool shutdown();

	protected:

		SceneManager scenemanager;
		SystemManager systemmanager;

	};

}