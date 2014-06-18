#pragma once
#include "Transform.h"

class Behaviour
{
public:
	Transform* transform;

	Behaviour(void);
	virtual ~Behaviour(void);
	virtual void Init();
	virtual void Update();
};

