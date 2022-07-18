#include "Audio/SoundDevice.h"
#include "Audio/SoundEffectsLibrary.h"
#include "Audio/MusicBuffer.h"
#include "Audio/SoundEffectsPlayer.h"
#include <iostream>
#include "root_directory.h"

namespace bb = BoomBoom;
using namespace std;

int main()
{
	std::cout << "starting...\n";
	SoundDevice* sd = LISTENER->Get();
	int Sound1 = SE_LOAD(bb::getPath("Resources/Audio/SFX/Sound2.wav").string().c_str());
	SoundEffectsPlayer sound_effects_player;
	ALint attunation = AL_INVERSE_DISTANCE_CLAMPED;
	sd->SetAttunation(attunation);
	sd->SetLocation(0.f, 0.f, 0.f);
	sd->SetOrientation(0.f, 1.f, 0.f, 0.f, 0.f, 1.f);
	//sound_effects_player.SetLooping(true);
	sound_effects_player.SetPosition(0.0f, 0.0f, 0.0f);
	sound_effects_player.Play(Sound1);
	while (sound_effects_player.isPlaying()) {
		cout << "Sound is Playing" << endl;
	}

	std::cout << "got here\n";

	return 0;
}