#pragma once
#include "screen.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

class MainMenu : public Screen
{
public:
	MainMenu();
	~MainMenu();
	
	void Update() override;
	void Render() override;
private:
};