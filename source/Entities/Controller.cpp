#include "Controller.h"

Controller::Controller()
{
	for (int i = 0; i < noteQuantity; i++)
	{
		Model model(bb::getPath("Resources/Models/note"+ to_string(i+1)+"/note.obj").string());
		models.push_back(model);
		
		ControllerNote note(i+1, 1.9f);
		notes.push_back(note);

	}
	for (int i = 0; i < noteQuantity; i++)
	{
		notes[i].setModel(models[i]);
	}
	key_map.push_back(GLFW_KEY_Z);
	key_map.push_back(GLFW_KEY_X);
	key_map.push_back(GLFW_KEY_C);
	key_map.push_back(GLFW_KEY_V);
	key_map.push_back(GLFW_KEY_B);
	
}

Controller::~Controller()
{
}

void Controller::setShader(Shader& shader)
{
	for (int i = 0; i < noteQuantity; i++)
	{
		notes[i].setShader(shader);
	}
}



void Controller::Draw()
{
	for (int i = 0; i < noteQuantity; i++)
	{
		notes[i].Draw();
	}
}


void Controller::ProcessInput(GLFWwindow* window)
{
	for (int i = 0; i < key_map.size(); i++) {
		if (glfwGetKey(window, key_map[i]) == GLFW_PRESS) {
			if (!notes[i].isPressed) {
				notes[i].isPressed = true;
				notes[i].Scale(0.8);
			}
		}
		if (glfwGetKey(window, key_map[i]) == GLFW_RELEASE) {
			if (notes[i].isPressed) {
				notes[i].isPressed = false;
				notes[i].Scale(1.25);
			}
		}
	}
}


void Controller::Update()
{
	for (int i = 0; i < noteQuantity; i++)
	{
		notes[i].Update();
		notes[i].ResetVectors();
	}
}
