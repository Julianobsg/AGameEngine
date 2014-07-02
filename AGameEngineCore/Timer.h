#pragma once
#include "EngineGlobal.h"

class Timer
{
#define FRAMES_STORED 10
public:
	static float framesPerSecond;
	
	static Uint32 frameCount;
	static Uint32 gameTicks;
	static Uint32 frameStored[FRAMES_STORED];
	
	Timer(void);
	~Timer(void);
	
	static void Init();
	static void WaitForMiliseconds(float ms);
	static void CalcFPS();

};

