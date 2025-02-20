#include "entity.h"

Entity::Entity()
{
	position.x = 0;
	position.y = 0;
	position.w = 32;
	position.h = 32;
	sprite.x = 0;
	sprite.y = 0;
	sprite.w = 32;
	sprite.h = 32;
	frame = 0;
	maxframes = 0;
	//offset.x = 0;
	//offset.y = 0;
	angle = 0.0;
	flip = SDL_FLIP_NONE;
	
	spritesheet = nullptr;
}

Entity::Entity(int x, int y)
{
	position.x = x;
	position.y = y;
	position.w = 32;
	position.h = 32;
	sprite.x = 0;
	sprite.y = 0;
	sprite.w = 32;
	sprite.h = 32;
	frame = 0;
	maxframes = 0;
	//offset.x = 0;
	//offset.y = 0;
	angle = 0.0;
	flip = SDL_FLIP_NONE;

	spritesheet = nullptr;
}

void Entity::Update()
{

} 

void Entity::Render()
{

}

void Entity::Animate()
{
	sprite.x = sprite.w * frame;
	frame++;
	if (frame > maxframes-1)
		frame = 0;
}