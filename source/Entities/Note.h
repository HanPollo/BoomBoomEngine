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

class Note : public Model
{
public:
	Note(int note, float beat, const string& path);
	~Note();

	void testDrawNote(Shader& shader);

	int note;
	float beat;

	glm::vec3 forward_vector = glm::vec3(0.0f, 0.0f, -0.1f);
	glm::vec3 backward_vector = glm::vec3(0.0f, 0.0f, 0.1f);
	glm::vec3 right_vector = glm::vec3(2.0f, 0.0f, 0.0f);
	glm::vec3 left_vector = glm::vec3(-2.0f, 0.0f, 0.0f);

	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);

	glm::mat4 model = glm::mat4(1.0f);


};