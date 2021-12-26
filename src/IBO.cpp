#include "IBO.h"

IBO::IBO() {
    glGenBuffers(1, &ID);
}

void IBO::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void IBO::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
