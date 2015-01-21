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
        Transform* cameraTransform = WorldToCameraTransform(sprite->transform);
        
		sprite->Draw(cameraTransform);
	}
}

bool Camera::OnView(Sprite* sprite)
{
	return true;
}

Vector2D* Camera::WorldToCameraPosition(Vector2D* position)
{
    Vector2D* inCameraPosition = new Vector2D(transform->position.x - position->x,
                                              transform->position.y - position->y);
	return inCameraPosition;
}

Vector2D* Camera::WorldToCameraScale(Vector2D *scale)
{
    return scale;
}

Transform* Camera::WorldToCameraTransform(Transform *transform)
{
    Transform* cameraTransform = new Transform;
    
    cameraTransform->angle = transform->angle;
    
    cameraTransform->position = *WorldToCameraPosition(&(transform->position));
    
    cameraTransform->scale = *WorldToCameraScale(&(transform->scale));
    
    return cameraTransform;
}