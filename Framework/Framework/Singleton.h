#pragma once

// ** Singleton
// ** 1. 단일 인스턴스로 구성됨. (인스턴스가 여러개로 구성되지 않는다.)
// ** 2. 어디에서나 호출 가능.

class Singleton
{
private:
	static Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Singleton;
		return Instance;
	}

private:
	string SceneState;
	
private:
	Singleton() { }
public:
	~Singleton() { }
};

