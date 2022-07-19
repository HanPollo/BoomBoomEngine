#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../root_directory.h"
#include "shaderClass.h"
#include "camera.h"
#include "Model.h"
#include "../Entities/Cursor.h"
#include "../Stage/stage.h"

#include <iostream>

namespace bb = BoomBoom;

class Window {

private:
    //Callbacks and other functions


    int m_Width, m_Height;
    const char* m_Title;
    bool m_VSync;
    void Initialize();

public:

    GLFWwindow* m_Window;
    Window(const char* title, int width, int height, bool vsync);
    ~Window();
    void Clear(float x, float y, float z);
    void Update();
    bool Closed() { return glfwWindowShouldClose(m_Window); }
};