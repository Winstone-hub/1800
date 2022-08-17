#pragma once
#include "Headers.h"

template <typename T>
class ObjectFactory
{
public:
	static Object* CreateObject()
	{
		Object* pObject = new T;
		pObject->Start();

		return pObject;
	}

	static Object* CreateObject(Vector3 _Position)
	{
		Object* pObject = new T;

		pObject->Start();
		pObject->SetPosition(_Position);

		return pObject;
	}
};