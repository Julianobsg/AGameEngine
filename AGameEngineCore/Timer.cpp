#include "Timer.h"
#include <string.h>


Timer::Timer(void)
{
}


Timer::~Timer(void)
{
}

Uint32 Timer::frameStored[FRAMES_STORED] = {NULL};
Uint32 Timer::frameCount = 0;
float Timer::framesPerSecond = 60;
Uint32 Timer::gameTicks = 0;

void Timer::Init()
{
	// Set all frame times to 0ms.
	memset(frameStored, 0, sizeof(frameStored));
	frameCount = 0;
	framesPerSecond = 60;
	gameTicks = SDL_GetTicks();
}

void Timer::WaitForMiliseconds(float ms)
{
	SDL_Delay(ms);
}

//Got this algorithm on internet, so far so good, check after if there is a better solution
//http://sdl.beuc.net/sdl.wiki/SDL_Average_FPS_Measurement
void Timer::CalcFPS()
{
	Uint32 frametimesindex;
	Uint32 getticks;
	Uint32 count;
	Uint32 i;

	// frametimesindex is the position in the array. It ranges from 0 to FRAME_VALUES.
	// This value rotates back to 0 after it hits FRAME_VALUES.
	frametimesindex = frameCount % FRAMES_STORED;

	// store the current time
	getticks = SDL_GetTicks();

	// save the frame time value
	frameStored[frametimesindex] = getticks - gameTicks;

	// save the last frame time for the next fpsthink
	gameTicks = getticks;

	// increment the frame count
	frameCount++;

	// Work out the current framerate

	// The code below could be moved into another function if you don't need the value every frame.

	// I've included a test to see if the whole array has been written to or not. This will stop
	// strange values on the first few (FRAME_VALUES) frames.
	if (frameCount < FRAMES_STORED) {

		count = frameCount;

	} else {

		count = FRAMES_STORED;

	}

	// add up all the values and divide to get the average frame time.
	framesPerSecond = 0;
	for (i = 0; i < count; i++) {

		framesPerSecond += frameStored[i];

	}

	framesPerSecond /= count;

	// now to make it an actual frames per second value...
	framesPerSecond = 1000.f / framesPerSecond;
	deltaTime = 1 / framesPerSecond;
}

float Timer::deltaTime;

