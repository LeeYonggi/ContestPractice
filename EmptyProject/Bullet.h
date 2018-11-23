#pragma once
#include "Object.h"
class Bullet :
	public Object
{
public:
	Bullet(Object *_target, float _speed, int _damage);
	Bullet();
	virtual ~Bullet();

private:
	Object *target;
	float speed; 
	int damage;

public:
	virtual void Init()		override;
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Release()	override;

};

