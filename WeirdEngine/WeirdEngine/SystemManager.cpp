#include "stdafx.h"
#include "SystemManager.h"
#include <iostream>

using namespace WEIRD;

SystemManager::SystemManager()
{
}


SystemManager::~SystemManager()
{
}

System * WEIRD::SystemManager::getSystem(SystemType callType)
{
	
	for (size_t i = 0; i < systems.size(); i++)
		if (systems[i].getType() == callType)
			return &systems[i];

	return nullptr;

}

bool WEIRD::SystemManager::init()
{

	SystemType typeWindow;
	typeWindow.Type = "Window";

	SystemType typeInput;
	typeInput.Type = "Input";

	systems.push_back(System(typeWindow));
	systems.push_back(System(typeInput));

	for (size_t i = 0; i < systems.size(); i++)
		systems[i].init();

	return false;

}

void WEIRD::SystemManager::update()
{

	for (size_t i = 0; i < systems.size(); i++)
		systems[i].update();

}

const void WEIRD::SystemManager::render(Scene* currentScene)
{
	
	for (size_t i = 0; i < systems.size(); i++)
		systems[i].render(currentScene);

}

bool WEIRD::SystemManager::shutdown()
{

	for (size_t i = 0; i < systems.size(); i++) {

		if (systems[i].shutdown())
			return true;

	}

	return false;
}
