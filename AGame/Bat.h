#pragma once
#include "Behaviour.h"
#include "Audio.h"

class Bat : public Behaviour
{
public:
	AGameEngine::Audio flyingSound;
	
	Bat(void);
	~Bat(void);

	void Update();

	void Init();

};

