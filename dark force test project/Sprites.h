#pragma once
#include <unordered_map>
#include <algorithm>
#include "olcPixelGameEngine.h"

class Object
{
public:
	uint32_t nGenericID = 0;
	olc::vf2d pos;
	olc::vf2d vel;
	olc::vf2d resetvel;
	float fSpeed = 0.0f;
	float fHeading = 0.0f;
	float angle = 0.0f;
	float fRadius = 0.0f;
	bool objecthit = false;
	bool bVisible = true;
	bool bRemove = false;
	bool bCollideWithScenery = true;
	bool bNotifySceneryCollision = false;
	bool bCollideWithObjects = false;
	bool bNotifyObjectCollision = false;
	bool bCanbeMoved = false;
	bool bIsActive = true;

public:
	void Walk(const float fWalkSpeed);
	void Strafe(const float fStrafeSpeed);
	void Turn(const float fTurnSpeed);
	void Stop();
	
};

