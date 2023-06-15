#include "Saber.h"


bool Saber::initSaber(bool success)
{
	sprites[0] = new olc::Sprite("testinner.png");
	sprites[1] = new olc::Sprite("testouter1.png");
	sprites[2] = new olc::Sprite("testouter2.png");
	sprites[3] = new olc::Sprite("testouter3.png");
	sprites[4] = new olc::Sprite("testouter4.png");
	//sprites[1] = new olc::Sprite("layeredduallightsaberouterSheet.png");
	decals[0] = new olc::Decal(sprites[0]);
	decals[1] = new olc::Decal(sprites[1]);
	decals[2] = new olc::Decal(sprites[2]);
	decals[3] = new olc::Decal(sprites[3]);
	decals[4] = new olc::Decal(sprites[4]);
	A[0].SetParams(0.125f, sprites[1]->width, sprites[1]->height, 4, 1, 4, 0, false, false, false);
	SsaberAnimation[0] = new olc::Sprite("leftangleswingSheet.png");
	SsaberAnimation[1] = new olc::Sprite("leftangleswingSheetglow.png");
	SsaberAnimation[2] = new olc::Sprite("rightangleswingSheet.png");
	SsaberAnimation[3] = new olc::Sprite("rightangleswingSheetglow.png");

	DsaberAnimation[0] = new olc::Decal(SsaberAnimation[0]);
	DsaberAnimation[1] = new olc::Decal(SsaberAnimation[1]);
	DsaberAnimation[2] = new olc::Decal(SsaberAnimation[2]);
	DsaberAnimation[3] = new olc::Decal(SsaberAnimation[3]);
	Anime[0].SetParams(0.125f, SsaberAnimation[0]->width, SsaberAnimation[0]->height, 6, 1, 6, 85, true, true, false);
	Anime[1].SetParams(0.125f, SsaberAnimation[0]->width, SsaberAnimation[0]->height, 6, 1, 6, 85, false, true, false);
	return true;
}

void Saber::DrawSaber(olc::PixelGameEngine* gfx, float fElapsedTime)
{
	int random = 0;


	if (light >= 1.0f)
	{
		lightswitch = true;
		light = 0.70f;
		random = rand() % 3;
	}
	else
	{
		lightswitch = false;

	}
	light += 0.5f;



	if (gfx->GetKey(olc::B).bPressed)
	{
		p = olc::DARK_CYAN;
	}
	if (gfx->GetKey(olc::R).bPressed)
	{
		p = olc::RED;
	}
	if (gfx->GetKey(olc::G).bPressed)
	{
		p = olc::GREEN;
	}
	if (gfx->GetKey(olc::P).bPressed)
	{
		p = olc::MAGENTA;
	}


	olc::vf2d size{ 0.40f,0.40f };
	gfx->SetDecalMode(olc::DecalMode::NORMAL);
	gfx->DrawDecal({ Pos.x,Pos.y }, decals[0], size, olc::WHITE);
	gfx->SetDecalMode(olc::DecalMode::ADDITIVE);

	switch (random)
	{
	case 0:
		gfx->DrawDecal({ Pos.x,Pos.y }, decals[1], size, p);
		break;
	case 1:
		gfx->DrawDecal({ Pos.x,Pos.y }, decals[2], size, p);
		break;
	case 2:
		gfx->DrawDecal({ Pos.x,Pos.y }, decals[3], size, p);
		break;
	case 3:
		gfx->DrawDecal({ Pos.x,Pos.y }, decals[4], size, p);
		break;
	}

}

void Saber::DrawSaberAnimation(olc::PixelGameEngine* gfx, bool& reset, int animation, int inner, int outer, float fElapsedTime)
{




	switch (animation)
	{
	case 0:
	{
		AnimationData saber1 = Anime[animation].GetInfo(fElapsedTime, leftPos.x, reset);
		olc::vf2d size = { 80.0f, 300.0f };
		gfx->SetDecalMode(olc::DecalMode::ADDITIVE);
		gfx->DrawPartialDecal({ leftPos.x, leftPos.y }, size, DsaberAnimation[inner], saber1.sourcePos, saber1.sourceSize, p);
		gfx->SetDecalMode(olc::DecalMode::NORMAL);
		gfx->DrawPartialDecal({ leftPos.x, leftPos.y }, size, DsaberAnimation[outer], saber1.sourcePos, saber1.sourceSize);
	}break;

	case 1:
	{
		AnimationData saber2 = Anime[animation].GetInfo(fElapsedTime, rightPos.x, reset);
		olc::vf2d size = { 80.0f, 300.0f };
		gfx->SetDecalMode(olc::DecalMode::ADDITIVE);
		gfx->DrawPartialDecal({ rightPos.x, rightPos.y }, size, DsaberAnimation[inner], saber2.sourcePos, saber2.sourceSize, p);
		gfx->SetDecalMode(olc::DecalMode::NORMAL);
		gfx->DrawPartialDecal({ rightPos.x, rightPos.y }, size, DsaberAnimation[outer], saber2.sourcePos, saber2.sourceSize);
		
	}break;

	}





}

void saberType::SetSprite(std::string filename)
{
	Sprite = new olc::Sprite(filename);
	Decal = new olc::Decal(Sprite);
}

void saberType::setParameters(float intervel, olc::vi2d filesize, olc::vi2d spritecount, bool invert, bool move, bool randomize)
{
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
}

void testsaber::Init()
{
	S = new olc::Sprite("duallightsaberFullSheet.png");
	D = new olc::Decal(S);


}

void testsaber::update(float deltatime)
{
	fTimer += deltatime;
	if (fTimer >= 1.0f)
	{
		fTimer -= 0.7f;
		Counter++;
		Counter %= 4;
	}
}

void testsaber::draw(olc::PixelGameEngine* gfx)
{
}
