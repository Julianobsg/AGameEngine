#include "Vector2D.h"

Vector2D::Vector2D()
{
	this->x = 0;
	this->y = 0;
}

Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2D Vector2D::Zero()
{
	return Vector2D(0 , 0);
}

Vector2D Vector2D::One()
{
	return Vector2D(1 , 1);
}
