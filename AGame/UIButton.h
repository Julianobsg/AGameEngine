#pragma once
#include <functional>
#include "Behaviour.h"
#include "Transform.h"

#include "Text.h"
#include "ButtonBehaviour.h"
#include "Vector2D.h"

class UIButton
{
public:
	UIButton(string title, Vector2D<float> position);
	~UIButton();

	void SetConclick(std::function<void(void)> onClick);

	Text* Button();
private:

	Text* button;

	ButtonBehaviour* behaviour;
};

