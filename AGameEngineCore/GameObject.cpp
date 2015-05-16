#include "GameObject.h"


GameObject::GameObject(void)
{
	transform = new Transform();
	name = "GameObject";
	destroy = false;
}


GameObject::~GameObject(void)
{
	for (std::list<Behaviour*>::iterator it = behaviours.begin(); it != behaviours.end(); it++)
	{
		delete(*it);
	}
}

void GameObject::Update()
{
	for (std::list<Behaviour*>::iterator it = behaviours.begin(); it != behaviours.end(); it++)
	{
		Behaviour* behaviour = *it;
		behaviour->Update();
		if (destroy)
		{
			break;
		}
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

void GameObject::Destroy()
{
	destroy = true;
}

void GameObject::Load(SDL_Renderer* renderer)
{

}

