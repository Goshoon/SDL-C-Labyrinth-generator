#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

#include "define.h"

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

extern TTF_Font* font;

class Application
{
public:
	Application();
	~Application();
	SDL_Window* window;
	SDL_Renderer* renderer;

	std::unordered_map<std::string, SDL_Texture*> images;

	bool done = false;
	bool mbLeft = false;
	bool mbRight = false;
	bool space = false;
	int mouseX = 0;
	int mouseY = 0;

	void Display();
	void DrawEverything();
	void Input();
	void AddTexture(const std::string& ID, const char* fileDir);
	SDL_Texture* GetTexture(const std::string& ID);
	void DrawRectangle(int x, int y, int width, int height, SDL_Color color);
	void RenderImage( SDL_Texture* image, int x, int y );
	void RenderImage( SDL_Texture* image, int x, int y, int w, int h );
	void RenderText(const char* toRenderText);
private:
	void InputReleased(SDL_Event* event);
	void InputPressed(SDL_Event* event);
};