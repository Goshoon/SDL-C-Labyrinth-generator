#pragma once
#include "SDL.h"
#include <algorithm>
#include <iostream>

class Camera
{
	
public:
    float zoom;
    SDL_Rect position;

    Camera(int x, int y, int w, int h);
	void campsito();
    void calculateZoom();
};