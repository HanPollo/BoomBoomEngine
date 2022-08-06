#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "root_directory.h"
#include "System/shaderClass.h"
#include "System/camera.h"
#include "System/Model.h"
#include "Entities/Cursor.h"
#include "Entities/Note.h"
#include "Stage/stage.h"
#include "System/Song.h"
#include "Entities/Controller.h"
#include "Audio/SoundDevice.h"
#include "Audio/SoundLibrary.h"


#include <iostream>



namespace bb = BoomBoom;
namespace Engine {
    enum Mode {
        EDIT,
        PLAY,
        PAUSE
    };
    //Engine Mode
    Mode mode = EDIT;
    bool firstMouse = true;

    // settings
    const unsigned int SCR_WIDTH = 900;
    const unsigned int SCR_HEIGHT = 700;
    // camera
    Camera camera(glm::vec3(0.05f, 1.0f, 3.0f));
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();
    float lastX = SCR_WIDTH / 2.0f;
    float lastY = SCR_HEIGHT / 2.0f;
    //Window and Shader
    GLFWwindow* window;
    shared_ptr<Shader> ourShader;
    //Song
    shared_ptr<Song> song;
    //Cursor & Controller
    shared_ptr<Cursor> cursor;
    //Controller controller;
    //Stage
    shared_ptr<Skybox> stage;
    shared_ptr<Model> guitar;
    glm::mat4 guitar_model = glm::mat4(1.0f);

    //Audio
    //shared_ptr<SoundDevice> sd = make_shared<SoundDevice>(LISTENER->Get());
    SoundDevice* sd = LISTENER->Get();
    vector<SoundSource> sound_sources;
    vector<int> sounds;
    int ID_Song;

    vector<Model> models;
    // timing
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    float playedTime = 0.0f;

    bool mapChange = true;

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        if (key == GLFW_KEY_F1 && action == GLFW_PRESS) {
            cout << "Edit Mode" << endl;
            mode = EDIT;
        }
        if (key == GLFW_KEY_F2 && action == GLFW_PRESS) {
            cout << "Play Mode" << endl;
            mode = PLAY;
        }

        if (mode == EDIT)
        {
            if (key == GLFW_KEY_M && action == GLFW_PRESS)
                camera.ProcessKeyboard(cam::FIX, deltaTime);
            if (key == GLFW_KEY_W && action == GLFW_PRESS)
                camera.ProcessKeyboard(cam::FORWARD, deltaTime);
            if (key == GLFW_KEY_S && action == GLFW_PRESS)
                camera.ProcessKeyboard(cam::BACKWARD, deltaTime);
            if (key == GLFW_KEY_A && action == GLFW_PRESS)
                camera.ProcessKeyboard(cam::LEFT, deltaTime);
            if (key == GLFW_KEY_D && action == GLFW_PRESS)
                camera.ProcessKeyboard(cam::RIGHT, deltaTime);
            if (key == GLFW_KEY_Q && action == GLFW_PRESS)
                song->SaveSong();
            if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
                cursor->ProcessKeyboard(cur::FORWARD);
                cout << "up:" << cursor->madeChanges << " ";
            }
            if (key == GLFW_KEY_DOWN && (action == GLFW_REPEAT || action == GLFW_PRESS)) {
                cursor->ProcessKeyboard(cur::BACKWARD);
                cout << "down:" << cursor->madeChanges << " ";
            }
            if (key == GLFW_KEY_LEFT && (action == GLFW_REPEAT || action == GLFW_PRESS))
                cursor->ProcessKeyboard(cur::LEFT);
            if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
                cursor->ProcessKeyboard(cur::RIGHT);
            if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
                cursor->note_buffer_left = 0;
            if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
                cursor->note_buffer_right = 0;

            if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
                if (!cursor->create_note_buffer) {
                    cursor->create_note_buffer = 1;
                    cout << "Creating Note" << endl;
                    cursor->createNote(*song);
                }
            }
            if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE)
                cursor->create_note_buffer = 0;
        }
        else if (mode == PLAY)
        {
            cout << "Play Mode" << endl;
        }
        else if (mode == PAUSE)
        {
            cout << "Pause" << endl;
        }
    }
    // glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        // make sure the viewport matches the new window dimensions; note that width and
        // height will be significantly larger than specified on retina displays.
        glViewport(0, 0, width, height);
    }
    // glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
    void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
    {
        float xpos = static_cast<float>(xposIn);
        float ypos = static_cast<float>(yposIn);

        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

        lastX = xpos;
        lastY = ypos;

        camera.ProcessMouseMovement(xoffset, yoffset);
    }

    // glfw: whenever the mouse scroll wheel scrolls, this callback is called
    // ----------------------------------------------------------------------
    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
    {
        camera.ProcessMouseScroll(static_cast<float>(yoffset));
    }

    void init()
    {
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
        window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Boom Boom Engine", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            //throw
        }
        //glfwSetKeyCallback(window, key_callback);
        glfwMakeContextCurrent(window);

        glfwSetKeyCallback(window, key_callback);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        glfwSetCursorPosCallback(window, mouse_callback);
        glfwSetScrollCallback(window, scroll_callback);

        // tell GLFW to capture our mouse
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        // glad: load all OpenGL function pointers
        // ---------------------------------------
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            //throw
        }
        //Song
        Song aux_song("default");
        song = make_shared<Song>(aux_song);

        glEnable(GL_DEPTH_TEST);

        //Audio
        //Listener Data
        ALint attunation = AL_INVERSE_DISTANCE_CLAMPED;
        sd->SetAttunation(attunation);
        sd->SetLocation(camera.Position[0], camera.Position[1], camera.Position[2]);
        sd->SetOrientation(camera.Front[0], camera.Front[1], camera.Front[2], camera.Up[0], camera.Up[1], camera.Up[2]);
        //Cursor Sound
        int sound2 = SE_LOAD(bb::getPath("Resources/Audio/SFX/CursorMove.wav").string().c_str());
        sounds.push_back(sound2);
        SoundSource source_2;
        sound_sources.push_back(source_2);
        //Song sound
        int ID_song = SE_LOAD(bb::getPath("Songs/" + song->name + "/" + song->name + ".wav").string().c_str());
        SoundSource song_source;

        // Create Shader
        Shader shader(bb::getPath("Resources/Shaders/default.vs").string().c_str(), bb::getPath("Resources/Shaders/default.fs").string().c_str());
        ourShader = make_shared<Shader>(shader);
        song->setNoteShaders(*ourShader);

        // load models
        Model rails(bb::getPath("Resources/Models/guitar/scene.gltf").string());
        guitar = make_shared<Model>(rails);
        Skybox skybox;
        stage = make_shared<Skybox>(skybox);
        Cursor aux_cursor;
        cursor = make_shared<Cursor>(aux_cursor);

        Model cursor_model(bb::getPath("Resources/Models/Cursor/cursor.obj").string());
        models.push_back(cursor_model);
        cursor->setModel(models[0]);
        cursor->setShader(*ourShader);
        //cursor->addAudioSource(sound_sources[0]);
        //cursor->addSound(sounds[0]);
        cursor->Update();

    }
    void processStage()
    {
        guitar_model = glm::translate(guitar_model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
        guitar_model = glm::scale(guitar_model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
        guitar_model = glm::rotate(guitar_model, glm::radians(-90.0f), glm::vec3(1, 0, 0));
        guitar_model = glm::rotate(guitar_model, glm::radians(-90.0f), glm::vec3(0, 0, 1));

    }
    void update(float dt)  //ProcessInput(float dt)
    {
        static const float refresh_rate = .01667f;
        static float stopwatch = .01667f;
        stopwatch += dt;
        if (stopwatch > refresh_rate)
        {
            if (mode == EDIT)
            {
                if (cursor->madeChanges || camera.wasMoved)
                {
                    stopwatch = 0.f;
                    cursor->madeChanges = false;
                    mapChange = true;
                    camera.wasMoved = false;
                    projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
                    view = camera.GetViewMatrix();
                    sd->SetLocation(camera.Position[0], camera.Position[1], camera.Position[2]);
                    sd->SetOrientation(camera.Front[0], camera.Front[1], camera.Front[2], camera.Up[0], camera.Up[1], camera.Up[2]);
                    cursor->Update();
                    song->UpdateNotes();
                }
            }
            else if (mode == PLAY)
            {
                cout << "Play Mode" << endl;
            }
            else if (mode == PAUSE)
            {
                cout << "Pause" << endl;
            }
        }

    }

    void render()
    {
        if (mode == EDIT)
        {
            if (mapChange) {
                mapChange = false;
                glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glEnable(GL_DEPTH_TEST);

                stage->Draw(view, projection);

                ourShader->use();
                ourShader->setMat4("projection", projection);
                ourShader->setMat4("view", view);

                //song->DrawNotes();

                cursor->Draw();
                

                ourShader->setMat4("model", guitar_model);
                guitar->Draw(*ourShader);

                glfwSwapBuffers(window);
            }
            glfwPollEvents();
        }
        else if (mode == PLAY)
        {
            cout << "Play Mode" << endl;
        }
        else if (mode == PAUSE)
        {
            cout << "Pause" << endl;
        }
    }

    bool isRunning()
    {
        return (!glfwWindowShouldClose(window));
    }

}