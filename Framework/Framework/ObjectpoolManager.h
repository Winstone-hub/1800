#pragma once
#include "Headers.h"

class Object;
class ObjectpoolManager
{
private:
	static ObjectpoolManager* Instance;
public:
	static ObjectpoolManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectpoolManager;
		return Instance;
	}
private:
	// ** Ȱ��ȭ�� ������Ʈ ����Ʈ
	map<string, list<Object*>> EnableList;

	// ** �� Ȱ��ȭ�� ������Ʈ ����Ʈ
	map<string, list<Object*>> DisableList;
public:
	bool FindObject(string _Key);
	void AddObject(string _Key);
	void SwitchingObject(string _Key, Vector3 _Position = Vector3());
	void Update();
	void Render();
private:
	ObjectpoolManager();
public:
	~ObjectpoolManager();
};

