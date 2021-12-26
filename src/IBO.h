#pragma once
#include <GL/glew.h>

class IBO {
private:
    GLuint ID;

public:
    IBO();
    void bind();
    void unbind();
};
