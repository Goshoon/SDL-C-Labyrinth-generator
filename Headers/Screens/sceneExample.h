#pragma once
#include <memory>
#include "mazeGenerator.h"
#include "screen.h"
#include "player.h"
#include "math.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

class sceneExample : public Screen
{
public:
	sceneExample();
	~sceneExample();

	bool generationWindow;
	
	void Update() override;
	void Render() override;
private:
	int xoffset, yoffset, previousMouseX, previousMouseY;
	std::unique_ptr<MazeGenerator> maze = std::make_unique<MazeGenerator>();
	std::unique_ptr<Player> player = std::make_unique<Player>(32, 32);
	std::unique_ptr<Camera> camera = std::make_unique<Camera>(0, 0, 640, 480);
};