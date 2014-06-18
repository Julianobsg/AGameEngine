#include "GameObject.h"


GameObject::GameObject(void)
{
	transform = new Transform();
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
