#pragma once
#include "Object.h"
class Monster :
	public Object
{
public:
	Monster();
	virtual ~Monster();

private:
	vector<D3DXVECTOR2> v_MonsterPath;
	int nowPath;
	float speed;
	bool isMove;

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
public:
	void MovePath();
public:
	void SetMonsterPath(vector<D3DXVECTOR2> monsterPath) { v_MonsterPath = monsterPath; }
};

