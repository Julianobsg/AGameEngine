#pragma once
#include "Behaviour.h"
#include "Shot.h"
class ShotBehaviour :
	public Behaviour
{
public:
	ShotBehaviour();
	~ShotBehaviour();

	float speed;
	virtual void Init();

	virtual void Update();
private:
	Shot* myShot;
};

