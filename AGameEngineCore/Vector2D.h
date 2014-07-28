#pragma once

class Vector2D
{
public:
	int x;
	int y;
	
	Vector2D();

	Vector2D (int x, int y);

	static Vector2D Zero();
	static Vector2D One();
    
    //Return this vector absolute value copy
    Vector2D Abs();
};
