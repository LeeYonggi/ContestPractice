#include "DXUT.h"
#include "Monster.h"


Monster::Monster()
	: speed(10), nowPath(0)
{
}


Monster::~Monster()
{
}

void Monster::Init()
{
	texture = IMAGEMANAGER->AddImage("testMonster", "./Resource/MonsterTest.png");
	isMove = true;
	speed = 100;
	nowPath = 0;
}

void Monster::MovePath()
{
	D3DXVECTOR2 temp = v_MonsterPath[nowPath] - pos;

	D3DXVec2Normalize(&temp, &temp);

	float lengthX = pos.x - v_MonsterPath[nowPath].x;
	float lengthY = pos.y - v_MonsterPath[nowPath].y;
	float r = lengthX * lengthX + lengthY * lengthY;

	if (sqrt(r) < (speed * ElTime))
	{
		if (v_MonsterPath.size() - 1 > nowPath)
		{
			pos += temp * speed * ElTime;
			++nowPath;
		}
		else
			isMove = false;
	}
	else
		pos += temp * speed * ElTime;
}

void Monster::Update()
{
	if(isMove)
		MovePath();
}

void Monster::Render()
{
	Object::Draw();
}

void Monster::Release()
{
}
