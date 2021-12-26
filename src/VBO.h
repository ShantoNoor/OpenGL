#pragma once 

#include <GL/glew.h>

class VBO {
private:
    GLuint ID;

public:
    VBO();
    void bind();
    void unbind();
};