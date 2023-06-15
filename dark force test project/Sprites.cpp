#include "Sprites.h"

void Object::Walk(const float fWalkSpeed)
{
	fSpeed = fWalkSpeed;
	vel = olc::vf2d(std::cos(fHeading), std::sin(fHeading)) * fSpeed;
}

void Object::Strafe(const float fStrafeSpeed)
{
	fSpeed = fStrafeSpeed;
	vel = olc::vf2d(std::cos(fHeading), std::sin(fHeading)).perp() * fSpeed;
}

void Object::Turn(const float fTurnSpeed)
{
	fHeading += fTurnSpeed;

	// Wrap heading to sensible angle
	if (fHeading < -3.14159f) fHeading += 2.0f * 3.14159f;
	if (fHeading > 3.14159f) fHeading -= 2.0f * 3.14159f;
}

void Object::Stop()
{
	fSpeed = 0;
	vel = { 0,0 };
}
