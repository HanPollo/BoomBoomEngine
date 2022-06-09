#ifndef BOOMBOOMENGINE_COMPONENT_H
#define BOOMBOOMENGINE_COMPONENT_H

#include "../System/Model.h"
#include "../System/shaderClass.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct Component
{
    virtual void f() {}  // must be polymorphic to use runtime-checked dynamic_cast
};

using ComponentPtr = std::shared_ptr<Component>;

struct Entity
{
    std::string name;
    std::vector<ComponentPtr> components;
};


struct ModelComp : Component
{
    int modelId;
    std::shared_ptr<Model> model;

    ModelComp(int modelId_) : modelId(modelId_) {};
    void setModel(std::string const& path); 
};

struct PositionComp : Component
{
    int positionId;
    float x = 0;
    float y = 0;
    float z = 0;

    PositionComp(int positionId_) : positionId(positionId_) {};
    void setPos(float x, float y, float z);
};


void render(const Entity& entity, Shader &shader);

#endif //BOOMBOOMENGINE_COMPONENT_H