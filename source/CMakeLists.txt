cmake_minimum_required(VERSION 3.20)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)

project(main_project C CXX)

# Getting the parent directory twice
cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH REPO_DIR)

add_executable(main "main.cpp" "console_print.cpp" "console_print.h")
set_property(TARGET main PROPERTY CXX_STANDARD 20)
target_link_libraries(main PRIVATE
    "${REPO_DIR}/Libraries/glad/build/Release/glad.lib"
    "${REPO_DIR}/Libraries/glfw/build/src/Release/glfw3.lib"
)
target_include_directories(main PRIVATE
    "${REPO_DIR}/Libraries/glad/include"
    "${REPO_DIR}/Libraries/glfw/include"
)