#include "Wall.h"

void Wall::spriteInit()
{
	//wallsprites[0]->LoadFromFile("wood.png");
	//ceilingsprites[0]->LoadFromFile("graystone.png");
	//floorsprites[0]->LoadFromFile("bluestone.png");
	wallS.Load("wood.png");
	ceilS.Load("graystone.png");
	floorS.Load("bluestone.png");
}

void Wall::renderWallProjection(olc::PixelGameEngine* pge, Player& player, Ray rays[])
{
	olc::Pixel P;
	int nHalfWindowHeight = WINDOW_HEIGHT / 2;
	float fPlayerH = TILE_SIZE / 2.0f;
	float fFoV = 60.0f;
	float fAngleStep = fFoV / (float)NUM_RAYS;
	int texture_width = wallS.Sprite()->width;
	int texture_height = wallS.Sprite()->height;
	for (int x = 0; x < NUM_RAYS; x++) {
		float prepDistance = rays[x].distance * cos(rays[x].rayAngle - player.rotationAngle);

		float projectedWallHeight = (TILE_SIZE / prepDistance * Dist_PROJ_PLANE);

		int wallStripHeight = (int)projectedWallHeight;
		int wallTopPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);

		int wallBottomPixel = (WINDOW_HEIGHT / 2) + (wallStripHeight / 2);

		wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
		wallBottomPixel = wallBottomPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottomPixel;



		int textureOffSetX;
		if (rays[x].wasHitVertical) {
			textureOffSetX = (int)rays[x].wallHitY % TILE_SIZE;

		}
		else {

			textureOffSetX = (int)rays[x].wallHitX % TILE_SIZE;
		}

		//get correct texture id for map content
		//int texNum = rays[x].wallHitContent - 1;




		float fViewAngle = (float)(x - (NUM_RAYS / 2)) * fAngleStep;
		float fCurAngle = (player.rotationAngle * 180.0f / PI) + fViewAngle;
		float fPlayerX = player.x;
		float fPlayerY = player.y;
		float fCosCurAngle = cos(fCurAngle * PI / 180.0f);
		float fSinCurAngle = sin(fCurAngle * PI / 180.0f);
		float fCosViewAngle = cos(fViewAngle * PI / 180.0f);

		for (int y = 0; y < WINDOW_HEIGHT; y++)
		{
			if (y < wallTopPixel)
			{

				float fFloorProjDistance = ((fPlayerH / (float)(nHalfWindowHeight - y)) * Dist_PROJ_PLANE) / fCosViewAngle;
				float fFloorProjX = fPlayerX + fFloorProjDistance * fCosCurAngle;
				float fFloorProjY = fPlayerY + fFloorProjDistance * fSinCurAngle;
				int nSampleX = (int(fFloorProjX) % TILE_SIZE) * (texture_width / float(TILE_SIZE));
				int nSampleY = (int(fFloorProjY) % TILE_SIZE) * (texture_height / float(TILE_SIZE));

				P = ceilS.Sprite()->GetPixel(nSampleX, nSampleY);
				pge->Draw(x, y, P);

			}
			else if (y > wallBottomPixel)
			{

				float fFloorProjDistance = ((fPlayerH / (float)(y - nHalfWindowHeight)) * Dist_PROJ_PLANE) / fCosViewAngle;
				float fFloorProjX = fPlayerX + fFloorProjDistance * fCosCurAngle;
				float fFloorProjY = fPlayerY + fFloorProjDistance * fSinCurAngle;
				int nSampleX = (int(fFloorProjX) % TILE_SIZE) * (texture_width / float(TILE_SIZE));
				int nSampleY = (int(fFloorProjY) % TILE_SIZE) * (texture_height / float(TILE_SIZE));

				P = floorS.Sprite()->GetPixel(nSampleX, nSampleY);
				pge->Draw(x, y, P);

			}
			else
			{
				int distanceFromTop = y + (wallStripHeight / 2) - (WINDOW_HEIGHT / 2);
				int textureOffSetY = distanceFromTop * ((float)texture_height / wallStripHeight);


				P = wallS.Sprite()->GetPixel(textureOffSetX, textureOffSetY);
				pge->Draw(x, y, P);

			}
		}
	}

}