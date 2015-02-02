#include "Transform.h"


Transform::Transform()
{
	scale = Vector2D<float>::One();
	angle = 0.0f;
	position = Vector2D<float>::Zero();
}


Transform::~Transform()
{
}
