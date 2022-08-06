#include "Application.h"

Application::Application()
{
	mode = EDIT;
    // build and compile shaders
    // -------------------------
    song.setNoteShaders(ourShader);
    // load models
    // -----------
    Model guitar(bb::getPath("Resources/Models/guitar/scene.gltf").string());
    Skybox stage;
    Cursor cursor;
    
    ID_Song = SE_LOAD(bb::getPath("Songs/" + song.name + "/" + song.name + ".wav").string().c_str());
}

Application::~Application()
{
}

void Application::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (mode == EDIT)
	{
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
            camera.ProcessKeyboard(cam::FIX, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera.ProcessKeyboard(cam::FORWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera.ProcessKeyboard(cam::BACKWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera.ProcessKeyboard(cam::LEFT, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera.ProcessKeyboard(cam::RIGHT, deltaTime);
	}
	else
	{

	}
}

void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
}

void Application::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
}

void Application::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}

void Application::init()
{

    ALint attunation = AL_INVERSE_DISTANCE_CLAMPED;
    sd->SetAttunation(attunation);
    sd->SetLocation(camera.Position[0], camera.Position[1], camera.Position[2]);
    sd->SetOrientation(camera.Front[0], camera.Front[1], camera.Front[2], camera.Up[0], camera.Up[1], camera.Up[2]);

    std::cout << "Welcome to Boom Boom Engine!\n" << "Here you can create Rhythm Games ;)\n";
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
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Boom Boom Engine", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        //throw
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
}

void Application::ProcessStage(float dt)
{
}


void Application::Update()
{
}

void Application::render()
{
}

bool Application::isRunning()
{
	return  (!glfwWindowShouldClose(window));
}
