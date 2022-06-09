//
// Created by pollo on 4/27/2022.
//

#ifndef BOOMBOOMENGINE_EBO_H
#define BOOMBOOMENGINE_EBO_H

#include"glad/glad.h"
#include<vector>

class EBO
{
public:
    // ID reference of Elements Buffer Object
    GLuint ID;
    // Constructor that generates a Elements Buffer Object and links it to indices
    EBO(std::vector<GLuint>& indices);

    // Binds the EBO
    void Bind();
    // Unbinds the EBO
    void Unbind();
    // Deletes the EBO
    void Delete();
};

#endif //BOOMBOOMENGINE_EBO_H
