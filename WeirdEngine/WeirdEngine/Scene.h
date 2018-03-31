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
	virtual void update(input inputs, float deltaTime);
	virtual const void render(SDL_Renderer*);
	virtual bool shutdown();

protected:

	std::vector<GameObject>objects;

};

