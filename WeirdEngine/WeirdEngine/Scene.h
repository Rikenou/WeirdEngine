#pragma once
#include <vector>
#include "inputs.h"
#include "GameObject.h"

class Scene
{
public:
	Scene();
	~Scene();

	virtual bool init();
	virtual void update(input inputs);
	virtual const void render();
	virtual bool shutdown();

	std::vector<GameObject*>sceneObjects;

protected:

	std::vector<GameObject>objects;

};

