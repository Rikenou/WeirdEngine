#include "stdafx.h"
#include "Manager.h"
#include <iostream>
#include "SystemType.h"

using namespace WEIRD;

Manager::Manager()
{
}


Manager::~Manager()
{
}

bool WEIRD::Manager::init() 
{

	systemmanager.init();
	scenemanager.init();

	return false;

}

void WEIRD::Manager::update(float deltaTime)
{

	systemmanager.update(deltaTime);

	SystemType type;
	type.Type = "Input";
	scenemanager.update(systemmanager.getSystem(type)->inputs, deltaTime);

}

const void WEIRD::Manager::render()
{

	systemmanager.render(scenemanager.currentScene);
	scenemanager.render();

}

bool WEIRD::Manager::shutdown()
{

	return systemmanager.shutdown();

}
