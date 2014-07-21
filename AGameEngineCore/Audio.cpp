#include "Audio.h"
#include "Debug.h"
#include "AudioPool.h"
#include "EngineGlobal.h"

AGameEngine::Audio::Audio(string audioPath)
{
	this->audioPath = audioPath;
	this->channel = -1;
	sound = Mix_LoadWAV(audioPath.c_str());
	if(sound == NULL) {
		Debug::Log("Unable to load WAV file: " + audioPath + " Error: "
                   + string(Mix_GetError()) + "\n");
	}
	AudioPool::AddSound(sound, &channel);
}

AGameEngine::Audio::Audio(void)
{

}


AGameEngine::Audio::~Audio(void)
{
}

void AGameEngine::Audio::Play()
{
	PlayLooped(0);
}


bool AGameEngine::Audio::IsPlaying()
{
	return Mix_Playing(channel);
}

int AGameEngine::Audio::Volume()
{
	return sound->volume;
}

//Min volume 0
//Max volume 128
void AGameEngine::Audio::SetVolume(int volume)
{
	Mix_VolumeChunk(sound, volume);
}

//1 to repeate once
//2 for repeating twice and so on
//-1 for infinity loop
void AGameEngine::Audio::PlayLooped(int repeatTimes)
{
	if (!IsPlaying())
	{
		channel = Mix_PlayChannel(-1, sound, repeatTimes);

		Mix_ChannelFinished(AudioPool::Finished);
		if(channel == -1) {
			Debug::Log("Unable to play WAV file: " + string(Mix_GetError()) + "\n");
		}
	}
}

void AGameEngine::Audio::PlayLooped()
{
	PlayLooped(-1);
}
