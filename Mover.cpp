#include "DXUT.h"
#include "Mover.h"
#include "World.h"

Mover::Mover()
{
}


Mover::~Mover()
{
}

void Mover::InitAnimation(string path, int frame, float speed)
{
	animation = new Animation(path, frame, speed, true);
	rect = animation->rect;
	addChild(animation);
}

void Mover::InitSprite(string path)
{
	sprite = new Sprite(path);
	rect = sprite->rect;
	setRotationCenter();
	addChild(sprite);
}