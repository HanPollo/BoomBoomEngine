#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <valarray>
#include "console_print.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

// Vertices coordinates
GLfloat vertices[] =
        {
                -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
                0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
                0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
                -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
                0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
                0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
        };

// Indices for vertices order
GLuint indices[] =
        {
                0, 3, 5, // Lower left triangle
                3, 2, 4, // Lower right triangle
                5, 4, 1 // Upper triangle
        };

int main()
{
    print_welcome();

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "BoomBoomEngine", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    // build and compile our shader program
    // ------------------------------------
    // Generates Shader object using shaders defualt.vert and default.frag
    Shader shaderProgram("../Resources/Shaders/default.vert", "../Resources/Shaders/default.frag");



    // Generates Vertex Array Object and binds it
    VAO VAO1;
    VAO1.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));

    // Links VBO to VAO
    VAO1.LinkVBO(VBO1, 0);
    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();


    // uncomment this call to draw in wireframe polygons.
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Tell OpenGL which Shader Program we want to use
        shaderProgram.Activate();
        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();
        // Draw primitives, number of indices, datatype of indices, index of indices
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    // Delete all the objects we've created
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}