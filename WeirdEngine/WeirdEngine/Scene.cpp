#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{

	objects.push_back(GameObject("IMG/Face", "FaceBMP", "png", 0, 0));

	objects.push_back(GameObject("IMG/transTest", "transTest", "png", 250, 0));
	objects.at(1).setScale(0.5, 0.5);

	objects.push_back(GameObject("IMG/animTest", "png", 850, 0, 16, 1.5, true));
	objects.at(2).setScale(0.2, 0.2);

}


Scene::~Scene()
{
}

bool Scene::init()
{

	return false;
}

void Scene::update(input inputs, float deltaTime)
{

	if (objects.size() > 0) {

		if (inputs.w || inputs.a || inputs.s || inputs.d)
			objects[0].update(inputs, deltaTime);

		if (objects.size() > 1) {

			for (size_t i = 1; i < objects.size(); i++)
				objects[i].update(deltaTime);

		}

	}

}

const void Scene::render(SDL_Renderer* screenRender)
{

	for (size_t i = 0; i < objects.size(); i++) {

		objects[i].render(screenRender);

	}

}

bool Scene::shutdown()
{
	return false;
}
