#pragma once
#include "Object.h"

class Monster;
class MonsterSpawner :
	public Object
{
public:
	MonsterSpawner(STAGE_STATE _stageKind);
	MonsterSpawner();
	virtual ~MonsterSpawner();
private:
	D3DXVECTOR2 startPos;
	vector<Monster*> v_Monster;
	vector<D3DXVECTOR2> v_MonsterPath;
	D3DXVECTOR2 spawnPos;
	STAGE_STATE stageKind;

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
private:
	void Stage1Init();
};

