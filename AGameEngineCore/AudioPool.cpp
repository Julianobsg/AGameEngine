#include "AudioPool.h"
#include "Debug.h"


std::list<AGameEngine::AudioPool::AudioContainer*> AGameEngine::AudioPool::inPoolAudio;

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
		Debug::Log("Unable to initialize audio: " + string(Mix_GetError()) + "/n");
		exit(1);
	}
	return(0);
}

void AGameEngine::AudioPool::Destroy()
{
	Mix_CloseAudio();
}

void AGameEngine::AudioPool::AudioCallback(void *udata, Uint8 *stream, int len)
{
	Debug::Log("Audio Callback");
}

void AGameEngine::AudioPool::AddSound(Mix_Chunk* sound, int* channel)
{
	AudioContainer* audio = new AudioContainer;
	audio->sound = sound;
	audio->channel = channel;

	inPoolAudio.push_back(audio);
}

void AGameEngine::AudioPool::Finished(int channel)
{
	for (list<AudioContainer*>::iterator it = inPoolAudio.begin(); it != inPoolAudio.end(); it++)
	{
		int* audioChannel = (*it)->channel;
		if (*audioChannel == channel)
		{
			*audioChannel = -1;
			return;
		}
	}
}


