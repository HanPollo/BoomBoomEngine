#ifndef BOOMBOOMENGINE_NOTE_H
#define BOOMBOOMENGINE_NOTE_H

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <vector>

#include"shaderClass.h"
#include "../System/Model.h"

enum Note_Movement{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Note
{
public:
    Model model;
    glm::vec3 Position;

};
#endif //BOOMBOOMENGINE_NOTE_H