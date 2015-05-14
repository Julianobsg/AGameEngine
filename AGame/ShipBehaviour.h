#pragma once
#include "Behaviour.h"
#include "Sprite.h"

class ShipBehaviour : public Behaviour
{
public:
	ShipBehaviour();
	~ShipBehaviour();

	virtual void Init();

	virtual void Update();
private:
	Sprite* mySprite;
	void Move(int vertical, int horizontal);
};

