#include "Window.h"
#include "VAO.h"
#include "VBO.h"
#include "IBO.h"
#include "Shader.h"

Shader *shader = nullptr;
VAO *vao = nullptr;
VBO *vbo = nullptr;
IBO *ibo = nullptr;

void CreateTriangle() {
    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,
        +1.0f, -1.0f, 0.0f,
        -1.0f, +1.0f, 0.0f,
        +1.0f, +1.0f, 0.0f
    };

    GLuint indices[] = {
        0, 2, 3,
        3, 1, 0
    };

    vao->bind();
    vbo->bind();


    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT)*3, 0);
    glEnableVertexAttribArray(0);

    ibo->bind();

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    ibo->unbind();
    vbo->unbind();
    vao->unbind();
}

void CompileShaders() {
    shader = new Shader();
    shader->addShader("shaders/Mandelbrot.vert", GL_VERTEX_SHADER);
    shader->addShader("shaders/Mandelbrot.frag", GL_FRAGMENT_SHADER);
    shader->linkShader();
    shader->validateShader(vao);
}

int main() {
    Window::get(1280, 720, "Mandelbrot")->init();

    vao = new VAO();
    vbo = new VBO();
    ibo = new IBO();

    CreateTriangle();
    CompileShaders();

    while(Window::get()->isClosed()){
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader->use();

        vao->bind();
        ibo->bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        vao->unbind();
        ibo->unbind();

        Window::get()->update();
    }

    return 0;
}
