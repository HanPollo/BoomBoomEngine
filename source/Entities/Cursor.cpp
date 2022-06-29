#include "Cursor.h"

Cursor::Cursor(Shader &shader)
{
    Model cursor(bb::getPath("Resources/Models/Cursor/cursor.obj").string());
    cursor_model = &cursor;
    cursor_shader = &shader;
  
}

Cursor::~Cursor()
{
}

void Cursor::Draw()
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
    model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1, 0, 0));
    model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(0, 0, 1));
    cursor_shader->setMat4("model", model);
    cursor_model->Draw(*cursor_shader);
    
}

