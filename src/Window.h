#pragma once

#include <stdio.h>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
private:
    static Window *instance;
    GLFWwindow *window;
    GLint width, height;
    std::string title;
    Window(GLint width, GLint height, std::string title);

public:
    static Window* get(GLint width = 800, GLint height = 600, std::string title = "OpenGL");
    void update();
    bool isClosed();
    bool init();
};
