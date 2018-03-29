#include "stdafx.h"
#include "SceneManager.h"
#include <iostream>

SceneManager::SceneManager()
{

	scene1 = Scene();

}


SceneManager::~SceneManager()
{
}

bool SceneManager::init()
{
	scenes.push_back(scene1);
	currentScene = &scenes[0];

	currentScene->init();

	return false;
}

void SceneManager::update(input inputs)
{
	//std::cout << inputs.w << std::endl;
	if(currentScene != nullptr)
		currentScene->update(inputs);

}

const void SceneManager::render()
{

}

bool SceneManager::shutdown()
{



	return false;
}
