#pragma once
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "application.h"

#ifndef CONTEXT_H
#define CONTEXT_H

void Inititialize();
void LoadTextures();
void Quit();

#endif
