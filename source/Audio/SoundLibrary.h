#pragma once
#include <AL\al.h>
#include <vector>


#define SE_LOAD SoundLibrary::Get()->Load
#define SE_UNLOAD SoundLibrary::Get()->UnLoad

class SoundLibrary
{
public:
	static SoundLibrary* Get();

	ALuint Load(const char* filename);
	bool UnLoad(const ALuint& bufferId);

private:
	SoundLibrary();
	~SoundLibrary();

	std::vector<ALuint> p_SoundEffectBuffers;
};

