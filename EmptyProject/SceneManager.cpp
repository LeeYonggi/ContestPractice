#include "DXUT.h"
#include "SceneManager.h"
#include "Scene.h"



void SceneManager::ChangeScene(Scene * nextScene)
{
	v_Scenes.push_back(nextScene);
	nowScene = v_Scenes.size() - 1;
	isSceneChange = true;
}

void SceneManager::Update()
{
	if (isSceneChange)
	{
		if (pastScene != 0)
			v_Scenes[pastScene]->Release();
		
		v_Scenes[nowScene]->Init();
		pastScene = nowScene;
		
		isSceneChange = false;
	}
	v_Scenes[nowScene]->Update();
}

void SceneManager::Render()
{
	v_Scenes[pastScene]->Render();
}

void SceneManager::Release()
{
	for (auto iter : v_Scenes)
	{
		SAFE_RELEASE(iter);
		SAFE_DELETE(iter);
	}
	v_Scenes.clear();
}

SceneManager::SceneManager()
	: pastScene(0), nowScene(0), isSceneChange(false)
{
}


SceneManager::~SceneManager()
{
	Release();
}
