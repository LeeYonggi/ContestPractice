#include "DXUT.h"
#include "MonsterSpawner.h"
#include "Monster.h"


MonsterSpawner::MonsterSpawner()
	: spawnPos({ 0, 0 })
{
}


MonsterSpawner::~MonsterSpawner()
{
	v_MonsterPath.clear();
}

void MonsterSpawner::Init()
{
	v_Monster.push_back(dynamic_cast<Monster*>(OBJECTMANAGER->AddObject(OBJ_ENEMY, new Monster())));
	spawnPos = { 0, 100 };
	for (int i = 0; i < v_Monster.size(); i++)
	{
		v_Monster[i]->SetActive(false);
		v_Monster[i]->SetPos(spawnPos);
	}

	v_MonsterPath.push_back({800, 100});
	
	
	v_Monster[0]->SetMonsterPath(v_MonsterPath);
	v_Monster[0]->SetActive(true);
}

void MonsterSpawner::Update()
{
	
}

void MonsterSpawner::Render()
{
}

void MonsterSpawner::Release()
{
}
