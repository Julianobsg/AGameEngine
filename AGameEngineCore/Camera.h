#pragma once
#include "GameObject.h"
#include "Sprite.h"

class Camera :
	public GameObject
{
public:
	Vector2D screenSize;
	//Size - Meters needed to reach each side of the smallest Size of screen
	float size;
	Camera(Vector2D screenSize);
	Camera();
	~Camera();
	void Draw(Sprite* sprite);
	bool OnView(Sprite* sprite);
    Vector2D* WorldToCameraPosition(Vector2D* position);
    Vector2D* WorldToCameraScale(Vector2D* scale);
private:
    Transform* WorldToCameraTransform(Transform* transform);

};

