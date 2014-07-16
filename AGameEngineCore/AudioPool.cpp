#include "AudioPool.h"
#include "Debug.h"



AGameEngine::AudioPool::AudioPool(void)
{

}


AGameEngine::AudioPool::~AudioPool(void)
{
}

int AGameEngine::AudioPool::Init()
{
	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16SYS;
	int audio_channels = 2;
	int audio_buffers = 4096;

	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError());
		exit(1);
	}
	return(0);
}

void AGameEngine::AudioPool::Destroy()
{
	Mix_CloseAudio();
}
