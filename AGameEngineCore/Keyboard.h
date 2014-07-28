#pragma once
#include "input.h"
#include "EngineGlobal.h"

enum KeyCode
{
	none = 0, up = SDLK_UP, down = SDLK_DOWN, left = SDLK_LEFT, right = SDLK_RIGHT,
    returnKey = SDLK_RETURN,
    escape = SDLK_ESCAPE,
    backspace = SDLK_BACKSPACE,
    tab = SDLK_TAB,
    space = SDLK_SPACE,
    exclain = SDLK_EXCLAIM,
    doubleQuote = SDLK_QUOTEDBL,
    hash = SDLK_HASH ,
    percent = SDLK_PERCENT,
    dollar = SDLK_DOLLAR,
    ampersand = SDLK_AMPERSAND,
    quote = SDLK_QUOTE,
    parenthesisLeft = SDLK_LEFTPAREN,
    parenthesisRight = SDLK_RIGHTPAREN,
    asterisk = SDLK_ASTERISK,
    plus = SDLK_PLUS,
    comma = SDLK_COMMA,
    minus = SDLK_MINUS,
    period = SDLK_PERIOD,
    slash = SDLK_SLASH,
    zero = SDLK_0,
    one = SDLK_1,
    two = SDLK_2,
    three = SDLK_3,
    four = SDLK_4,
    five = SDLK_5,
    six = SDLK_6,
    seven = SDLK_7,
    eight = SDLK_8,
    nine = SDLK_9,
    colon = SDLK_COLON,
    semicolon = SDLK_SEMICOLON,
    less = SDLK_LESS,
    equals = SDLK_EQUALS,
    greater = SDLK_GREATER,
    question = SDLK_QUESTION,
    at = SDLK_AT,
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
