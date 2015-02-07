#include "GameObject.h"


GameObject::GameObject(void)
{
	transform = new Transform();
	name = "GameObject";
}


GameObject::~GameObject(void)
{
}

void GameObject::Update()
{
	for (std::list<Behaviour*>::iterator it = behaviours.begin(); it != behaviours.end(); it++)
	{
		Behaviour* behaviour = *it;
		behaviour->Update();
	}
}

void GameObject::AddBehaviour(Behaviour* behaviour)
{
	behaviour->transform = transform;
	behaviour->gameObject = this;
	behaviours.push_front(behaviour);
}

void GameObject::Init()
{
	for (std::list<Behaviour*>::iterator it = behaviours.begin(); it != behaviours.end(); it++)
	{
		Behaviour* behaviour = *it;
		behaviour->Init();
	}
}

void GameObject::Draw(Transform* cameraTransform)
{

}
