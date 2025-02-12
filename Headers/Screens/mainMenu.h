#pragma once
#include "sceneExample.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include <memory>

extern std::unique_ptr<Screen> currentScreen;

class MainMenu : public Screen
{
public:
	MainMenu();
	~MainMenu();
	
	void Update() override;
	void Render() override;
private:
};