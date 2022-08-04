#pragma once

#include "glad/glad.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "stb_image.h"

#include "../System/BasicMesh.h"
#include "../System/Model.h"
#include "../System/shaderClass.h"
#include "../root_directory.h"
#include "ControllerNote.h"
#include "../System/GameObject.h"
namespace bb = BoomBoom;

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <GLFW/glfw3.h>
using namespace std;

class Controller
{
public:
	Controller();
	~Controller();

	void setShader(Shader& shader);

	//void addNote(Note note);
	void Draw();
	int getKey(int noteNum);

	void ProcessInput(GLFWwindow* window);

	void Update();

private:
	int noteQuantity = 5;
	vector<ControllerNote> notes;
	vector<Model> models;
	vector<int> key_map;

};