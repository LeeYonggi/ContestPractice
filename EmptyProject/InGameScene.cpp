#include "DXUT.h"
#include "InGameScene.h"

#include "BackGround.h"
#include "MonsterSpawner.h"
#include "TowerTile.h"

float timeSpeed = 1.0f;

InGameScene::InGameScene()
{
}


InGameScene::~InGameScene()
{
}

void InGameScene::Init()
{
	OBJECTMANAGER->AddObject(OBJ_ENEMY, new MonsterSpawner(STAGE1));
	OBJECTMANAGER->AddObject(OBJ_ENEMY, new TowerTile(STAGE1));
	OBJECTMANAGER->AddObject(OBJ_BACK, new BackGround());
}

void InGameScene::Update()
{
	OBJECTMANAGER->Update();
}

void InGameScene::Render()
{
	OBJECTMANAGER->Render();
}

void InGameScene::Release()
{
	OBJECTMANAGER->Release();
}
