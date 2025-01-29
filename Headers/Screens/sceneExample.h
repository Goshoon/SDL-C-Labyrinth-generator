#pragma once
#include "mazeGenerator.h"
#include "screen.h"
#include "player.h"

#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

class sceneExample : public Screen
{
public:
	sceneExample();
	~sceneExample();

	MazeGenerator* maze = new MazeGenerator();
	bool generationWindow;
	
	void Update() override;
	void Render() override;
private:
	int xoffset, yoffset, previousMouseX, previousMouseY;
	Player* player;
};