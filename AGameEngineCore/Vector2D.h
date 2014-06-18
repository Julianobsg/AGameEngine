#pragma once

class Vector2D
{
public:
	int x;
	int y;
	
	Vector2D();

	Vector2D (int x, int y);

	Vector2D static Zero();
	static Vector2D One();
};