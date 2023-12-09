//
// Created by aashik on 9/12/23.
//

#include "VAO.h"

VAO::VAO() {

    glGenVertexArrays(1, &ID);
}

void VAO::linkAttribute(VBO VBO, GLuint layout, GLint numComp, GLenum type, GLsizei stride, void *offset) {

    VBO.bindVBO();
    glVertexAttribPointer(layout, numComp, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    VBO.unBindVBO();
}

void VAO::bindVAO() {

    glBindVertexArray(ID);
}

void VAO::unBindVAO() {

    glBindVertexArray(0);
}

void VAO::deleteVAO() {

    glDeleteVertexArrays(1, &ID);
}