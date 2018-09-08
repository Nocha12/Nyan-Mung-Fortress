#include "DXUT.h"
#include "GameScene.h"
#include "World.h"

GameScene::GameScene()
{
	addChild(ground = new Ground());
	addChild(player = new Player());
	player->pos = Vec2(300, 455);
	follow(player, Vec2(640, 495));
}

GameScene::~GameScene()
{
}

void GameScene::update(float dt)
{
	Scene::update(dt);

	if ((world.getKeyState('Z') == 1))
	{
		ground->makeHole(random(0, 1280), random(0, 720), 50);
	}
	if ((world.getKeyState('x') == 1 || world.getKeyState('X') == 1))
	{
		ground->makeHole(random(0, 1280), random(0, 720), 60);
	}
	if ((world.getKeyState('c') == 1 || world.getKeyState('C') == 1))
	{
		ground->makeHole(random(0, 1280), random(0, 720), 100);
	}
}
