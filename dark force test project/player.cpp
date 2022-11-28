#include "player.h"


void Player::Init()
{
	x = WINDOW_WIDTH / 2;
	y = WINDOW_HEIGHT / 2;
	width = 20;
	height = 20;
	turnDirection = 0;
	walkDirection = 0;
	rotationAngle = 60;
	walkSpeed = 100;
	turnSpeed = 45 * (PI / 180);
	lookUpDown = 0;
	playerLookAngle = 45 * (PI / 180);
	lookUpDown = 0;
}

void Player::movePlayer(float deltaTime)
{
	rotationAngle += turnDirection * turnSpeed * deltaTime;
	float moveStep = walkDirection *walkSpeed * deltaTime;

	float newPlayerX = x + cos(rotationAngle) * moveStep;
	float newPlayerY = y + sin(rotationAngle) * moveStep;

	//wall collision
	if (!theMap.mapHasWallAt(newPlayerX, newPlayerY)) {
		x = newPlayerX;
		y = newPlayerY;
	}
}

void Player::renderPlayer(olc::PixelGameEngine* pge)
{
	olc::Pixel P = olc::GREEN;
	pge->FillRect(
		x * MINIMAP_SCALE_FACTOR,
		y * MINIMAP_SCALE_FACTOR,
		width * MINIMAP_SCALE_FACTOR,
		height * MINIMAP_SCALE_FACTOR,
		P
	);
}

void Player::Controls(olc::PixelGameEngine* pge)
{
	if (pge->GetKey(olc::Key::W).bHeld)
	{
		walkDirection = +1;
	}
	else if (pge->GetKey(olc::Key::S).bHeld)
	{
		walkDirection = -1;
	}
	else
	{
		walkDirection = 0;
	}

	if (pge->GetKey(olc::Key::D).bHeld)
	{
		turnDirection = +1;
	}
	else if (pge->GetKey(olc::Key::A).bHeld)
	{
		turnDirection = -1;
	}
	else
	{
		turnDirection = 0;
	}

}
