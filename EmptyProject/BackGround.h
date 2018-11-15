#pragma once
#include "Object.h"
class BackGround :
	public Object
{
public:
	BackGround();
	virtual ~BackGround();

private:

public:
	void Init();
	void Update();
	void Render();
	void Release();

};

