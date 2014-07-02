#include "Keyboard.h"
#include "Debug.h"

KeyCode Keyboard::selectedKeyCode = none;

Keyboard::Keyboard(void)
{
}


Keyboard::~Keyboard(void)
{
}

bool Keyboard::KeyDown(KeyCode keyCode)
{
	return keyCode == selectedKeyCode;
}

void Keyboard::SetKeyDown(SDL_Event* e)
{
	if (e->type == SDL_KEYDOWN)
	{
		switch (e->key.keysym.sym)
		{
		case SDLK_UP:
			selectedKeyCode = KeyCode::up;
			break;
		case SDLK_DOWN:
			selectedKeyCode = KeyCode::down;		
			break;
		case SDLK_LEFT:
			selectedKeyCode = KeyCode::left;
			break;
		case SDLK_RIGHT:
			selectedKeyCode = KeyCode::right;
			break;
		default:
			selectedKeyCode = KeyCode::none;
			break;
		}
	} else {
		selectedKeyCode = KeyCode::none;
	}
}
