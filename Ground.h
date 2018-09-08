#pragma once
#include "Sprite.h"

class Ground : public Entity
{
public:
	Ground();
	~Ground();

	void initHitMap();
	void makeHole(float x, float y, float r);
	bool hitTestPoint(float x, float y);

	Sprite* image;
	bool **hitMap;
};

