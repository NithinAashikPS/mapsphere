//
// Created by aashik on 9/12/23.
//

#ifndef MAPSPHERE_VBO_H
#define MAPSPHERE_VBO_H

#include "glad/glad.h"

class VBO {

public:
    GLuint ID;
    VBO(GLfloat* vertices, GLsizeiptr size);

    void bindVBO();
    void unBindVBO();
    void deleteVBO();

};


#endif //MAPSPHERE_VBO_H
