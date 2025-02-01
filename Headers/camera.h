#pragma once
#include "SDL.h"

class Camera
{
	
public:
	Camera(int x, int y, int w, int h);
	SDL_Rect position;
	void campsito();

};