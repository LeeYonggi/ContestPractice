#pragma once
#include "Object.h"


enum TOWER_STATE
{
	TOW_DEFAULT,
	TOW_ATTACK
};

class Tower :
	public Object
{
public:
	Tower();
	virtual ~Tower();

protected:
	float radius;
	Object *target;
	TOWER_STATE towerState;
	int damage;
	float attackDelay;
	float shootDelay;
	bool isShoot;
	vector<Texture*> vTexture;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();

public:
	bool TargetTracking();
	
};

