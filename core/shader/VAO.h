//
// Created by aashik on 9/12/23.
//

#ifndef MAPSPHERE_VAO_H
#define MAPSPHERE_VAO_H


#include "glad/glad.h"
#include "VBO.h"

class VAO {

public:
    GLuint ID;
    VAO();

    void linkAttribute(VBO VBO, GLuint layout, GLint numComp, GLenum type, GLsizei stride, void *offset);
    void bindVAO();
    void unBindVAO();
    void deleteVAO();
};


#endif //MAPSPHERE_VAO_H
