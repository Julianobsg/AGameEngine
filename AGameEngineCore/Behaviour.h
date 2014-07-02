#pragma once
#include "Transform.h"
#include "Texture.h"

class Behaviour
{
public:
	Transform* transform;
	Texture* texture;

	Behaviour(void);
	virtual ~Behaviour(void);
	virtual void Init();
	virtual void Update();
};

