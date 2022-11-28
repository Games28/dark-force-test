#include "Map.h"


void Map::InitMap()
{
	
}

bool Map::mapHasWallAt(float x, float y)
{
	if (x < 0 || x >= MAP_NUM_COLS * TILE_SIZE || y < 0 || y >= MAP_NUM_ROWS * TILE_SIZE) {
		return true;
	}
	int mapGridIndexX = floor(x / TILE_SIZE);
	int mapGridIndexY = floor(y / TILE_SIZE);
	return theMap[mapGridIndexY][mapGridIndexX] != 0;
}

bool Map::isInsideMap(float x, float y)
{
	return (x >= 0 && x <= MAP_NUM_COLS * TILE_SIZE && y >= 0 && y <= MAP_NUM_ROWS * TILE_SIZE);
}

void Map::renderMap(olc::PixelGameEngine& pge)
{
	for (int i = 0; i < MAP_NUM_ROWS; i++) {
		for (int j = 0; j < MAP_NUM_COLS; j++) {
			int tileX = j * TILE_SIZE;
			int tileY = i * TILE_SIZE;
			olc::Pixel P = theMap[i][j] != 0 ? olc::BLUE : olc::WHITE;


			pge.FillRect(
				tileX * MINIMAP_SCALE_FACTOR,
				tileY * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR,
				P
			);

		}
	}
}

int Map::getMapAt(int x, int y)
{
	return theMap[x][y];
}
