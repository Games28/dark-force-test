#define OLC_PGE_APPLICATION

#include "olcPixelGameEngine.h"
#include "Defs.h"
#include "Map.h"
#include "player.h"
#include "Ray.h"
#include "Wall.h"

class dark_force : public olc::PixelGameEngine
{
public:
	dark_force()
	{
		sAppName = "dark force game";
	}

public:
	Map theMap;
	Player player;
	RayCast rays;
	Wall walls;
public:


public:
	bool OnUserCreate() override
	{
		theMap.theMap;
		player.Init();
		rays.castAllRays(player, theMap);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);
		player.Controls(this);
		player.movePlayer(fElapsedTime);
		walls.renderWallProjection(this, player, rays.ray);
		theMap.renderMap(*this);
		player.renderPlayer(this);
		rays.castAllRays(player, theMap);
		rays.renderRays(this, player);
		return true;
	}
};


int main()
{
	dark_force game;
	if (game.Construct(WINDOW_WIDTH, WINDOW_HEIGHT, 1, 1))
	{
		game.Start();
	}

	return 0;
}