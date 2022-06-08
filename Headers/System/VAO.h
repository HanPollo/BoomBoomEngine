//
// Created by pollo on 4/27/2022.
//

#ifndef BOOMBOOMENGINE_VAO_H
#define BOOMBOOMENGINE_VAO_H

#include<glad/glad.h>
#include"VBO.h"

class VAO
{
public:
    // ID reference for the Vertex Array Object
    GLuint ID;
    // Constructor that generates a VAO ID
    VAO();

    // Links a VBO Attribute such as a position or color to the VAO
    void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
    // Binds the VAO
    void Bind();
    // Unbinds the VAO
    void Unbind();
    // Deletes the VAO
    void Delete();
};

#endif //BOOMBOOMENGINE_VAO_H
