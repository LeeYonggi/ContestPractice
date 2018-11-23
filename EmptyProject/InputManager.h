#pragma once
#include "Singleton.h"

#define MAX_SIZE_KEY 256
class InputManager :
	public Singleton<InputManager>
{
public:
	InputManager();
	virtual ~InputManager();

private:
	bool pastKey[MAX_SIZE_KEY];
	bool nowKey[MAX_SIZE_KEY];

	POINT mousePoint;
public:
	void Init();
	void Update();

	bool GetKeyDown(int key)	{ return (pastKey[key] == false && nowKey[key] == true) ? true : false; }
	bool GetKeyPress(int key) { return (pastKey[key] == true && nowKey[key] == true)	? true : false; }
	bool GetKeyUp(int key)	{ return (pastKey[key] == true && nowKey[key] == false) ? true : false; }

	Vector2 GetMousePos() { return Vector2(mousePoint.x, mousePoint.y); }
};

#define INPUTMANAGER InputManager::GetInstance()