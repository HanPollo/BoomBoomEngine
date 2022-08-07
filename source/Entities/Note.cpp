#include "Note.h"

Note::Note() : GameObject()
{
	note = 3;
	beat = 0.5f;
	float note_pos = -0.15f + (note - 1) * 0.1f;
	transform_model = glm::translate(transform_model, glm::vec3(note_pos, -0.1f, beat));
	transform_model = glm::scale(transform_model, glm::vec3(0.05f, 0.05f, 0.05f));
}

Note::Note(Cursor& cursor) : GameObject() {
	note = cursor.note;
	beat = cursor.beat;
	float note_pos = -0.15f + (note-1)*0.1f;
	transform_model = glm::translate(transform_model, glm::vec3(note_pos, -0.1f, beat));
	transform_model = glm::scale(transform_model, glm::vec3(0.05f, 0.05f, 0.05f));	
}
Note::Note(int note, float beat) : GameObject() {
	this->note = note;
	this->beat = beat;
	float note_pos = -0.15f + (note - 1) * 0.1f;
	transform_model = glm::translate(transform_model, glm::vec3(note_pos, -0.1f, beat));
	transform_model = glm::scale(transform_model, glm::vec3(0.05f, 0.05f, 0.05f));
}

Note::~Note()
{
}

void Note::Advance(float dt)
{
	if (beat < 3.0f) {
		translate_vector[2] = backward_vector[2] += (dt * SPEED); //b_v += dt* speed
		beat = transform_model[3][2];
	}
	else
		translate_vector = glm::vec3(0.0f, 0.0f, 0.0f);

}


