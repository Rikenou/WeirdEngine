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
	GameObject();
	GameObject(std::string path, std::string name, std::string ext);
	GameObject(float x, float y);
	GameObject(std::string path, std::string name, std::string ext, float x, float y);
	GameObject(std::string path, std::string ext, int setTotalFrame, float freq, bool setAnim);
	GameObject(std::string path, std::string ext, float x, float y, int setTotalFrame, float freq, bool setAnim);
	~GameObject();

	virtual bool init();
	virtual void update(float deltaTime);
	virtual void update(input inputs, float deltaTime);
	virtual const void render(SDL_Renderer*);
	virtual bool shutdown();

	const Pos getPos();
	void setPos(float newX, float newY);

	float scaleX;
	float scaleY;

	void setScale(float newXScale, float newYScale);

protected:

	std::string pathName;
	std::string p;
	std::string e;

	std::vector<SDL_Surface*> image;
	std::vector<SDL_Texture*> texture;

	float width;
	float height;

	float x;
	float y;

	bool anim = false;

	void updateSprite(float deltaTime);
	float timer;
	int frame;
	int totalFrame;
	int freq;

};

