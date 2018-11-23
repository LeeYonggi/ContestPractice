#include "DXUT.h"
#include "InputManager.h"


InputManager::InputManager()
{
	Init();
}


InputManager::~InputManager()
{
}

void InputManager::Init()
{
	memset(pastKey, false, sizeof(pastKey));
	memset(nowKey, false, sizeof(nowKey));

	mousePoint = { 0, 0 };
}

void InputManager::Update()
{
	memcpy(pastKey, nowKey, sizeof(nowKey));

	for (int i = 0; i < MAX_SIZE_KEY; i++)
		nowKey[i] = GetAsyncKeyState(i);

	GetCursorPos(&mousePoint);
	ScreenToClient(DXUTGetHWND(), &mousePoint);
}
