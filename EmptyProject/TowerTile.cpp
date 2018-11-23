#include "DXUT.h"
#include "TowerTile.h"

#include "Tower01.h"


TowerTile::TowerTile(STAGE_STATE _stageKind)
{
	stageKind = _stageKind;
	width = 16;
	height = 9;
	TileFunction([&]() { TileBasicInit(); });
	isSelect = false;
	tileX = 0;
	tileY = 0;
}

TowerTile::TowerTile()
{
}


TowerTile::~TowerTile()
{
}

void TowerTile::Init()
{
	IMAGEMANAGER->AddImage("testSelect", "./Resource/testSelect.png");

	switch (stageKind)
	{
	case STAGE1:
		for(int i = 0; i < 10; i++)
			vTileSet[i] = true;

		break;
	case STAGE2:
		break;
	case STAGE3:
		break;
	default:
		break;
	}
}

void TowerTile::Update()
{
	isSelect = false;
	TileCheck();
}

void TowerTile::Render()
{
	if (isSelect)
	{
		IMAGEMANAGER->DrawImage("testSelect", Vector2(tileX, tileY), 0, 2);
	}
}

void TowerTile::Release()
{
}

void TowerTile::TileBasicInit()
{
	vTileSet.push_back(false);
}

void TowerTile::TileCheck()
{
	D3DXVECTOR2 mousePoint = INPUTMANAGER->GetMousePos() - CAMERAMANAGER->camPos;

	if (mousePoint.x < 0 || mousePoint.y < 0) return;

	int x = mousePoint.x /= 80;
	int y = mousePoint.y /= 80;

	y *= 10;

	if (vTileSet[x + y] == true)
	{
		isSelect = true;
		tileX = x * 80 + 40;
		tileY = y * 80 + 40;
		if (INPUTMANAGER->GetKeyDown(VK_LBUTTON))
		{
			Object *temp = OBJECTMANAGER->AddObject(OBJ_TOWER, new Tower01());
			temp->SetPos({ tileX, tileY });
		}
	}
}

void TowerTile::TileFunction(const function<void()>& func)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			func();
		}
	}
}
