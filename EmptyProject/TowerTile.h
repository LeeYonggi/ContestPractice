#pragma once
#include "Object.h"
#include <functional>

class TowerTile :
	public Object
{
public:
	TowerTile(STAGE_STATE _stageKind);
	TowerTile();
	virtual ~TowerTile();

private:
	STAGE_STATE stageKind;
	vector<bool> vTileSet;
	int width;
	int height;

	float tileX;
	float tileY;
	bool isSelect;

public:
	virtual void Init()		override;
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Release()	override;

public:
	void TileBasicInit();
	void TileCheck();
	void TileFunction(const function<void()> &func);

};

