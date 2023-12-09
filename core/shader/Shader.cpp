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
    compileErrors(ID, "PROGRAM");
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

void Shader::activateShader() {

    glUseProgram(ID);
}

void Shader::deleteShader() {

    glDeleteProgram(ID);
}

GLuint Shader::createShader(unsigned int type, const char* shaderSource) {

    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);
    compileErrors(shader, type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT");
    return shader;
}

void Shader::compileErrors(unsigned int shader, const char *type) {

    GLint hasCompiled;
    char infoLog[1024];

    const char *program = "PROGRAM";
    if (type != program) {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE) {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << std::endl;
        }
    } else {
        glGetProgramiv(shader, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE) {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << std::endl;
        }
    }
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