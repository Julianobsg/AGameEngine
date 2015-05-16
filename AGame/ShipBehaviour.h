#pragma once
#include "Behaviour.h"
#include "Ship.h"

class ShipBehaviour : public Behaviour
{
public:
	int speed;
	ShipBehaviour();
	~ShipBehaviour();

	virtual void Init();

	virtual void Update();



private:
	float VerticalCheck();
	float HorizontalCheck();
	Ship* myShip;
	void Move(int vertical, int horizontal);
};

