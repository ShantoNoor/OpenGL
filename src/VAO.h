#pragma once 
#include <GL/glew.h>

class VAO {
private:
    GLuint ID;
public:
    VAO();
    void bind();
    void unbind();
};