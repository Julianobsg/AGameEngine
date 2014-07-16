#pragma once
#include "EngineGlobal.h"
#include <string>

using namespace std;

namespace AGameEngine {
	class Audio
	{
	public:
		Audio(void);
		Audio(string audioPath);
		~Audio(void);

		void Play();
		bool IsPlaying();

		int Volume();

		void SetVolume(int volume);
		string audioPath;
		Mix_Chunk* sound;
	};
}

