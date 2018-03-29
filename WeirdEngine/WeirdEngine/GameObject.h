#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "position.h"
#include "inputs.h"

class GameObject
{
public:
	GameObject(std::string, float x, float y);
	~GameObject();

	virtual bool init();
	virtual void update(input inputs);
	virtual const void render();
	virtual bool shutdown();

	SDL_Surface* getImage();
	const Pos getPos();

protected:

	SDL_Surface * image = nullptr;

	float x;
	float y;

};

