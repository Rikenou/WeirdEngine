#include "stdafx.h"
#include "GameObject.h"
#include <math.h>
#include<iostream>

GameObject::GameObject()
{
	
	pathName = "";

	x = 0;
	y = 0;

	totalFrame = 1;
	freq = 0;

	init();

}

GameObject::GameObject(float Newx, float Newy)
{

	pathName = "";

	x = Newx;
	y = Newy;

	totalFrame = 1;
	freq = 0;

	init();

}

GameObject::GameObject(std::string path, std::string name, std::string ext)
{

	pathName = path + '/' + name + '.' + ext;

	x = 0;
	y = 0;

	totalFrame = 1;
	freq = 0;

	init();

}

GameObject::GameObject(std::string path, std::string name, std::string ext, float Newx, float Newy)
{

	pathName = path + '/' + name + '.' + ext;

	x = Newx;
	y = Newy;
	
	totalFrame = 1;
	freq = 0;

	init();

}

GameObject::GameObject(std::string path, std::string ext, int setTotalFrame, float setFreq, bool setAnim)
{

	pathName = path + '/' + std::to_string(1) + ext;
	p = path;
	e = ext;

	x = 0;
	y = 0;

	anim = setAnim;
	totalFrame = setTotalFrame;
	freq = setFreq;

	init();

}

GameObject::GameObject(std::string path, std::string ext, float Newx, float Newy, int setTotalFrame, float setFreq, bool setAnim)
{

	pathName = path + '/' + std::to_string(1) + '.' + ext;
	p = path;
	e = ext;

	x = Newx;
	y = Newy;

	anim = setAnim;
	totalFrame = setTotalFrame;
	freq =  setFreq;

	init();

}

GameObject::~GameObject()
{

}

bool GameObject::init()
{

	if (!anim) {

		image.push_back(IMG_Load(pathName.c_str()));
		texture.push_back(NULL);

	}

	else {
		for (int i = 1; i <= totalFrame; i++) {

			std::string temp = p + '/' + std::to_string(i) + '.' + e;
			image.push_back(IMG_Load(temp.c_str()));
			texture.push_back(NULL);

		}
	}

	frame = 0;
	timer = 0;

	scaleX = 1;
	scaleY = 1;

	return true;

}

void GameObject::update(float deltaTime)
{

	if(anim)
		updateSprite(deltaTime);

}

void GameObject::update(input inputs, float deltaTime)
{

	if (inputs.w)
		y -= 5;

	if (inputs.s)
		y += 5;

	if (inputs.a)
		x -= 5;

	if (inputs.d)
		x += 5;

	if(anim)
		updateSprite(deltaTime);

}

const void GameObject::render(SDL_Renderer* screenRender)
{

	if (image.at(0) != NULL)
	{

		if (!anim) {

			if (texture.at(0) == NULL) {
				texture.at(0) = SDL_CreateTextureFromSurface(screenRender, image.at(0));
				if (texture.at(0) == NULL)
				{
					printf("Unable to create texture");
					return;
				}
			}

			SDL_Rect position;
			position.x = x;
			position.y = y;
			position.w = image.at(0)->w;
			position.h = image.at(0)->h;

			SDL_RenderCopy(screenRender, texture.at(0), NULL, &position);

		}

		else {

			if (texture.at(frame) == NULL) {
				texture.at(frame) = SDL_CreateTextureFromSurface(screenRender, image.at(frame));
				if (texture.at(frame) == NULL)
				{
					printf("Unable to create texture");
					return;
				}

			}

			SDL_Rect position;
			position.x = x;
			position.y = y;
			position.w = image.at(frame)->w;
			position.h = image.at(frame)->h;

			SDL_RenderCopy(screenRender, texture.at(frame), NULL, &position);

		}

	}

	else
		printf("There is no image");
	
}

bool GameObject::shutdown()
{
	return false;
}

const Pos GameObject::getPos()
{
	Pos pos;
	pos.x = x;
	pos.y = y;

	return pos;
}

void GameObject::setPos(float newX, float newY)
{

	x = newX;
	y = newY;

}

void GameObject::setScale(float newXScale, float newYScale)
{

	scaleX = newXScale;
	scaleY = newYScale; 

	if (!anim) {

		SDL_Surface* scaledSurface = IMG_Load(pathName.c_str());
		scaledSurface->w = scaledSurface->w * scaleX;
		scaledSurface->h = scaledSurface->h * scaleY;

		for (int i = 0; i < image.at(0)->w; i++)
			for (int j = 0; j < image.at(0)->h; j++) {

				if (i * scaleX < scaledSurface->w && j * scaleY < scaledSurface->h) {

					Uint32 pixel;

					int bpp = image.at(0)->format->BytesPerPixel;

					Uint8 *p = (Uint8 *)image.at(0)->pixels + j * image.at(0)->pitch + i * bpp;

					bpp = scaledSurface->format->BytesPerPixel;

					int weirdX = round(i * scaleX);
					int weirdY = round(j * scaleY);

					Uint8 *scaledp = (Uint8 *)scaledSurface->pixels + weirdY * scaledSurface->pitch + weirdX * bpp;

					if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
						scaledp[0] = p[2];
						scaledp[1] = p[1];
						scaledp[2] = p[0];
					}
					else {
						scaledp[0] = p[0];
						scaledp[1] = p[1];
						scaledp[2] = p[2];
					}

					if (bpp == 4)
						scaledp[3] = p[3];

				}

			}

		SDL_FreeSurface(image.at(0));
		image.at(0) = scaledSurface;

	}

	else {

		for (int n = 0; n < totalFrame; n++) {

			SDL_Surface* scaledSurface = IMG_Load(pathName.c_str());
			scaledSurface->w = scaledSurface->w * scaleX;
			scaledSurface->h = scaledSurface->h * scaleY;

			for (int i = 0; i < image.at(n)->w; i++)
				for (int j = 0; j < image.at(n)->h; j++) {

					if (i * scaleX < scaledSurface->w && j * scaleY < scaledSurface->h) {

						Uint32 pixel;

						int bpp = image.at(n)->format->BytesPerPixel;

						Uint8 *p = (Uint8 *)image.at(n)->pixels + j * image.at(n)->pitch + i * bpp;

						bpp = scaledSurface->format->BytesPerPixel;

						int weirdX = round(i * scaleX);
						int weirdY = round(j * scaleY);

						Uint8 *scaledp = (Uint8 *)scaledSurface->pixels + weirdY * scaledSurface->pitch + weirdX * bpp;

						if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
							scaledp[0] = p[2];
							scaledp[1] = p[1];
							scaledp[2] = p[0];
						}
						else {
							scaledp[0] = p[0];
							scaledp[1] = p[1];
							scaledp[2] = p[2];
						}

						if (bpp == 4)
							scaledp[3] = p[3];

					}

				}

			SDL_FreeSurface(image.at(n));
			image.at(n) = scaledSurface;

		}

	}

}

void GameObject::updateSprite(float deltaTime)
{
	//std::cout << timer << std::endl;
	if (timer >= freq) {

		timer = 0;

		if (frame + 1 < totalFrame)
			frame += 1;

		else
			frame = 0;

	}

	timer += deltaTime;
	std::cout << deltaTime << std::endl;
}