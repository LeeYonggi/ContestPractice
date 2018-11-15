#include "DXUT.h"
#include "MainProc.h"
#include "InGameScene.h"


MainProc::MainProc()
{
}


MainProc::~MainProc()
{
}

void MainProc::Init()
{
	SCENEMANAGER->ChangeScene(new InGameScene);
}

void MainProc::Update()
{
	SCENEMANAGER->Update();
}

void MainProc::Render()
{
	IMAGEMANAGER->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	SCENEMANAGER->Render();

	IMAGEMANAGER->sprite->End();
}

void MainProc::Release()
{
	ImageManager::ReleaseInstance();
	SceneManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	CameraManager::ReleaseInstance();
}
