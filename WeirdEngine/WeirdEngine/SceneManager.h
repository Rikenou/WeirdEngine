#pragma once
#include <vector>
#include "inputs.h"
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	bool init();
	void update(input inputs);
	const void render();
	bool shutdown();

	Scene* currentScene = nullptr;

protected:

	std::vector<Scene> scenes;

	Scene scene1;

};

