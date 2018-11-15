#pragma once
#include "Object.h"

class Monster;
class MonsterSpawner :
	public Object
{
public:
	MonsterSpawner();
	virtual ~MonsterSpawner();
private:
	D3DXVECTOR2 startPos;
	vector<Monster*> v_Monster;
	vector<D3DXVECTOR2> v_MonsterPath;
	D3DXVECTOR2 spawnPos;

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

