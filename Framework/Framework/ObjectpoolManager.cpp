#include "ObjectpoolManager.h"
#include "Object.h"

ObjectpoolManager* ObjectpoolManager::Instance = nullptr;


ObjectpoolManager::ObjectpoolManager()
{

}

ObjectpoolManager::~ObjectpoolManager()
{

}

void ObjectpoolManager::GetObject(string _Key)
{

}

void ObjectpoolManager::SwitchingObject(Object* _Object)
{
	auto iter = DisableList.find(_Object->GetKey());

	//DisableList.size()
	
	if (iter == DisableList.end())
	{
		list<Object*> Temp;
		Temp.push_back(_Object);
		DisableList.insert(make_pair(_Object->GetKey(), Temp));
	}
	else
		iter->second.push_back(_Object);
}

void ObjectpoolManager::Update()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); )
		{
			int Result = (*iter2)->Update();

			if (Result)
			{
				SwitchingObject((*iter2));
				iter2 = iter->second.erase(iter2);
			}
			else
				++iter2;
		}
	}
}

void ObjectpoolManager::Render()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}