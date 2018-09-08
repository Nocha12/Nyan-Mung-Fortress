#include "DXUT.h"
#include "Ground.h"
#include "World.h"

Ground::Ground()
{
	image = new Sprite("image/Background/ground_1.png");
	addChild(image);
	initHitMap();
}

Ground::~Ground()
{
}

//게임이 처음시작할때 충돌맵을 1대1비율로 bool배열에 담기
void Ground::initHitMap()
{
	printf("init\n");
	rect = image->rect;
	hitMap = new bool*[image->texture->info.Height];
	for (int i = 0; i < image->texture->info.Height; i++)
		hitMap[i] = new bool[image->texture->info.Width];
	DWORD* data;
	D3DLOCKED_RECT lockRect;
	LPDIRECT3DSURFACE9 surface;
	image->texture->d3dTexture->GetSurfaceLevel(0, &surface);
	surface->LockRect(&lockRect, 0, 0);
	data = (DWORD*)lockRect.pBits;
	for (int i = 0; i < image->texture->info.Height; i++)
	{
		for (int j = 0; j <image->texture->info.Width; j++)
		{
			int index = i*lockRect.Pitch / 4 + j;

			if (data[index] >> 24 == 0x00)
			//if (data[index] == D3DXCOLOR(0, 0, 0, 0))
				hitMap[i][j] = false;
			else
				hitMap[i][j] = true;
		}
	}
	surface->UnlockRect();
	SAFE_RELEASE(surface);
}

//총이 땅에맞앗을때 구멍을 생성하는 함수
void Ground::makeHole(float x, float y, float r)
{
	x -= pos.x;
	y -= pos.y;
	DWORD* data;
	D3DLOCKED_RECT lockRect;
	LPDIRECT3DSURFACE9 surface;
	image->texture->d3dTexture->GetSurfaceLevel(0, &surface);
	surface->LockRect(&lockRect, 0, 0);
	data = (DWORD*)lockRect.pBits;
	for (int i = y - r; i < y + r; i++)
	{
		for (int j = x - r; j < x + r; j++)
		{
			if (j >= 0 && i >= 0 && j < image->texture->info.Width && i < image->texture->info.Height)
			{
				if (sqrt(pow(x - j, 2) + pow(y - i, 2)) <= r&&hitMap[i][j])
				{
					int index = i*lockRect.Pitch / 4 + j;
					data[index] = 0x00FFFFFF;
					hitMap[i][j] = false;
				}
			}
		}
	}
	surface->UnlockRect();
	SAFE_RELEASE(surface);
}

//x,y좌표가 땅인지 반환해주는 함수
bool Ground::hitTestPoint(float x, float y)
{
	x -= this->pos.x;
	y -= this->pos.y;

	if ((x > 0 && y > 0) && x < image->texture->info.Width && y < image->texture->info.Height)
		return this->hitMap[(int)y][(int)x];
	else
		return false;
}