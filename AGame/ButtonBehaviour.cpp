#include "stdafx.h"
#include "ButtonBehaviour.h"
#include "Debug.h"
#include "Mouse.h"
#include <string>
#include "Application.h"


ButtonBehaviour::ButtonBehaviour()
{
}


ButtonBehaviour::~ButtonBehaviour()
{
}

void ButtonBehaviour::Init()
{
	button = (Text*) this->gameObject;
	
	Vector2D<float> worldPosition = *Application::GetMainCamera()->
		WorldToCameraPosition(&(button->transform->position));
	boundaries.minY = worldPosition.y;
	boundaries.minX = worldPosition.x;
	boundaries.maxX = worldPosition.x + (button->texture->size.x * button->transform->scale.x);
	boundaries.maxY = worldPosition.y + (button->texture->size.y * button->transform->scale.y);
}

void ButtonBehaviour::Update()
{
	Vector2D<int> *position = Mouse::Position();
	//Debug::Log(to_string(position->x));
	
	if (position->x < boundaries.maxX && position->x > boundaries.minX
		&& position->y > boundaries.minY && position->y < boundaries.maxY)
	{
		button->ChangeColor(255, 255, 0);
		if (Mouse::MouseButtonDown(MouseCode::left))
		{
			onClick();
		}
	} else
	{
		button->ChangeColor(0, 255, 255);
	}	
}
