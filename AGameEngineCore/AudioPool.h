#include "EngineGlobal.h"
#pragma once
#include <list>

namespace AGameEngine 
{
	class AudioPool
	{
	public:
		AudioPool(void);
		~AudioPool(void);

		static int Init();
		static void Play();
		static void Destroy();
		static void AddSound(Mix_Chunk* sound, int* channel);
		static void Finished(int channel);
	private:
		typedef struct AudioContainer {
			int* channel;
			Mix_Chunk* sound;
		} AudioContainer;

		SDL_AudioSpec wanted;
		static void AudioCallback(void *udata, Uint8 *stream, int len);
		static std::list<AudioContainer*> inPoolAudio;
	};

}
