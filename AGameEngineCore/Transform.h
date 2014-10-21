#pragma once
#include "Vector2D.h"

class Transform
{
public:
	Vector2D position;
	float angle;
	Vector2D scale;

	Transform(void);
	~Transform(void);
};

