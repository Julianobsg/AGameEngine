#include "Audio.h"
#include "SDL_mixer.h"
#include "Debug.h"
#include "AudioPool.h"

AGameEngine::Audio::Audio(string audioPath)
{
	this->audioPath = audioPath;
	sound = Mix_LoadWAV(audioPath.c_str());
	if(sound == NULL) {
		Debug::Log("Unable to load WAV file: " + string(Mix_GetError()) + "\n");
	}
}

AGameEngine::Audio::Audio(void)
{

}


AGameEngine::Audio::~Audio(void)
{
	Mix_FreeChunk(sound);
}

void AGameEngine::Audio::Play()
{
	int channel;

	channel = Mix_PlayChannel(-1, sound, 0);
	if(channel == -1) {
		Debug::Log("Unable to play WAV file: " + string(Mix_GetError()) + "\n");
	}
}

bool AGameEngine::Audio::IsPlaying()
{
	return false;
}

int AGameEngine::Audio::Volume()
{
	return 0;
}

void AGameEngine::Audio::SetVolume(int volume)
{

}
