#ifndef BOOMBOOMENGINE_STAGE_H
#define BOOMBOOMENGINE_STAGE_H

#include "glad/glad.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "stb_image.h"

#include "../System/BasicMesh.h"
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

class Skybox
{
public:
    Skybox();
    Skybox(string dir);
    ~Skybox();

    void Draw(const glm::mat4& view, const glm::mat4& projection);
    string directory;

private:
    unsigned int cubemapTexture;

    GLuint VAO;
    GLuint VBO;

    Shader* shader;

    GLuint loadCubemap(std::vector<std::string> faces);
};


#endif //BOOMBOOMENGINE_MODEL_H
