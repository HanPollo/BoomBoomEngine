#include "component.h"

void render(const Entity& entity, Shader& shader)
{
    bool hasModel = false;
    bool hasPosition = false;
    for (auto component : entity.components)
    {
        ModelComp* model_comp = dynamic_cast<ModelComp*>(component.get());
        PositionComp* pos_comp = dynamic_cast<PositionComp*>(component.get());
 
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(pos_comp->x, pos_comp->y, pos_comp->z));

        shader.setMat4("model", transform);
        model_comp->model->Draw(shader);

        if (model_comp != nullptr)
        {
            hasModel = true;
        }
        if (pos_comp != nullptr)
        {
            hasPosition = true;
        }
    }


    if (!hasModel)
    {
        std::cout << entity.name << " does not have a model." << std::endl;
    }
    if (!hasPosition)
    {
        std::cout << entity.name << " does not have a position." << std::endl;
    }
}





void ModelComp::setModel(std::string const& path)
{
    auto auxMod = std::make_shared<Model>(Model::Model(path));
    this->model = auxMod;
}

void PositionComp::setPos(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
