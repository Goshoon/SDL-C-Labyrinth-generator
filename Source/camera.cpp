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
	position.x = std::clamp(position.x, -position.w, widthLimit + position.w);
	position.y = std::clamp(-position.y, position.h, heightLimit - position.h);
	std::cout << "widthLimit" << " : " << widthLimit << std::endl;
	std::cout << "heightLimit" << " : " << heightLimit << std::endl;
	std::cout << "heightLimit-position.h" << " : " << heightLimit-position.h << std::endl;
	std::cout << "widthLimit-position.w" << " : " << widthLimit-position.w << std::endl;
	std::cout << "position.w" << " : " << position.w << std::endl;
	std::cout << "position.h" << " : " << position.h << std::endl;
	//std::cout << position.y << "\n";
}
