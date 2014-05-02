#pragma once
#include "EngineGlobal.h"

#include <string>

using namespace std;

class GameObject
{
public:
	string name;
	GameObject(void);
	virtual ~GameObject(void);
	virtual void Update();
};

