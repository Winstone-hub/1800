#pragma once
class InputManager
{
private:
	static InputManager* Instance;
public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;
		return Instance;
	}
public:
	void CheckKey();

private:
	InputManager();
public:
	~InputManager();
};

