set(BOOM_BOOM_SYSTEM_HEADERS
        BasicMesh.h
        camera.h
        EBO.h
        Model.h
        shaderClass.h
        VAO.h
        VBO.h
        )
set(BOOM_BOOM_SYSTEM_SOURCES
        BasicMesh.cpp
        Camera.cpp
        EBO.cpp
        Model.cpp
        shaderClass.cpp
        VAO.cpp
        VBO.cpp
        )
add_library(system STATIC ${BOOM_BOOM_SYSTEM_SOURCES} ${BOOM_BOOM_SYSTEM_HEADERS} system.h ${Shaders})
if (MSVC)
    target_compile_options(system PUBLIC /wd5033)
endif(MSVC)
target_include_directories(system PRIVATE ${THIRD_PARTY_INCLUDE_DIRECTORIES} BOOM_BOOM_INCLUDE_DIRECTORY)
target_link_libraries(system PRIVATE ${THIRD_PARTY_LIBRARIES})
set_property(TARGET system PROPERTY CXX_STANDARD 20)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${BOOM_BOOM_SYSTEM_SOURCES} ${BOOM_BOOM_SYSTEM_HEADERS})