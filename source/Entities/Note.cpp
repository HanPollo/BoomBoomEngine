#include "Note.h"

Note::Note(int note, float beat, const string& path) : Model(path) {
	this->note = note;
	this->beat = beat;
	if (note == 1) {
		position = glm::vec3(-3.95f, -0.1f, beat);
	}
	else if (note == 2) {
		position = glm::vec3(-1.95f, -0.1f, beat);
	}
	else if (note == 3) {
		position = glm::vec3(0.05f, -0.1f, beat);
	}
	else if (note == 4) {
		position = glm::vec3(2.05f, -0.1f, beat);
	}
	else if (note == 5) {
		position = glm::vec3(4.05f, -0.1f, beat);
	}
	cout << position[0] << endl;
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));
	
}

Note::~Note()
{
}

void Note::testDrawNote(Shader& shader)
{
	Draw(shader);
}
