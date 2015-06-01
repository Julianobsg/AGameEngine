#pragma once
#include "EngineGlobal.h"

#include <string>
#include "Vector2D.h"
#include <list>
#include "Behaviour.h"
#include "Transform.h"

using namespace std;

class Scene;

class GameObject
{
public:
	friend class Camera;
	friend class Scene;

	Scene* currentScene;
	string name;
	Transform* transform;
	GameObject(void);
	virtual ~GameObject(void);
	virtual void AddBehaviour(Behaviour* behaviour);
	void Init();
	void Destroy();
	list<Behaviour*> behaviours;
protected:
	void Update();
	virtual void Draw(Transform* cameraTransform); 
	virtual void Load(SDL_Renderer* renderer);
private:
	bool destroy;
};

