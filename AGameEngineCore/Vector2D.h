#pragma once

template <class T> 
class Vector2D
{
public:
	T x;
	T y;
	
	Vector2D (T x, T y);
    
	void SetVector(T x, T y);
    //Return this vector absolute value copy
};


template<>
class Vector2D <int>
{
public:
	int x;
	int y;

	Vector2D();

	Vector2D(int x, int y);

	static Vector2D<int> Zero();
	static Vector2D<int> One();

	void SetVector(int x, int y);
	//Return this vector absolute value copy
	Vector2D<int> Abs();
};

template<>
class Vector2D < float >
{
public:
	float x;
	float y;

	Vector2D();

	//Vector2D(int x, int y);
	Vector2D(float x, float y);

	static Vector2D<float> Zero();
	static Vector2D<float> One();

	void SetVector(float x, float y);
	
	//void SetVector(int x, int y);
	
	Vector2D<float> Abs();
};
