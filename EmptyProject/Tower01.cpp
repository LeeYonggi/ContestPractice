#include "DXUT.h"
#include "Tower01.h"

#include "Bullet.h"


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
	vTexture = IMAGEMANAGER->AddAnimeImage("./Resource/Tower/0_1/Idle/d%d_1.png", 0, 11);
	for (int i = 1; i < 13; i++)
	{
		for (int j = 1; j < 16; j++)
		{
			char ctr[128];
			sprintf(ctr, "./Resource/Tower/0_1/Attack/clem_lv1%d_%d.png", i, j);
			IMAGEMANAGER->AddImage(ctr, ctr);
		}
	}
}

void Tower01::Update()
{
	Tower::Update();
	switch (towerState)
	{
	case TOW_DEFAULT:
		TargetTracking();
		break;
	case TOW_ATTACK:
		if (CircleCollision(pos, target->GetPosition(), 200, 1))
		{
			if (shootDelay < 0.0f)
			{
				Object *temp = OBJECTMANAGER->AddObject(OBJ_BULLET, new Bullet(target, 500, damage));
				temp->SetPos(pos);
				shootDelay = 0.5f;
				isShoot = true;
			}
		}
		else
			towerState = TOW_DEFAULT;

		if (shootDelay > 0.0f)
			shootDelay -= ElTime;
		break;
	default:
		break;
	}
}

void Tower01::Render()
{
	char ctr[128];
	

	switch (towerState)
	{
	case TOW_DEFAULT:
		sprintf(ctr, "./Resource/Tower/0_1/Idle/d%d_1.png", (int)angle);
		IMAGEMANAGER->DrawImage(ctr, pos);
		break;
	case TOW_ATTACK:
		if (target)
		{
			angle = GetTargetAngle(target);
			angle = angle / 30;
			if (attackDelay < 14 && isShoot)
				attackDelay += ElTime * 30.0f;
			else
			{
				attackDelay = 0;
				isShoot = false;
			}
			sprintf(ctr, "./Resource/Tower/0_1/Attack/clem_lv1%d_%d.png", (int)angle + 1, (int)attackDelay + 1);
			//sprintf(ctr, "./Resource/Tower/0_1/Idle/d%d_1.png", (int)angle);
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
