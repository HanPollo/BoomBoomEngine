#pragma once
#ifndef BOOMBOOMENGINE_NOTE_H
#define BOOMBOOMENGINE_NOTE_H

#include "glad/glad.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "stb_image.h"

#include "../System/BasicMesh.h"
#include "../System/Model.h"
#include "../System/shaderClass.h"
#include "../root_directory.h"
#include "Cursor.h"
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
#endif //BOOMBOOMENGINE_NOTE_H

class Note : public GameObject
{
public:
	Note(Cursor& cursor);
	Note(int note, float beat);
	~Note();

	void testDrawNote(Shader& shader);

	const float SPEED = 0.1f;
	int note;
	float beat;

	glm::vec3 forward_vector = glm::vec3(0.0f, 0.0f, -0.1f);
	glm::vec3 backward_vector = glm::vec3(0.0f, 0.0f, 0.1f);

	void Advance();


};