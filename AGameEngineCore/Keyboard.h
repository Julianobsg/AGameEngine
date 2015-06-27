#pragma once
#include "input.h"
#include "EngineGlobal.h"
#include <map>

enum class KeyCode
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
    
    leftBracket = SDLK_LEFTBRACKET,
    backslash = SDLK_BACKSLASH,
    rightBracket = SDLK_RIGHTBRACKET,
    caret = SDLK_CARET,
    underscore = SDLK_UNDERSCORE,
    backquote = SDLK_BACKQUOTE,
    a = SDLK_a,
    b = SDLK_b,
    c = SDLK_c,
    d = SDLK_d,
    e = SDLK_e,
    f = SDLK_f,
    g = SDLK_g,
    h = SDLK_h,
    i = SDLK_i,
    j = SDLK_j,
    k = SDLK_k,
    l = SDLK_l,
    m = SDLK_m,
    n = SDLK_n,
    o = SDLK_o,
    p = SDLK_p,
    q = SDLK_q,
    r = SDLK_r,
    s = SDLK_s,
    t = SDLK_t,
    u = SDLK_u,
    v = SDLK_v,
    w = SDLK_w,
    x = SDLK_x,
    y = SDLK_y,
    z = SDLK_z,

};

class Keyboard :
	public Input
{
	friend class Application;
public:
	Keyboard(void);
	~Keyboard(void);

	static bool KeyDown(KeyCode keyCode);

private:
	static void SetEvent(SDL_Event* e);
	static const int STATUS_PRESSED = 2;
	static const int STATUS_RELEASED = 1;
	static std::map<KeyCode, int> keyStatus;
};
