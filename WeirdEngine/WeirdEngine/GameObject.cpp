#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(std::string path, float Newx, float Newy)
{

	image = IMG_Load(path.c_str());

	x = Newx;
	y = Newy;

}


GameObject::~GameObject()
{

}

bool GameObject::init()
{
	return false;
}

void GameObject::update(input inputs)
{

	if (inputs.w)
		y -= 1;

	if (inputs.s)
		y += 1;

	if (inputs.a)
		x -= 1;

	if (inputs.d)
		x += 1;

}

const void GameObject::render()
{
	return void();
}

bool GameObject::shutdown()
{
	return false;
}

SDL_Surface * GameObject::getImage()
{
	return image;
}

const Pos GameObject::getPos()
{
	Pos pos;
	pos.x = x;
	pos.y = y;

	return pos;
}
