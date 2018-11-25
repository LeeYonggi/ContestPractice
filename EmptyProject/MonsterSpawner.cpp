#include "DXUT.h"
#include "MonsterSpawner.h"
#include "Monster.h"


MonsterSpawner::MonsterSpawner(STAGE_STATE _stageKind)
	: spawnPos({ 0, 0 })
{
	stageKind = _stageKind;
}

MonsterSpawner::MonsterSpawner()
	: spawnPos({ 0, 0 })
{
}


MonsterSpawner::~MonsterSpawner()
{
	v_MonsterPath.clear();
}

void MonsterSpawner::Stage1Init()
{
	v_Monster.push_back(dynamic_cast<Monster*>(OBJECTMANAGER->AddObject(OBJ_ENEMY, new Monster())));
	spawnPos = { 0, 150 };

	for (int i = 0; i < v_Monster.size(); i++)
	{
		v_Monster[i]->SetActive(false);
		v_Monster[i]->SetPos(spawnPos);
	}

	v_MonsterPath.push_back({ 950, 150 });

	for (int i = 5; i < 180; i += 5)
	{
		float x = cos(D3DXToRadian(i- 90)) * 110;
		float y = sin(D3DXToRadian(i- 90)) * 100;
		v_MonsterPath.push_back({ 950 + x, 250 + y });
	}
	
	v_MonsterPath.push_back({ 350, 350 });
	
	for (int i = 175; i > 0; i -= 5)
	{
		float x = cos(D3DXToRadian(i + 90)) * 110;
		float y = sin(D3DXToRadian(i + 90)) * 100;
		v_MonsterPath.push_back({ 320 + x, 450 + y });
	}

	v_MonsterPath.push_back({ 1250, 550 });

	v_Monster[0]->SetMonsterPath(v_MonsterPath);
	v_Monster[0]->SetActive(true);
} 

void MonsterSpawner::Init()
{
	switch (stageKind)
	{
	case STAGE1:
		Stage1Init();
		break;
	case STAGE2:
		break;
	case STAGE3:
		break;
	default:
		break;
	}
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
