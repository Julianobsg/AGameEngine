#pragma once
#include "EngineGlobal.h"

#include <string>
#include "Vector2D.h"
#include <list>
#include "Behaviour.h"
#include "Transform.h"

using namespace std;

class GameObject
{
public:
	string name;
	Transform* transform;
	GameObject(void);
	virtual ~GameObject(void);
	void Update();
	virtual void AddBehaviour(Behaviour* behaviour);
	void Init();

protected:
	list<Behaviour*> behaviours;
};

