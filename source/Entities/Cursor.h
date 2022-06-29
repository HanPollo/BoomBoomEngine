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
using namespace std;

/*
enum Cursor_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};
*/

class Cursor
{
public:
    Cursor(Shader &shader);
    ~Cursor();

    void Draw();

private:

    Model* cursor_model;
    Shader* cursor_shader;

    //void ProcessKeyboard(Camera_Movement direction, float deltaTime);
};
#endif //BOOMBOOMENGINE_NOTE_H