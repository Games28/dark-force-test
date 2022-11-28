#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include"olcPixelGameEngine.h"
#include "Defs.h"
#include "Map.h"

class Player
{
public:
	Player() = default;
	void Init();
	void movePlayer(float deltaTime);
	void renderPlayer(olc::PixelGameEngine* pge);
	void Controls(olc::PixelGameEngine* pge);
public:
	float x;
	float y;
	float width;
	float height;
	int turnDirection; // -1 for left, +1 for right
	int walkDirection; // -1 for back, +1 for front
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
	int islookingupdown;
	float lookUpDown;
	float playerLookAngle;
	Map theMap;
};
#endif // !PLAYER_H


