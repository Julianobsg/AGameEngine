#pragma once
#include "Sprite.h"

class Ship : public Sprite
{
public:
	const int SHIP_WIDTH = 120;
	const int SHIP_HEIGHT = 100;
	Ship();
	~Ship();
private:
	void SetupAnimations();
};

