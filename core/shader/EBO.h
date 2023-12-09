//
// Created by aashik on 9/12/23.
//

#ifndef MAPSPHERE_EBO_H
#define MAPSPHERE_EBO_H


#include "glad/glad.h"

class EBO {

public:
    GLuint ID;
    EBO(GLuint* indices, GLsizeiptr size);

    void bindEBO();
    void unBindEBO();
    void deleteEBO();
};


#endif //MAPSPHERE_EBO_H
