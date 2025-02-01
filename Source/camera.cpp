#include "camera.h"
#include <algorithm>
#include <iostream>

Camera::Camera(int x, int y, int w, int h)
{

	position.x = x;
	position.y = y;
	position.w = w;
	position.h = h;
	
	campsito();
}

void Camera::campsito()
{

	position.x = std::clamp((position.x), -600, 200);
	position.y = std::clamp((position.y),  -600, 200);
	std::cout<<position.x<< " Camera_X:Camera_Y " <<position.y << "\n";

}