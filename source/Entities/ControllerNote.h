#pragma once

#include "Note.h"

class ControllerNote : public Note
{
public:
	ControllerNote(int note, float beat);
	~ControllerNote();

	bool isPressed = 0;

};