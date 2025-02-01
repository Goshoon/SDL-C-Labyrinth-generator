#include "contreras.h"
#include <algorithm>
#include <iostream>

Contreras::Contreras() // Contructor por defecto
{
	position.x = 0;
	position.y = 0;
	position.w = 12;
	position.h = 12;
}

Contreras::Contreras(int x, int y) // Constructor a posicion
{
	position.x = x;
	position.y = y;
	position.w = 12;
	position.h = 12;
}

void Contreras::Update()
{



}

void Contreras::Render(Camera* camera) // Posicion en pantalla = posicion + posicion_camara
{
	SDL_Color outlineColor = { 255, 0, 0, 255 }; 
	app->DrawRectangle(position.x + camera->position.x, position.y + camera->position.y, 24, 24, outlineColor);
}
