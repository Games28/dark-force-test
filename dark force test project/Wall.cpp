#include "Wall.h"

void Wall::spriteInit()
{
	wallsprites[0]->LoadFromFile("wood.png");
	ceilingsprites[0]->LoadFromFile("graystone.png");
	floorsprites[0]->LoadFromFile("bluestone.png");
	wallS.Load("wood.png");
	ceilS.Load("graystone.png");
	floorS.Load("bluestone.png");
}

void Wall::renderWallProjection(olc::PixelGameEngine* pge, Player& player,Ray rays[])
{
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

		int texture_width = wallsprites[0]->width;
		int texture_height = wallsprites[0]->height;



		for (int y = 0; y < WINDOW_HEIGHT; y++)
		{
			if (y < wallTopPixel)
			{
				int nHalfWindowHeight = WINDOW_HEIGHT / 2;
				float fPlayerH = TILE_SIZE / 2.0f;
				float fFoV = 60.0f;
				float fAngleStep = fFoV / (float)NUM_RAYS;
				float fViewAngle = (float)(x - (NUM_RAYS / 2)) * fAngleStep;
				float fCurAngle = (player.rotationAngle * 180.0f / PI) + fViewAngle;
				float fPlayerX = player.x;
				float fPlayerY = player.y;
				float fFloorProjDistance = ((fPlayerH / (float)(nHalfWindowHeight - y)) * Dist_PROJ_PLANE) / cos(fViewAngle * PI / 180.0f);
				float fFloorProjX = fPlayerX + fFloorProjDistance * cos(fCurAngle * PI / 180.0f);
				float fFloorProjY = fPlayerY + fFloorProjDistance * sin(fCurAngle * PI / 180.0f);
				int nSampleX = (int)(fFloorProjX) % TILE_SIZE;
				int nSampleY = (int)(fFloorProjY) % TILE_SIZE;
				//color_t texelColor = wallTextures[4].texture_buffer[(texture_width * nSampleY) + nSampleX];
				olc::Pixel P = ceilS.Sprite()->Sample(nSampleX, nSampleY);
				pge->Draw(x, y, P);
				//drawPixel(x, y, texelColor);
				//drawPixel(x, y, 0xff444444);
			}
			else if (y > wallBottomPixel)
			{
				int nHalfWindowHeight = WINDOW_HEIGHT / 2;
				float fPlayerH = TILE_SIZE / 2.0f;
				float fFoV = 60.0f;
				float fAngleStep = fFoV / (float)NUM_RAYS;
				float fViewAngle = (float)(x - (NUM_RAYS / 2)) * fAngleStep;
				float fCurAngle = (player.rotationAngle * (180.0f / PI)) + fViewAngle;
				float fPlayerX = player.x;
				float fPlayerY = player.y;
				float fFloorProjDistance = ((fPlayerH / (float)(y - nHalfWindowHeight)) * Dist_PROJ_PLANE) / cos(fViewAngle * PI / 180.0f);
				float fFloorProjX = fPlayerX + fFloorProjDistance * cos(fCurAngle * PI / 180.0f);
				float fFloorProjY = fPlayerY + fFloorProjDistance * sin(fCurAngle * PI / 180.0f);
				int nSampleX = (int)(fFloorProjX) % TILE_SIZE;
				int nSampleY = (int)(fFloorProjY) % TILE_SIZE;
				//color_t texelColor = wallTextures[5].texture_buffer[(nSampleY * texture_width) + nSampleX];
				olc::Pixel P = floorS.Sprite()->Sample(nSampleX, nSampleY);
				pge->Draw(x, y, P);
				//drawPixel(x, y, texelColor);
				//drawPixel(x, y, 0xff777777);
			}
			else
			{
				int distanceFromTop = y + (wallStripHeight / 2) - (WINDOW_HEIGHT / 2);
				int textureOffSetY = distanceFromTop * ((float)texture_height / wallStripHeight);

				//color_t texelColor = wallTextures[texNum].texture_buffer[(texture_width * textureOffSetY) + textureOffSetX];
				//drawPixel(x, y, texelColor);
				//olc::Pixel P = wallsprites[0]->Sample
				pge->Draw(x, y, olc::CYAN);
				//if (rays[x].wasHitVertical)
				//{
				//	changeColorIntensity(&texelColor, 0.7);
				//}
				//
				//drawPixel(x, y, texelColor);
			}
		}
	}

}
