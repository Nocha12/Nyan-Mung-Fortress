#pragma once
#include "Mover.h"
class Bullet : public Mover
{
public:
	Bullet();
	~Bullet();

	void update(float dt) override;
};

