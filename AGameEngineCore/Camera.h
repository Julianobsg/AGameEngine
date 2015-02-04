#pragma once
#include "GameObject.h"
#include "Sprite.h"

class Camera :
	public GameObject
{
public:
	Vector2D<int> screenSize;
	//Size - Units needed to reach each side of the height of screen
	float size;
	Camera(Vector2D<int> screenSize);
	Camera();
	~Camera();
	void Draw(GameObject* sprite);
	bool OnView(GameObject* sprite);
	Vector2D<float>* WorldToCameraPosition(Vector2D<float>* position);
	Vector2D<float>* WorldToCameraScale(Vector2D<float>* scale);
private:
    Transform* WorldToCameraTransform(Transform* transform);
	Transform* cameraTransform;
	float scaleModifier;
};

