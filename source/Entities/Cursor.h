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


class Cursor : public Model
{
    enum Cursor_Movement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };
public:
    Cursor();
    ~Cursor();

    const float SPEED = 0.1f;
    float beat = 0.5f; //Represents the beat the cursor is (Basically the Z axis).
    int note = 3;   //Represents the note the cursor is from 1 to 5.

    int note_buffer_left = 0; //A buffer to create discrete movemente when cursor changes notes.
    int note_buffer_right = 0;
    glm::vec3 forward_vector = glm::vec3(0.0f, 0.0f, -0.1f);
    glm::vec3 backward_vector = glm::vec3(0.0f, 0.0f, 0.1f);
    glm::vec3 right_vector = glm::vec3(2.0f, 0.0f, 0.0f);
    glm::vec3 left_vector = glm::vec3(-2.0f, 0.0f, 0.0f);

    glm::vec3 transform_vector = glm::vec3(0.0f, 0.0f, 0.0f);

    glm::mat4 transform_model = glm::mat4(1.0f);

    void UpdateCursor();
    void ProcessKeyboard(Cursor_Movement direction);
    void ProcessInput(GLFWwindow* window);

    //void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:

    //glm::mat4 transform_model = glm::mat4(1.0f);

    
};
#endif //BOOMBOOMENGINE_NOTE_H