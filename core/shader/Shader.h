//
// Created by aashik on 9/12/23.
//

#ifndef MAPSPHERE_SHADER_H
#define MAPSPHERE_SHADER_H

#include "glad/glad.h"
#include "string"
#include "fstream"
#include "sstream"
#include "iostream"
#include "cerrno"

static std::string readShader(const char *fileName);

class Shader {

public:
    GLuint ID;
    Shader(const char *vertexFile, const char *fragmentFile);

    void activateShader();
    void deleteShader();

    void compileErrors(unsigned int shader, const char *type);

private:
    GLuint createShader(unsigned int type, const char* shaderSource);
};


#endif //MAPSPHERE_SHADER_H
