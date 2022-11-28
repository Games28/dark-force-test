#ifndef WALL_H
#define WALL_H
#include "olcPixelGameEngine.h"
#include "Defs.h"
#include "player.h"
#include "Ray.h"


class Wall
{
public:
	Wall() = default;
	void spriteInit();
public:
	void renderWallProjection(olc::PixelGameEngine* pge, Player& player, Ray rays[]);
	olc::Sprite* wallsprites[10];
	olc::Sprite* floorsprites[10];
	olc::Sprite* ceilingsprites[10];
	olc::Renderable wallS;
	olc::Renderable ceilS;
	olc::Renderable floorS;
};

#endif // !WALL_H



