#include "Vector3D.h"


Vector3D::Vector3D(void)
{
	Vector3D::Vector3D(0, 0, 0);
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
	return Vector3D::Vector3D(0, 0, 0);
}

Vector3D Vector3D::One()
{
	return Vector3D::Vector3D(1, 1, 1);
}
