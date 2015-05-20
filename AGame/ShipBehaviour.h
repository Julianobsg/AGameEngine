#pragma once
#include "Behaviour.h"
#include "Ship.h"

class ShipBehaviour : public Behaviour
{
public:
	float fireRate;
	int speed;
	ShipBehaviour();
	~ShipBehaviour();

	virtual void Init();

	virtual void Update();



private:
	float actualRating;
	float VerticalCheck();
	float HorizontalCheck();
	Ship* myShip;
	void Move(int vertical, int horizontal);
};

