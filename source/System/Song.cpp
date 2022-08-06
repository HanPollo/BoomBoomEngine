#include "Song.h"
#include "../Entities/Cursor.h"
#include "../Entities/Note.h"
#include "direct.h"

Song::Song()
{
	cout << "Created New Song" << endl;
	name = "default";
	Model note1(bb::getPath("Resources/Models/note1/note.obj").string());
	Model note2(bb::getPath("Resources/Models/note2/note.obj").string());
	Model note3(bb::getPath("Resources/Models/note3/note.obj").string());
	Model note4(bb::getPath("Resources/Models/note4/note.obj").string());
	Model note5(bb::getPath("Resources/Models/note5/note.obj").string());
	shared_models->push_back(note1);
	shared_models->push_back(note2);
	shared_models->push_back(note3);
	shared_models->push_back(note4);
	shared_models->push_back(note5);

}

Song::~Song()
{
}

Song::Song(string name)
{
	cout << "Loaded Song" << endl;
	this->name = name;
	Model note1(bb::getPath("Resources/Models/note1/note.obj").string());
	Model note2(bb::getPath("Resources/Models/note2/note.obj").string());
	Model note3(bb::getPath("Resources/Models/note3/note.obj").string());
	Model note4(bb::getPath("Resources/Models/note4/note.obj").string());
	Model note5(bb::getPath("Resources/Models/note5/note.obj").string());
	shared_models->push_back(note1);
	shared_models->push_back(note2);
	shared_models->push_back(note3);
	shared_models->push_back(note4);
	shared_models->push_back(note5);

	
	song = SE_LOAD(bb::getPath("Songs/"+name+"/"+name+".wav").string().c_str());
	SoundSource source;
	Asource = &source;
	
	LoadSong();
}


void Song::DrawNotes()
{
	
	if (notes.size() > 0) {
		for (int i = 0; i < notes.size(); i++) {
			notes[i].Draw();
		}
	}
}

void Song::UpdateNotes()
{
	if (notes.size() > 0) {
		for (int i = 0; i < notes.size(); i++) {
			notes[i].Update();
		}
	}
}


void Song::addNote(Cursor& cursor)
{
	Note new_note(cursor);
	new_note.setModel(shared_models->at(new_note.note - 1));
	new_note.setShader(cursor.getShader());
	notes.push_back(new_note);
}

void Song::setNoteShaders(Shader& shader)
{
	for (int i = 0; i < notes.size(); i++) {
		notes[i].setShader(shader);
	}
}

void Song::SaveSong()
{
	mkdir(bb::getPath("Songs/" + name).string().c_str());
	ofstream File(bb::getPath("Songs/" + name + "/data.song").string());
	File << notes.size() << endl;
	for (int i = 0; i < notes.size(); i++) {
		File << notes[i].note << " " << notes[i].beat << endl;
	}

}

void Song::LoadSong()
{
	int size;
	ifstream File(bb::getPath("Songs/" + name + "/data.song").string());
	File >> size;
	int n;
	float b;
	while (File >> n >> b) {
		Note new_note(n, b);
		new_note.setModel(shared_models->at(new_note.note - 1));
		notes.push_back(new_note);
	}



}

void Song::Play()
{
	for (int i = 0; i < notes.size(); i++) {
		notes[i].Advance();
	}
}

