#include "DXUT.h"
#include "Tower01.h"


Tower01::Tower01()
{
	angle = 1;
}


Tower01::~Tower01()
{
}

void Tower01::Init()
{
	IMAGEMANAGER->AddImage("testTower", "./Resource/Tower/0_1/Idle/d4_1.png");
	vTexture = IMAGEMANAGER->AddAnimeImage("./Resource/Tower/0_1/Idle/d%d_1.png", 4, 15);
}

void Tower01::Update()
{
	Tower::Update();
}

void Tower01::Render()
{
	char ctr[128];
	

	switch (towerState)
	{
	case TOW_DEFAULT:
		sprintf(ctr, "./Resource/Tower/0_1/Idle/d%d_1.png", (int)angle + 3);
		IMAGEMANAGER->DrawImage(ctr, pos);
		break;
	case TOW_ATTACK:
		if (target)
		{
			angle = GetTargetAngle(target);
			angle = ceil(angle / 30);
			sprintf(ctr, "./Resource/Tower/0_1/Idle/d%d_1.png", (int)angle + 3);
			IMAGEMANAGER->DrawImage(ctr, pos);
		}
		break;
	default:
		break;
	}
	//IMAGEMANAGER->DrawImage("testTower", pos);
}

void Tower01::Release()
{
}
