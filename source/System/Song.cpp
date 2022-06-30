#include "Song.h"

Song::Song()
{
	cout << "Created New Song" << endl;
	name = "default";
}

Song::~Song()
{
}

void Song::DrawNotes(Shader& shader)
{
	if (notes.size() > 0) {
		cout << "1" << endl;
		for (int i = 0; i < sizeof(notes); i++) {
			cout << "2" << endl;
			shader.use();
			cout << "3" << endl;
			shader.setMat4("model", notes[i]->model);
			cout << "4" << endl;
			notes[i]->Draw(shader);
			cout << "5" << endl;
		}
	}
}

void Song::addNote(Note* new_note)
{
	notes.push_back(new_note);
}

