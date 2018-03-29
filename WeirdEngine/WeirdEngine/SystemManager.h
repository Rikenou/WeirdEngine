#pragma once
#include "System.h"
#include "Scene.h"
#include <vector>

namespace WEIRD {

	class SystemManager
	{

	public:
		SystemManager();
		~SystemManager();

		System* getSystem(SystemType);

		bool init();
		void update();
		const void render(Scene* currentScene);
		bool shutdown();

	protected:

		std::vector<System> systems;

	};

}