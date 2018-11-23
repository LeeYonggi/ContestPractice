#include "DXUT.h"
#include "Tower01.h"


Tower01::Tower01()
{
}


Tower01::~Tower01()
{
}

void Tower01::Init()
{
	IMAGEMANAGER->AddImage("testTower", "./Resource/Tower/0_1/Idle/d1_1.png");
	vTexture = IMAGEMANAGER->AddAnimeImage("./Resource/Tower/0_1/Idle/d%d_1.png", 1, 12);
}

void Tower01::Update()
{
	Tower::Update();
}

void Tower01::Render()
{
	switch (towerState)
	{
	case TOW_DEFAULT:
		break;
	case TOW_ATTACK:
		break;
	default:
		break;
	}
	IMAGEMANAGER->DrawImage("testTower", pos);
}

void Tower01::Release()
{
}
