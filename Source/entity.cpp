#include "entity.h"

Entity::Entity()
{
	x = 0;
	y = 0;
}

Entity::Entity(int _x, int _y)
{
	SDL_Point _spriteDimentions;
	SDL_QueryTexture(sprite, NULL, NULL, &_spriteDimentions.x, &_spriteDimentions.y);

	x = _x;
	y = _y;

	src.x = 0;
	src.y = 0;
	src.w = _spriteDimentions.x;
	src.h = _spriteDimentions.y;

	dst.x = _x;
	dst.y = _y;
	dst.w = _spriteDimentions.x;
	dst.h = _spriteDimentions.y;
}

void Entity::Update()
{
	dst.x = x;
	dst.y = y;
	
	x++;
}

void Entity::Draw()
{
	SDL_RenderCopy(app->renderer, sprite, NULL, &dst);
}