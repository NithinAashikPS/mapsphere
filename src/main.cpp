#include <iostream>
#include <cmath>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "../core/shader/Shader.h"
#include "../core/shader/VAO.h"
#include "../core/shader/EBO.h"
#include "stb_image.h"

GLfloat  vertices[] = {
        -0.50f, -0.5f * float(sqrt(3)) / 3,     0.0f,  0.8f, 0.3f, 0.02f,
         0.50f, -0.5f * float(sqrt(3)) / 3,     0.0f, 0.8f, 0.3f, 0.02f,
         0.00f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f, 1.0f, 0.6f, 0.32f,
         -0.25f, 0.5f * float(sqrt(3)) / 6,    0.0f, 0.9f, 0.45f, 0.17f,
        0.25f, 0.5f * float(sqrt(3)) / 6,    0.0f, 0.9f, 0.45f, 0.17f,
        0.00f,-0.5f * float(sqrt(3)) / 3,    0.0f, 0.8f, 0.3f, 0.02f,
};
GLuint indices[] = {
        0, 3, 5,
        3, 2, 4,
        5, 4, 1
};

int main() {

    if (glfwInit()) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow *window = glfwCreateWindow(1280, 720, "Map Sphere", nullptr, nullptr);

        glfwMakeContextCurrent(window);
        gladLoadGL();
        glViewport(0, 0, 1280, 720);

        if (window == nullptr) {
            std::cout << "Failed To Create GLFW Window" << std::endl;
            glfwTerminate();
            return -1;
        } else {
            glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
        }

        Shader shader("basic.vertex.shader.glsl", "basic.fragment.shader.glsl");
        VAO vao;
        vao.bindVAO();

        VBO vbo(vertices, sizeof vertices);
        EBO ebo(indices, sizeof indices);

        vao.linkAttribute(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
        vao.linkAttribute(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));
        vao.unBindVAO();
        vbo.unBindVBO();
        ebo.unBindEBO();

        GLuint uniID = glGetUniformLocation(shader.ID, "scale");

        while (!glfwWindowShouldClose(window)) {
            glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            shader.activateShader();
            glUniform1f(uniID, 0.0f);
            vao.bindVAO();
            glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        vao.unBindVAO();
        shader.deleteShader();
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    return 0;
}
