//
// Created by aashik on 9/12/23.
//

#include "Shader.h"

Shader::Shader(const char *vertexFile, const char *fragmentFile) {

    std::string vertexCode = readShader(vertexFile);
    std::string fragmentCode = readShader(fragmentFile);

    const char *vertexSource = vertexCode.c_str();
    const char *fragmentSource = fragmentCode.c_str();


    ID = glCreateProgram();
    GLuint vertexShader = createShader(GL_VERTEX_SHADER, vertexSource);
    GLuint fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentSource);

    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

void Shader::activateShader() {

    glUseProgram(ID);
}

void Shader::deleteShader() {

    glDeleteProgram(ID);
}

std::string readShader(const char *fileName) {

    std::ifstream in(fileName, std::ios::binary);
    if (in) {
        std::string shaderContent;
        in.seekg(0, std::ios::end);
        shaderContent.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&shaderContent[0], (signed int) shaderContent.size());
        in.close();
        return shaderContent;
    }
    throw (errno);
}

GLuint createShader(unsigned int type, const char* shaderSource) {

    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);
    return shader;
}