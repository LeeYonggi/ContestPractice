#include "DXUT.h"
#include "MainProc.h"


MainProc::MainProc()
{
}


MainProc::~MainProc()
{
}

void MainProc::Init()
{
	IMAGEMANAGER->AddImage("test", "./Resource/test.png");
}

void MainProc::Update()
{
}

void MainProc::Render()
{
	IMAGEMANAGER->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	IMAGEMANAGER->DrawImage("test", {640, 360});

	IMAGEMANAGER->sprite->End();
}

void MainProc::Release()
{
	ImageManager::ReleaseInstance();
}
