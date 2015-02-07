#pragma once
#include "Transform.h"
#include "Texture.h"

class GameObject;

class Behaviour
{
public:
	GameObject* gameObject;
	Transform* transform;
	Texture* texture;

	Behaviour(void);
	virtual ~Behaviour(void);
	virtual void Init();
	virtual void Update(); 
};

