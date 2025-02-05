#include "button.h"

Button::Button(int x, int y, int w, int h){

    position.x = x;
    position.y = y;
    position.w = w;
    position.h = h;

}

void Button::Render(Camera& camera) // Posicion en pantalla = posicion + posicion_camara
{
	SDL_Color outlineColor = { 255, 0, 0, 255 }; 
	app->DrawRectangle(camera, position.x, position.y, 24, 24, outlineColor);
}