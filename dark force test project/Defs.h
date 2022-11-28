#ifndef CONSTANTS_H
#define CONSTANTS_H


#include <stdint.h>


#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64

#define MAP_NUM_ROWS 14
#define MAP_NUM_COLS 20

#define NUM_TEXTURES 9
#define MINIMAP_SCALE_FACTOR 0.2

#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64

#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS WINDOW_WIDTH
//640               .5775
#define Dist_PROJ_PLANE ((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2)) //1108.51

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

typedef uint32_t color_t;


#endif
