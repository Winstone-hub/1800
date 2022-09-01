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
	// ** 활성화된 오브젝트 리스트
	map<string, list<Object*>> EnableList;

	// ** 비 활성화된 오브젝트 리스트
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

