#pragma once
#include "input.h"
#include "EngineGlobal.h"

enum KeyCode
{
	none = 0, up = 1, down, left, right,
};

class Keyboard :
	public Input
{
public:
	Keyboard(void);
	~Keyboard(void);

	static bool KeyDown(KeyCode keyCode);
	static void SetKeyDown(SDL_Event* e);

private:
	static KeyCode selectedKeyCode;
};
