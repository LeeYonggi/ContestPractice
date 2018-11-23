#include "DXUT.h"
#include "Bullet.h"

#include "Monster.h"


Bullet::Bullet(Object * _target, float _speed, int _damage)
{
	target = _target;
	speed = _speed;
	damage = _damage;
}

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::Init()
{
	IMAGEMANAGER->AddImage("bullet", "./Resource/Tower/0_1/Bullet/bullet.png");
}

void Bullet::Update()
{
	D3DXVECTOR2 temp = TrackingPos(target);

	pos += temp * speed * ElTime; 

	rotation = GetTargetAngle(target) - 180;

	try
	{
		if (CircleCollision(pos, target->GetPosition(), 20, 40))
		{
			auto _target = dynamic_cast<Monster*>(target);
			_target->SetHp(_target->GetHp() - 1);
			SetDestroy(true);
		}
	}
	catch (const std::exception&)
	{
	}

}

void Bullet::Render()
{
	IMAGEMANAGER->DrawImage("bullet", pos, rotation);
}

void Bullet::Release()
{
}
