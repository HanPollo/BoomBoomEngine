cmake_minimum_required(VERSION 3.20)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)
project(boomBoomEngine C CXX)

# Set variables
set(ENTITY_FILES
        )
set(COMPONENT_FILES
        )
set(SYSTEM_FILES
        source/System/shaderClass.cpp
        source/System/VBO.cpp
        source/System/EBO.cpp
        source/System/VAO.cpp
        source/System/texture.cpp
        source/System/Camera.cpp
        source/System/Mesh.cpp source/System/Model.cpp source/System/shape.cpp source/System/basic_shapes.cpp)


set(SOURCE_FILES
        source/main.cpp
        3rdParty/glad/src/glad.c
        ${ENTITY_FILES}
        ${COMPONENT_FILES}
        ${SYSTEM_FILES}
        source/stb.cpp)
set(CONSOLE_PRINT
        source/console_print.cpp
        source/console_print.h)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(3rdParty/glfw)

# GLM
include_directories(3rdParty/glm)

include_directories(3rdParty/glad/include)
include_directories(3rdParty/glfw/include)

include_directories(3rdParty/stb)

include_directories(3rdParty/json)

include_directories(Headers/Entities)
include_directories(Headers/Components)
include_directories(Headers/System)

add_executable(main source/main.cpp ${CONSOLE_PRINT} ${SOURCE_FILES})

target_link_libraries(main glfw)

set_property(TARGET main PROPERTY CXX_STANDARD 20)

