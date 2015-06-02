#include "stdafx.h"
#include "UIButton.h"

UIButton::UIButton(string title, Vector2D<float> position)
{
	button = new Text("CaviarDreams.ttf");
	button->transform->position = position;
	button->SetContent(title);
	button->ChangeColor(0, 255, 255);
	behaviour = new ButtonBehaviour;
	button->AddBehaviour(behaviour);
}


UIButton::~UIButton()
{
	delete(button);
	delete(behaviour);
}


void UIButton::SetConclick(std::function<void(void)> onClick)
{
	behaviour->onClick = onClick;
}

Text* UIButton::Button()
{
	return button;
}
