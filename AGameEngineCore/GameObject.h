#pragma once
#include "EngineGlobal.h"

#include <string>

using namespace std;

class GameObject
{
public:
	string name;
	GameObject(void);
	~GameObject(void);
	void Update();
};

