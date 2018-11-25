#include "DXUT.h"
#include "Tower.h"

#include "Bullet.h"

Tower::Tower()
{
	towerState = TOW_DEFAULT;
	damage = 1;
	shootDelay = 0.5f;
	target = nullptr;
	attackDelay = 0;
	isShoot = false;
}

Tower::~Tower()
{
}

void Tower::Init()
{

}

void Tower::Update()
{
	
}

void Tower::Render()
{
	
}

void Tower::Release()
{
}

bool Tower::TargetTracking()
{
	auto iter = OBJECTMANAGER->GetObjects(OBJ_ENEMY);

	for (int i = 0; i < iter->size(); i++)
	{
		if (CircleCollision(pos, (*iter)[i]->GetPosition(), 200, 1))
		{
			towerState = TOW_ATTACK;
			target = (*iter)[i];
			return true;
		}
	}
	return false;
}
