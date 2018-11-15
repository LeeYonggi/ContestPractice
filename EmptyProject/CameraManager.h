#pragma once
#include "Singleton.h"
class CameraManager :
	public Singleton<CameraManager>
{
public:
	D3DXVECTOR2 camPos;
public:
	CameraManager();
	virtual ~CameraManager();
public:
	
};

#define CAMERAMANAGER CameraManager::GetInstance()