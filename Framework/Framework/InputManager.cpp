#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : dwKey(0)
{

}

InputManager::~InputManager()
{

}

void InputManager::CheckKey()
{
	dwKey = 0;

	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
		dwKey |= KEY_UP;

	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
		dwKey |= KEY_DOWN;

	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
		dwKey |= KEY_LEFT;

	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
		dwKey |= KEY_RIGHT;

	if (GetAsyncKeyState(VK_SPACE))
		dwKey |= KEY_SPACE;

	if (GetAsyncKeyState(VK_RETURN))
		dwKey |= KEY_RETURN;

	if (GetAsyncKeyState(VK_ESCAPE))
		dwKey |= KEY_ESCAPE;
}
