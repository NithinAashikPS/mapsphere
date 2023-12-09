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
static GLuint createShader(unsigned int type, const char* shaderSource);

class Shader {

public:
    GLuint ID;
    Shader(const char *vertexFile, const char *fragmentFile);

    void activateShader();
    void deleteShader();
};


#endif //MAPSPHERE_SHADER_H
