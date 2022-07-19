#pragma once
#include "SoundDevice.h"
#include "SoundSource.h"
#include "SoundLibrary.h"
#include "../root_directory.h"
#include <vector>

namespace bb = BoomBoom;
using namespace std;

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	void CreateDevice();
	void CreateSound();
	void CreateBuffer();

	void setSoundtoSource();

private:
	SoundDevice MainSoundDevice;
	vector<SoundDevice> Devices;
	vector<int> Sounds;
	vector<SoundSource> Sources;

	SoundSource MusicSource;

};