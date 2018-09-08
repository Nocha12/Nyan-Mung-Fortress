#pragma once
#include "Scene.h"
#include "Ground.h"
#include "Player.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	Ground *ground;
	Player *player;
	
	void update(float dt) override;
	Ground *getGround()
	{
		return ground;
	}
};




