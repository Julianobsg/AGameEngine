#pragma once
#include "Observer.h"
class GameActionObserver :
	public Observer
{
public:
	GameActionObserver();
	~GameActionObserver();

	virtual void Init();

	virtual void Update();

};

