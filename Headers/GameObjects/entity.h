#pragma once
#include "SDL_image.h"

class Entity
{
public:
	Entity();
	short frame;
	SDL_Texture* spritesheet;
	SDL_Rect position, sprite;

	void Update();
	void Render();
};