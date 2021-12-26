#include "Window.h"

Window* Window::instance = nullptr;

Window* Window::get(GLint width, GLint height, std::string title) {
    if(instance == nullptr) {
        instance = new Window(width, height, title);
    }
    return instance;
}

void Window::update() {
    glfwPollEvents();
    glfwSwapBuffers(window);
}

bool Window::isClosed() { 
    return !glfwWindowShouldClose(window); 
}

bool Window::init(){
    if(!glfwInit()) {
        printf("Failed to Init GLFW.\n");
        glfwTerminate();
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if(!window) {
        printf("Failed to Create GLFW Window.\n");
        glfwTerminate();
        return false;
    }

    int bufferwidth = 0, bufferheight = 0;
    glfwGetFramebufferSize(window, &bufferwidth, &bufferwidth);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK) {
        printf("Failed to Init GLEW\n");
        glfwDestroyWindow(window);
        glfwTerminate();
        return false;
    }

    glViewport(0, 0, bufferwidth, bufferheight);

    return true;
}

Window::Window(GLint width, GLint height, std::string title) {
    this->width = width;
    this->height = height;
    this->title = title;
}