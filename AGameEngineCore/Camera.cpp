#include "Camera.h"
#define  DEFAULT_CAMERA_SIZE 10;

Camera::Camera()
{
	size = DEFAULT_CAMERA_SIZE;
}

Camera::Camera(Vector2D screenSize) : Camera()
{
	this->screenSize = screenSize;
}

Camera::~Camera()
{
}

void Camera::Draw(Sprite* sprite)
{
	if (OnView(sprite))
	{
		sprite->Draw();
	}
}

bool Camera::OnView(Sprite* sprite)
{
	return true;
}

Vector2D* Camera::WorldToCameraPosition(Vector2D* position)
{
	return position;
}

