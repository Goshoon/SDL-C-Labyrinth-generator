#include "camera.h"

Camera::Camera(int x, int y, int w, int h)
{

	position.x = x;
	position.y = y;
	position.w = w;
	position.h = h;
	
	Update();
}

void Camera::Update()
{
	int widthLimit = CELL_WIDTH * MATRIX_DIMENSION;
	int heightLimit = CELL_HEIGHT * MATRIX_DIMENSION;
	position.x = std::clamp(position.x, -position.w, widthLimit-position.w);
	position.y = std::clamp(position.y, -position.h / 2, heightLimit-position.h);
	//std::cout << position.y << "\n";
}
