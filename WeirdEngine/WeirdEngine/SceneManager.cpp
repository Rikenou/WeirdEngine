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

void SceneManager::update(input inputs, float deltaTime)
{

	if(currentScene != nullptr)
		currentScene->update(inputs, deltaTime);

}

const void SceneManager::render()
{

}

bool SceneManager::shutdown()
{



	return false;
}
