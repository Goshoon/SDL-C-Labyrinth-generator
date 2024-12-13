#pragma once
#include <memory>
#include "application.h"
using std::unique_ptr;

extern unique_ptr<Application> app;

class Entity
{
public:
	Entity();
	Entity(int _x, int _y);

	int x, y;
	unsigned short frame, xOffset, yOffset;
	bool animated;

	SDL_Texture* sprite;

	SDL_Rect dst; // Espacio en el area de juego

	void Update();
	void Draw();
private:
	SDL_Rect src; // Animacion
};