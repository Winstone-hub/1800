#pragma once


struct Vector3
{
	float x, y, z;

	Vector3() : x(0), y(0), z(0) { };

	Vector3(float _x, float _y)
		: x(_x), y(_y), z(0) { };

	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) { };



	Vector3 operator-(const Vector3& _V1)
	{
		return Vector3(x - _V1.x, y - _V1.y, z - _V1.z);
	}

	Vector3 operator+(const Vector3& _V1)
	{
		return Vector3(x + _V1.x, y + _V1.y, z + _V1.z);
	}

	Vector3 operator+=(const Vector3& _V1)
	{
		return Vector3(x += _V1.x, y += _V1.y, z += _V1.z);
	}

	Vector3 operator/(float _Value)
	{
		return Vector3(x / _Value, y / _Value, z / _Value);
	}

	Vector3 operator*(float _Value)
	{
		return Vector3(x * _Value, y * _Value, z * _Value);
	}
};

struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
	Vector3 Direction;
};



