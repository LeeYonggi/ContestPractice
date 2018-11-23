#include "DXUT.h"
#include "Tower.h"

#include "Bullet.h"

Tower::Tower()
{
	towerState = TOW_DEFAULT;
	damage = 1;
	shootDelay = 0.5f;
}

Tower::~Tower()
{
}

void Tower::Init()
{

}

void Tower::Update()
{
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
