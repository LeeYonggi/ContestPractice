#include "DXUT.h"
#include "InGameScene.h"

#include "BackGround.h"
#include "MonsterSpawner.h"

float timeSpeed = 1.0f;

InGameScene::InGameScene()
{
}


InGameScene::~InGameScene()
{
}

void InGameScene::Init()
{
	OBJECTMANAGER->AddObject(OBJ_ENEMY, new MonsterSpawner());
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
