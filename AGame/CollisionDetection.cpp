#include "stdafx.h"
#include "CollisionDetection.h"
#include "Timer.h"
#include "Collision.h"
#include "Application.h"

#define DETECTION_TIMER 0.2f
CollisionDetection::CollisionDetection()
{
}


CollisionDetection::~CollisionDetection()
{
}

void CollisionDetection::Init()
{
	std::list<GameObject*> gameObjects = currentScene->gameObjects;
	goSize = gameObjects.size();
	collidingObjects = std::list < Collision* >();
	for (std::list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		Sprite* go = dynamic_cast<Sprite *>(*it);
		if (go != nullptr)
		{
			for (std::list<Behaviour*>::iterator bIt = go->behaviours.begin(); bIt != go->behaviours.end(); bIt++)
			{
				Collision* col = dynamic_cast<Collision *> (*bIt);
				if (col)
				{
					collidingObjects.push_back(col);
					break;
				}
			}
		}
	}
}

void CollisionDetection::Update()
{
	detectionDelay += Timer::deltaTime;
	if (detectionDelay > DETECTION_TIMER)
	{
		if (goSize != currentScene->gameObjects.size())
		{
			this->Init();
		}
		detectionDelay = 0.0f;
		DetetectCollision();
	}
}

void CollisionDetection::DetetectCollision()
{
	if (collidingObjects.size() > 1)
	{
		std::list<Collision*> tempObjects = collidingObjects;
		for (std::list<Collision*>::iterator i = collidingObjects.begin(); i != collidingObjects.end(); i++)
		{
			for (std::list<Collision*>::iterator j = i++; j != collidingObjects.end(); j++)
			{
				Collision* firstCollision = (*i);
				Collision* secondCollision = (*j);
				Boundaries firstBoundary = GetBoundaries(static_cast<Sprite *>(firstCollision->gameObject));
				Boundaries secondBoundary = GetBoundaries(static_cast<Sprite *>(secondCollision->gameObject));
				if (firstBoundary.minX < secondBoundary.maxX && firstBoundary.minX > secondBoundary.minX &&
					firstBoundary.minY < secondBoundary.maxY && firstBoundary.minY > secondBoundary.minY)
				{
					firstCollision->CollisionEnter();
					secondCollision->CollisionEnter();
				}
			}
		}
	}
}

CollisionDetection::Boundaries CollisionDetection::GetBoundaries(Sprite* sprite)
{
	Vector2D<float> worldPosition = *Application::GetMainCamera()->
		WorldToCameraPosition(&(sprite->transform->position));
	Boundaries boundaries; 
	boundaries.minY = worldPosition.y;
	boundaries.minX = worldPosition.x;
	boundaries.maxX = worldPosition.x + (sprite->ActualTexture()->size.x * sprite->transform->scale.x);
	boundaries.maxY = worldPosition.y + (sprite->ActualTexture()->size.y * sprite->transform->scale.y);
	return boundaries;
}