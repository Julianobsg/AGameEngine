#pragma once
#include "Sprite.h"
class Shot :
	public Sprite
{
public:
	Shot(Vector2D<float> position);
	~Shot();
private:
	const int SHOT_SIZE = 16;
};

