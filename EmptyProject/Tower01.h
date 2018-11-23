#pragma once
#include "Tower.h"
class Tower01 :
	public Tower
{
public:
	Tower01();
	virtual ~Tower01();

private:
	

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

