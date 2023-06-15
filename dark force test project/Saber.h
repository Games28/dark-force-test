#ifndef SABER_H
#define SABER_H

#include "olcPixelGameEngine.h"
#include "Animation.h"

class saberType
{
public:
	saberType() = default;
	void SetSprite(std::string filename);
	void setParameters(float intervel, olc::vi2d filesize, olc::vi2d spritecount, bool invert, bool move, bool randomize);

public:
	float fInterval = 0.0f;
	olc::vi2d fileSize = { 0,0 };
	olc::vi2d spriteCount = { 0,0 };
	int totalspriteCount = 0;
	int CurrentTile = 0;
	int tileMovement = 0;
	int invertedStart = 0;
	bool Inverted = false;
	bool tileMove = false;
	bool Randomized = false;
	olc::Sprite* Sprite;
	olc::Decal* Decal;
};

class Saber
{
public:
	Saber() = default;


	bool initSaber(bool success);
	void DrawSaber(olc::PixelGameEngine* gfx, float fElapsedTime);
	void DrawSaberAnimation(olc::PixelGameEngine* gfx, bool& reset, int animation, int inner, int outer, float fElapsedTime);

public:


	olc::vf2d Pos = { 400.0f,150.0f };
	olc::vf2d APos = { 0.0f,0.0f };
	olc::vf2d Positon = { 0.0f,110.0f };
	olc::vf2d leftPos = { 0.0f,110.0f };
	olc::vf2d rightPos = { 0.0f,110.0f };
	olc::Sprite* sprites[5];
	olc::Decal* decals[5];
	float light = 1.0f;
	float Aswitch = 1.0f;
	int SpriteChange = 5;
	float xoffset = 0;
	bool lightswitch = false;
	olc::Pixel p = olc::WHITE;
	olc::Pixel darkinner = olc::BLACK;
	olc::Pixel darkouter = olc::WHITE;
	olc::Pixel lightinner = olc::WHITE;
	olc::Pixel lightouter = olc::BLUE;

	//saber innter animation test
	olc::Sprite* SsaberinnerAnimationleft[7];
	olc::Decal* DsaberinnerAnimationleft[7];

	//saber outer animation
	olc::Sprite* SSaberouterAnimationleft[7];
	olc::Decal* DsaberouterAnimatiionleft[7];
	SpriteAnimation A[2];
	//new animation test
	SpriteAnimation Anime[2];
	olc::Sprite* SsaberAnimation[4];
	olc::Decal* DsaberAnimation[4];

};


/////////////////////////////////////////////////////
//test

class testsaber 
{
public:
	testsaber() = default;
	void Init();
	void update(float deltatime);
	void draw(olc::PixelGameEngine* gfx);


public:
	olc::Sprite* S;
	olc::Decal* D;
	float fTimer;
	int Counter;
	float ox, oy;

};


#endif // !SABER_H



