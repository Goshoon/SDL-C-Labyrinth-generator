#pragma once
#include "mazeGenerator.h"
#include "screen.h"
#include "player.h"
#include "contreras.h"
#include "math.h"
#include <chrono>
#include <thread>  // Para usar std::this_thread::sleep_for
#include <memory>

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
	int previousMouseX, previousMouseY;
	std::unique_ptr<MazeGenerator> maze = std::make_unique<MazeGenerator>();
	std::unique_ptr<Player> player = std::make_unique<Player>(32, CELL_HEIGHT*MATRIX_DIMENSION);
	std::unique_ptr<Camera> camera = std::make_unique<Camera>(32, CELL_HEIGHT*MATRIX_DIMENSION, 640, 480);
	std::unique_ptr<Contreras> contreras = std::make_unique<Contreras>(64, 64);
};