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
		void PlayLooped();
		void PlayLooped(int repeatTimes);
		bool IsPlaying();

		int Volume();

		void SetVolume(int volume);
		string audioPath;
	private:
		Mix_Chunk* sound;
		int channel;
	};
}

