#pragma once
#include <memory>
#include "SDL.h"
#include "SDL_Image.h"
#include "SDL_ttf.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "application.h"
extern std::unique_ptr<Application> app;
extern TTF_Font* font;

#ifndef CONTEXT_H
#define CONTEXT_H

void Inititialize();
void Quit();

#endif
