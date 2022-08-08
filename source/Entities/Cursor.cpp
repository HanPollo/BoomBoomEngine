#include "Cursor.h"
#include "../System/Song.h"


Cursor::Cursor() : GameObject()
{   
    transform_model = glm::translate(transform_model, glm::vec3(0.05f, -0.1f, 0.5f)); // translate it down so it's at the center of the scene
    transform_model = glm::scale(transform_model, glm::vec3(0.05f, 0.05f, 0.05f));	// it's a bit too big for our scene, so scale it down
}

Cursor::~Cursor()
{
}

void Cursor::Update()
{
    //transform_model = glm::translate(transform_model, glm::vec3(0.0f, 0.0f, 0.01f)*0.1f); // translate it down so it's at the center of the scene
    //transform_model = glm::scale(transform_model, glm::vec3(0.05f, 0.05f, 0.05f));	// it's a bit too big for our scene, so scale it down
    //transform_model = glm::rotate(transform_model, glm::radians(-1.0f), glm::vec3(0, 1, 0));
    //model2 = glm::rotate(model, glm::radians(-90.0f), glm::vec3(0, 0, 1));
    transform_model = glm::translate(transform_model, translate_vector);
    translate_vector = glm::vec3(0.0f, 0.0f, 0.0f);
    position = glm::vec3(transform_model[3][0], transform_model[3][1], transform_model[3][2]);
    if (HasAudioSource())
        object_Asource->SetPosition(position[0], position[1], position[2]);

    object_shader->setMat4("model", transform_model);
    //Draw();
    //note_buffer = 0;

}

void Cursor::ProcessKeyboard(cur::Cursor_Movement direction)
{
    madeChanges = true;
    float velocity = SPEED;
    if (direction == cur::FORWARD) {
        if (transform_model[3][2] > -2.95) {
            translate_vector = forward_vector * velocity;
            beat = transform_model[3][2];
        }
    }
    if (direction == cur::BACKWARD) {
        if (transform_model[3][2] < 1.9f) {
            translate_vector = backward_vector * velocity;
            beat = transform_model[3][2];
        }
    }
    if (direction == cur::LEFT) {
        if (!note_buffer_left && note != 1) {
            Play();
            translate_vector = left_vector;
            note--;
            note_buffer_left = 1;
        }
    }
    if (direction == cur::RIGHT)
        if (!note_buffer_right && note != 5) {
            Play();
            translate_vector = right_vector;
            note++;
            note_buffer_right = 1;
        }
        
}

void Cursor::ProcessInput(GLFWwindow* window, Song& song)
{
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        song.SaveSong(0.f);
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        ProcessKeyboard(cur::FORWARD);
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        ProcessKeyboard(cur::BACKWARD);
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        ProcessKeyboard(cur::LEFT);
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        ProcessKeyboard(cur::RIGHT);
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_RELEASE)
        note_buffer_left = 0;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_RELEASE)
        note_buffer_right = 0;

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        if (!create_note_buffer) {
            create_note_buffer = 1;
            cout << "Creating Note" << endl;
            createNote(song);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
        create_note_buffer = 0;
}


void Cursor::createNote(Song& song) {
    madeChanges = true;
    song.addNote(*this);
}

ALuint Cursor::getSourceID()
{
    return object_Asource->getSourceID();
}

