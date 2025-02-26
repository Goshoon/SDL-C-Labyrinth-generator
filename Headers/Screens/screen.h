#pragma once
#include <iostream>
#include <memory>
#include "application.h"

#include "SDL.h"
#include "SDL_Image.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

class Screen
{
public:
	Screen();
	~Screen();

	virtual void Update();
	virtual void Render();
};

/*
	Interfaz de todas las "escenas en el programa"
*/