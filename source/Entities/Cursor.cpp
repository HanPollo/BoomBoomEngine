#include "Cursor.h"

const string& PATH = bb::getPath("Resources/Models/Cursor/cursor.obj").string();

Cursor::Cursor() : Model(PATH)
{   
    transform_model = glm::translate(transform_model, glm::vec3(0.05f, -0.1f, 0.5f)); // translate it down so it's at the center of the scene
    transform_model = glm::scale(transform_model, glm::vec3(0.05f, 0.05f, 0.05f));	// it's a bit too big for our scene, so scale it down
}

Cursor::~Cursor()
{
}


void Cursor::UpdateCursor()
{
    //transform_model = glm::translate(transform_model, glm::vec3(0.0f, 0.0f, 0.01f)*0.1f); // translate it down so it's at the center of the scene
    //transform_model = glm::scale(transform_model, glm::vec3(0.05f, 0.05f, 0.05f));	// it's a bit too big for our scene, so scale it down
    //transform_model = glm::rotate(transform_model, glm::radians(-1.0f), glm::vec3(0, 1, 0));
    //model2 = glm::rotate(model, glm::radians(-90.0f), glm::vec3(0, 0, 1));
    transform_model = glm::translate(transform_model, transform_vector);
    transform_vector = glm::vec3(0.0f, 0.0f, 0.0f);
    //note_buffer = 0;
    
}

void Cursor::ProcessKeyboard(Cursor_Movement direction)
{
    
    float velocity = SPEED;
    if (direction == FORWARD) {
        transform_vector = forward_vector * velocity;
        beat += forward_vector[2] * velocity;
    }
    if (direction == BACKWARD) {
        transform_vector = backward_vector * velocity;
        beat += backward_vector[2] * velocity;
    }
    if (direction == LEFT) {
        if (!note_buffer_left && note != 1) {
            transform_vector = left_vector;
            note--;
            note_buffer_left = 1;
        }
    }
    if (direction == RIGHT)
        if (!note_buffer_right && note != 5) {
            transform_vector = right_vector;
            note++;
            note_buffer_right = 1;
        }
        
}

void Cursor::ProcessInput(GLFWwindow* window, Song& song)
{
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        ProcessKeyboard(FORWARD);
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        ProcessKeyboard(BACKWARD);  
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) 
        ProcessKeyboard(LEFT);
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) 
            ProcessKeyboard(RIGHT);
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
    string path = "";
    if (note == 1) {
        path = "Resources/Models/note1/note.obj";
    }
    else if (note == 2) {
        path = "Resources/Models/note2/note.obj";
    }
    else if (note == 3) {
        path = "Resources/Models/note3/note.obj";
    }
    else if (note == 4) {
        path = "Resources/Models/note4/note.obj";
    }
    else{
        path = "Resources/Models/note5/note.obj";
    }
    Note new_note(note, beat, bb::getPath(path).string());
    Note* note_ptr = &new_note;
    song.addNote(note_ptr);
    
}
