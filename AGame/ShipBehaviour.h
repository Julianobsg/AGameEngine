#pragma once
#include "Behaviour.h"
#include "Sprite.h"

class ShipBehaviour : public Behaviour
{
public:
	int speed;
	ShipBehaviour();
	~ShipBehaviour();

	virtual void Init();

	virtual void Update();



private:
	float VerticalCheck(float vertical);
	float HorizontalCheck(float horizontal);
	Sprite* mySprite;
	void Move(int vertical, int horizontal);
};

