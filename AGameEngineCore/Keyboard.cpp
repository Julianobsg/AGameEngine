#include "Keyboard.h"
#include "Debug.h"

KeyCode Keyboard::selectedKeyCode = KeyCode::none;

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

void Keyboard::SetEvent(SDL_Event* e)
{
	if (e->type == SDL_KEYDOWN)
	{
        selectedKeyCode = static_cast<KeyCode>(e->key.keysym.sym);
	}
    if (e->type == SDL_KEYUP) 
    {
        selectedKeyCode = KeyCode::none;
    }
}
