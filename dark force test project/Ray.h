#ifndef RAY_H
#define RAY_H
#include "olcPixelGameEngine.h"
#include "Defs.h"
#include "player.h"
#include "Map.h"

struct Ray
{
	float rayAngle;
	float wallHitX;
	float wallHitY;
	float distance;
	bool wasHitVertical;
    int wallHitContent;
};


class RayCast
{
public:
	RayCast() = default;
	void normalizeAngle(float* angle);
	float distanceBetweenPoints(float x1, float y1, float x2, float y2);
	void castRay(float rayAngle, int stripID, Player &player, Map& map);
	void castAllRays(Player& player, Map& map);
	void renderRays(olc::PixelGameEngine* pge, Player& player);
public:
	Ray ray[NUM_RAYS];
public:
	struct Ray
	{
		float rayAngle;
		float wallHitX;
		float wallHitY;
		float distance;
		bool wasHitVertical;
		int wallHitContent;
	};
};
#endif // !RAY_H


