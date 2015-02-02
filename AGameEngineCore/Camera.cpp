#include "Camera.h"
#define  DEFAULT_CAMERA_SIZE 10;

Camera::Camera()
{
	size = DEFAULT_CAMERA_SIZE;
}

Camera::Camera(Vector2D<int> screenSize) : Camera()
{
	this->screenSize = screenSize;
}

Camera::~Camera()
{
	free(cameraTransform);
}

void Camera::Draw(GameObject* gameObject)
{
	if (OnView(gameObject))
	{
        cameraTransform = WorldToCameraTransform(gameObject->transform);

		gameObject->Draw(cameraTransform);
	}
}

bool Camera::OnView(GameObject* sprite)
{
	return true;
}

Vector2D<float>* Camera::WorldToCameraPosition(Vector2D<float>* position)
{
	Vector2D<float>* inCameraPosition = new Vector2D<float>(position->x - transform->position.x,
									          position->y - transform->position.y);
	return inCameraPosition;
}

Vector2D<float>* Camera::WorldToCameraScale(Vector2D<float> *scale)
{
	float scaleModifier = screenSize.y / size;
	return new Vector2D<float>(scale->x * scaleModifier, scale->y * scaleModifier);
}

Transform* Camera::WorldToCameraTransform(Transform *transform)
{
    Transform* cameraTransform = new Transform;
    
    cameraTransform->angle = transform->angle;
    
    cameraTransform->position = *WorldToCameraPosition(&(transform->position));
    
    cameraTransform->scale = *WorldToCameraScale(&(transform->scale));
    
    return cameraTransform;
}