#include "VAO.h"

VAO::VAO(){
    glGenVertexArrays(1, &ID);
}

void VAO::bind() {
    glBindVertexArray(ID);
}

void VAO::unbind(){
    glBindVertexArray(0);
}
