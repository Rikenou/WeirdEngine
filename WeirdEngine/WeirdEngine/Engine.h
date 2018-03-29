#pragma once
#include <memory>
#include "Manager.h"
#include "SystemManager.h"

namespace WEIRD {

	class Engine
	{
	public:
		Engine();
		~Engine();

		static Engine* startEngine();

		int init();
		int Run();

	protected:

		static std::unique_ptr<Engine>engine;
		Manager manager;

		bool isRunning = false;

		int framerate;

	protected:

		bool W;
		bool A;
		bool S;
		bool D;

	};

}