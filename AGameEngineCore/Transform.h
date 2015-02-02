#pragma once
#include "Vector2D.h"

class Transform
{
public:
	Vector2D<float> position;
	float angle;
	Vector2D<float> scale;

	Transform(void);
	~Transform(void);
};

