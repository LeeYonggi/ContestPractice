#pragma once
#include "Singleton.h"

#define OBJECT_SIZE 7 
enum OBJECT_STATE
{
	OBJ_BACK,
	OBJ_BACKGROUND,
	OBJ_TILE,
	OBJ_BULLET,
	OBJ_ENEMY,
	OBJ_TOWER,
	OBJ_UI
};

class ObjectManager :
	public Singleton<ObjectManager>
{
private:
	map<OBJECT_STATE, vector<Object*>*> m_Object;

public:
	ObjectManager();
	virtual ~ObjectManager();
public:
	void Init();
	void Update();
	void Render();
	void Release();

public:
	Object* AddObject(OBJECT_STATE state, Object *obj);
	vector<Object*> *GetObjects(OBJECT_STATE state);
};

#define OBJECTMANAGER ObjectManager::GetInstance()