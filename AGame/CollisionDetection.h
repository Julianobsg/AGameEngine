#pragma once
#include "Observer.h"
#include "Sprite.h"
#include "Collision.h"

class CollisionDetection
	: public Observer
{
public:

	CollisionDetection();
	~CollisionDetection();

	virtual void Init();

	virtual void Update();
private:
	float detectionDelay = 0.0f;
	int goSize;
	void DetetectCollision();
	
	std::list<Collision*> collidingObjects;
	struct Boundaries
	{
		float minX;
		float minY;
		float maxX;
		float maxY;
	};
	Boundaries GetBoundaries(Sprite* sprite);
};

