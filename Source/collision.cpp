#include "collision.h"
#include <iostream>
bool Collide(SDL_Rect& rectA, SDL_Rect& rectB)
{
	/*
	std::cout << "X: " << rectA.x << " : " << rectB.x << "\n";
	std::cout << "Y: " << rectA.y << " : " << rectB.y << "\n";
	std::cout << "W: " << rectA.w << " : " << rectB.w << "\n";
	std::cout << "H: " << rectA.h << " : " << rectB.h << "\n";
*/
	return rectA.x < rectB.x + rectB.w
	&& rectA.x + rectA.w > rectB.x
	&& rectA.y < rectB.y + rectB.h
	&& rectA.y + rectA.h > rectB.y;
}