#pragma once
#include "Entity.h"
#include "Animation.h"

class Mover : public Entity
{
public:
	Mover();
	~Mover();

	Animation *animation;
	Sprite *sprite;
	bool isRemoved;

	void InitAnimation(string path, int frame, float speed);
	void InitSprite(string path);
};

