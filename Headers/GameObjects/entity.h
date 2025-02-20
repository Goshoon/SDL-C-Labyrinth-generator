#pragma once
#include "SDL_image.h"

class Entity
{
public:
	Entity();
	Entity(int x, int y);
	
	int frame, maxframes;
	double angle;
	SDL_RendererFlip flip;
	SDL_Point offset;
	SDL_Texture* spritesheet;
	SDL_Rect position, sprite;

	void Update();
	void Render();
	void Animate();
};