#pragma once
#include "Singleton.h"


class Scene;
class SceneManager :
	public Singleton<SceneManager>
{
private:
	vector<Scene*> v_Scenes;
	int nowScene;
	int pastScene;
	bool isSceneChange;

public:
	void ChangeScene(Scene *nextScene);
	void Update();
	void Render();
	void Release();

	SceneManager();
	virtual ~SceneManager();
};

#define SCENEMANAGER SceneManager::GetInstance()