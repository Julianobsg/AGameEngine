#include "Keyboard.h"
#include "Debug.h"


Keyboard::Keyboard(void)
{
}


Keyboard::~Keyboard(void)
{
}

bool Keyboard::KeyDown(KeyCode keyCode)
{
	if (keyStatus[keyCode] != 0)
	{
		return keyStatus[keyCode] == STATUS_PRESSED;
	}
	return false;
}

void Keyboard::SetEvent(SDL_Event* e)
{
	if (e->type == SDL_KEYDOWN)
	{
        keyStatus[static_cast<KeyCode>(e->key.keysym.sym)] = STATUS_PRESSED;
	}
    if (e->type == SDL_KEYUP) 
    {
		keyStatus[static_cast<KeyCode>(e->key.keysym.sym)] = STATUS_RELEASED;
    }
}

std::map<KeyCode, int> Keyboard::keyStatus;
