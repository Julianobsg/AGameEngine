#include "Vector3D.h"


Vector3D::Vector3D(void)
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3D::Vector3D(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::~Vector3D(void)
{
}

Vector3D Vector3D::Zero()
{
	Vector3D v3;
	return v3;
}

Vector3D Vector3D::One()
{
	Vector3D v3 = Vector3D(1,1,1);
	return v3;
}
