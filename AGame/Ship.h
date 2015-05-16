#pragma once
#include "Sprite.h"
#include "Scene.h"

class Ship : public Sprite
{
public:
	const int SHIP_WIDTH = 120;
	const int SHIP_HEIGHT = 100;
	Ship();
	~Ship();
	void Shoot();
private:
	void SetupAnimations();
};

