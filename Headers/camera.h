#pragma once
#include "define.h"
#include "SDL.h"

#include <algorithm>
#include <iostream>

class Camera
{
	
public:
    float zoom;
    SDL_Rect position;

    Camera(int x, int y, int w, int h);
	void Update();
    void calculateZoom();
};