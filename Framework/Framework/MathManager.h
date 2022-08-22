#pragma once
#include "Headers.h"

class MathManager
{
public:
	// ** 거리 구하는 함수    
	static float GetDistance(const Vector3& _A_Point,const Vector3& _B_Point)
	{
		const float Width = _A_Point.x - _B_Point.x;
		const float Height = _A_Point.y - _B_Point.y;

		return sqrt((float)pow(Width, 2) + (float)pow(Height, 2));
	}

	// ** 방향 구하는 함수    
	static Vector3 GetDirection(const Vector3& _Current,const Vector3& _Target)
	{
		const float Width = _Target.x - _Current.x;
		const float Height = _Target.y - _Current.y;

		const float Distance = sqrt((float)pow(Width, 2) + (float)pow(Height, 2));

		return Vector3(Width / Distance, Height / Distance);
	}
};