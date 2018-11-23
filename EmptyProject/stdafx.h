#pragma once


#define SCREEN_X 1280
#define SCREEN_Y 720


#define DEVICE DXUTGetD3D9Device()
#define Vector2 D3DXVECTOR2
extern float timeSpeed;
#define ElTime DXUTGetElapsedTime() * timeSpeed

#include "MainProc.h"
#include <math.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "Singleton.h"
#include "CameraManager.h"
#include "ImageManager.h"
#include "InputManager.h"
#include "Object.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "Scene.h"

#include "InGameScene.h"