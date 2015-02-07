#pragma once
#include "Behaviour.h"
#include "Text.h"
#include "Camera.h"

class ButtonBehaviour : public Behaviour
{
public:
	Text* button;
	Camera* mainCamera;

	ButtonBehaviour();
	~ButtonBehaviour();

	virtual void Init();

	virtual void Update();

};

