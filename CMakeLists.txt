cmake_minimum_required(VERSION 3.27)
set(PROJECT_NAME mapsphere)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

file(GLOB SHADER_FILES "res/shaders/*.glsl")

foreach(SHADER_FILE ${SHADER_FILES})
    configure_file(${SHADER_FILE} ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
endforeach()

add_executable(${PROJECT_NAME} src/main.cpp
        core/shader/Shader.cpp
        core/shader/Shader.h
        core/shader/VBO.cpp
        core/shader/VBO.h
        core/shader/EBO.cpp
        core/shader/EBO.h
        core/shader/VAO.cpp
        core/shader/VAO.h)

add_subdirectory(3rdparty)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/3rdparty/glfw/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/3rdparty/glad/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/3rdparty/stb)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)
target_link_libraries(${PROJECT_NAME} PRIVATE stb)