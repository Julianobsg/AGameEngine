#pragma once
class Vector3D
{
public:
	int x;
	int z;
	int y;

	Vector3D(void);
	~Vector3D(void);
	Vector3D (int x, int y, int z);

	static Vector3D  Zero();
	static Vector3D One();
};

