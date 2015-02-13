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
}

void ButtonBehaviour::Update()
{
	Vector2D<int> *position = Mouse::Position();
	//Debug::Log(to_string(position->x));
	
	if (position->x < button->texture->size.x)
	{
		button->ChangeColor(255, 255, 0);
		if (Mouse::MouseButtonDown(MouseCode::left))
		{
			Application::LoadScene(1);
		}
	} else
	{
		button->ChangeColor(0, 255, 255);
	}	
}
