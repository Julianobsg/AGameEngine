#include "EngineGlobal.h"
#pragma once

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
	private:
		SDL_AudioSpec wanted;

	};

}
