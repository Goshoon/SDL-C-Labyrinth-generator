#pragma once
#include "mazeGenerator.h"
#include "screen.h"

class sceneExample : public Screen
{
public:
	sceneExample();
	~sceneExample();

	MazeGenerator* maze = new MazeGenerator();
	
	void Update() override;
	void Render() override;
private:
};