#include "DXUT.h"
#include "Player.h"
#include "World.h"
#include "GameScene.h"

Player::Player()
{
	InitSprite("image/player.png");
	leftTop = Vec2(0, 0);
	rightTop = Vec2(sprite->texture->info.Width, 0);
	leftBottom = Vec2(0, sprite->texture->info.Height);
	rightBottom = Vec2(sprite->texture->info.Width, sprite->texture->info.Height);
	rotation = 0;
}

Player::~Player()
{
}

void Player::update(float dt)
{
	int climbSpeed = 2;
	int moveSpeed = 3;
	bool canLeftMove = true, canRightMove = true;

	GameScene* inGame = dynamic_cast<GameScene*>(world.currentScene);

	//Trep
	if (inGame->getGround()->hitTestPoint(pos.x + leftTop.x, pos.y + leftTop.y))
	{
		canLeftMove = false;
		printf("asfdasfd");
	}
	if (inGame->getGround()->hitTestPoint(pos.x + rightTop.x, pos.y + rightTop.y))
	{
		canRightMove = false;
		printf("asfdasfd");
	}

	if ((world.getKeyState(VK_RIGHT) == 2) && canRightMove)
	{
		pos.x += moveSpeed;
	}
	else if (world.getKeyState(VK_LEFT) == 2 && canLeftMove)
	{
		pos.x -= moveSpeed;
	}


	//Down
	if (!inGame->getGround()->hitTestPoint(pos.x + leftBottom.x, pos.y + leftBottom.y))
	{
		printf("LDown\n");
		rotation = angle(leftBottom, rightBottom);
		leftBottom.y += climbSpeed;
		rightBottom.y -= climbSpeed;
		pos.y += climbSpeed;
	}
	if (!inGame->getGround()->hitTestPoint(pos.x + rightBottom.x, pos.y + rightBottom.y))
	{
		printf("RDown\n");
		rotation = angle(leftBottom, rightBottom);
		rightBottom.y += climbSpeed;
		leftBottom.y -= climbSpeed;
		pos.y += climbSpeed;
	}

	//Up
	if (inGame->getGround()->hitTestPoint(pos.x + leftBottom.x, pos.y + leftBottom.y))
	{
		printf("LUp\n");
		rightBottom.y += climbSpeed;
		leftBottom.y -= climbSpeed;
		pos.y -= climbSpeed;
	}
	if (inGame->getGround()->hitTestPoint(pos.x + rightBottom.x, pos.y + rightBottom.y))
	{
		printf("RUp\n");
		rightBottom.y -= climbSpeed;
		leftBottom.y += climbSpeed;
		pos.y -= climbSpeed;
	}

	pos.x = clamp(pos.x, 4, 3045);
}
