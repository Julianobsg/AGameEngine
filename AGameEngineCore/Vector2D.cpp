#include "Vector2D.h"

Vector2D<int>::Vector2D()
{
	this->x = 0;
	this->y = 0;
}

Vector2D<int>::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Vector2D<int>::SetVector(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2D<int> Vector2D<int>::Zero()
{
	return Vector2D<int>(0, 0);
}

Vector2D<int> Vector2D<int>::One()
{
	return Vector2D<int>(1, 1);
}

Vector2D<int> Vector2D<int>::Abs()
{
    Vector2D newVector = *this;
    
    
    if (newVector.x < 0) {
        newVector.x *= -1;
    }
    
    if (newVector.y < 0) {
        newVector.y *= -1;
    }
    
    return newVector;
}


Vector2D<float>::Vector2D()
{
	this->x = 0;
	this->y = 0;
}

Vector2D<float>::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2D<float>::SetVector(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D<float> Vector2D<float>::Zero()
{
	return Vector2D<float>(0, 0);
}

Vector2D<float> Vector2D<float>::One()
{
	return Vector2D<float>(1, 1);
}

Vector2D<float> Vector2D<float>::Abs()
{
	Vector2D<float> newVector = *this;


	if (newVector.x < 0) {
		newVector.x *= -1;
	}

	if (newVector.y < 0) {
		newVector.y *= -1;
	}

	return newVector;
}


template <class T>
void Vector2D<T>::SetVector(T x, T y)
{
	this->x = x;
	this->y = y;
}


template <class T>
Vector2D<T>::Vector2D(T x, T y)
{
	this->x = x;
	this->y = y;
}

