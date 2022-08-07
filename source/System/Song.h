#pragma once


#include "../root_directory.h"
#include "Model.h"
#include "../Audio/SoundSource.h"
#include "../Audio/SoundLibrary.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <filesystem>

namespace bb = BoomBoom;
using namespace std;

class Cursor;
class Note;
class Song {
public:
	Song();
	~Song();

	Song(string name);

	string name;
	vector<Note> notes;
	vector<Model> models;
	shared_ptr<vector<Model>> shared_models = make_shared<vector<Model>>(move(models));
	SoundSource* Asource = nullptr;
	long long score = 0;

	int song;
	void DrawNotes();
	void UpdateNotes();
	void addNote(Cursor& cursor);
	void setNoteShaders(Shader& shader);

	void addScore(long long x);
	void substractScore(long long x);
	
	void SaveSong();
	void LoadSong();

	//void PlaySong();
	void Play(float dt);
};
