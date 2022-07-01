#pragma once

// ** Singleton
// ** 1. ���� �ν��Ͻ��� ������. (�ν��Ͻ��� �������� �������� �ʴ´�.)
// ** 2. ��𿡼��� ȣ�� ����.

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

