#pragma once
#include "Mover.h"

class Player : public Mover
{
public:
	Player();
	~Player();

	Vec2 leftTop, rightTop;
	Vec2 leftBottom, rightBottom;

	void update(float dt) override;
};