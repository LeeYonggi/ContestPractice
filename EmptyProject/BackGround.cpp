#include "DXUT.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

void BackGround::Init()
{
	texture = IMAGEMANAGER->AddImage("Stage1Back", "./Resource/stage1/stage1.png");
	pos = { SCREEN_X * 0.5f, SCREEN_Y * 0.5f };
}

void BackGround::Update()
{
}

void BackGround::Render()
{
	Object::Draw();
}

void BackGround::Release()
{
}
