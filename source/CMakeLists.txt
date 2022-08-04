set(BOOM_BOOM_HEADERS
        System/BasicMesh.h
        System/camera.h
        System/EBO.h
        System/Model.h
        System/shaderClass.h
        System/VAO.h
        System/VBO.h
        System/Window.h
        System/Song.h
        System/GameObject.h
        Components/component.h
        Entities/Note.h
        Entities/Cursor.h
        Entities/ControllerNote.h
        Entities/Controller.h
        Stage/stage.h
        Audio/SoundDevice.h
        Audio/SoundLibrary.h
        Audio/SoundSource.h
        Audio/OpenALErrorCheck.h
        Audio/AudioManager.h
        )
set(BOOM_BOOM_SOURCES
        System/BasicMesh.cpp
        System/Camera.cpp
        System/EBO.cpp
        System/Model.cpp
        System/shaderClass.cpp
        System/VAO.cpp
        System/VBO.cpp
        System/Song.cpp
        System/GameObject.cpp
        #System/Window.cpp
        Components/component.cpp
        Entities/Cursor.cpp
        Entities/Note.cpp
        Entities/ControllerNote.cpp
        Entities/Controller.cpp
        Stage/stage.cpp 
        Audio/SoundDevice.cpp
        Audio/SoundLibrary.cpp
        Audio/SoundSource.cpp
        Audio/AudioManager.cpp
        )
add_library(BoomEngine STATIC ${BOOM_BOOM_SOURCES} ${BOOM_BOOM_HEADERS} System/system.h ${Shaders})
if (MSVC)
    target_compile_options(BoomEngine PUBLIC /wd5033)
endif(MSVC)
target_include_directories(BoomEngine PRIVATE ${THIRD_PARTY_INCLUDE_DIRECTORIES} BOOM_BOOM_INCLUDE_DIRECTORY)
target_link_libraries(BoomEngine PRIVATE ${THIRD_PARTY_LIBRARIES})
set_property(TARGET BoomEngine PROPERTY CXX_STANDARD 20)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${BOOM_BOOM_SOURCES} ${BOOM_BOOM_HEADERS})