#pragma once
#include "Behaviour.h"
#include "Text.h"
#include "Camera.h"
#include <functional>

class ButtonBehaviour : public Behaviour
{
public:
	Text* button;
	Camera* mainCamera;

	ButtonBehaviour();
	~ButtonBehaviour();

	std::function<void(void)> onClick;
	virtual void Init();

	virtual void Update();
private:
	struct Boundaries
	{
		float minX;
		float minY;
		float maxX;
		float maxY;
	};
	Boundaries boundaries;
};

