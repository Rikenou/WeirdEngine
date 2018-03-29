#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{

	objects.push_back(GameObject("IMG/FaceBMP.png", 0, 0));
	
}


Scene::~Scene()
{
}

bool Scene::init()
{

	for (size_t i = 0; i < objects.size(); i++)
		sceneObjects.push_back(&objects[i]);

	return false;
}

void Scene::update(input inputs)
{

	if (inputs.w || inputs.a || inputs.s || inputs.d)
		objects[0].update(inputs);

}

const void Scene::render()
{
	return void();
}

bool Scene::shutdown()
{
	return false;
}
