#include "stdafx.h"
#include "EnemyCollision.h"
#include "Debug.h"
#include "Shot.h"
#include "Application.h"
#include "Ship.h"


EnemyCollision::EnemyCollision()
{
}


EnemyCollision::~EnemyCollision()
{
}

void EnemyCollision::Init()
{
}

void EnemyCollision::Update()
{

}

void EnemyCollision::CollisionEnter(Collision* other)
{
	if (other->tag == "Shot")
	{
		Shot* thisShot = (Shot*) other->gameObject;
		thisShot->Destroy();
		((Enemy*) gameObject)->Die();
	}
	else if (other->tag == "Player")
	{
		((Ship*)other->gameObject)->Die();
	}
}
