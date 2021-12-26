#include "Shader.h"
#include "stdio.h"
#include <fstream>
#include <sstream>

Shader::Shader() {
    shader = glCreateProgram();

    if(!shader) {
        printf("Error creating Shader Program.\n");
    }
}

bool Shader::addShader(std::string path, GLenum shaderType) {
    GLuint newShader = glCreateShader(shaderType);

    std::string code = readfile(path);

    const GLchar* theCode[1];
    theCode[0] = code.c_str();

    GLint codeLength[1];
    codeLength[0] = code.length();

    glShaderSource(newShader, 1, theCode, codeLength);
    glCompileShader(newShader);

    GLint result = 0;
    GLchar eLog[1024] = { 0 };

    glGetShaderiv(newShader, GL_COMPILE_STATUS, &result);

    if(!result) {
        glGetProgramInfoLog(newShader, sizeof(eLog), NULL, eLog);
        printf("Error compiling shader program %d: %s\n", shaderType, eLog);
        return false;
    }

    glAttachShader(shader, newShader);
    
    return true;
}

bool Shader::linkShader() {
    GLint result = 0;
    GLchar eLog[1024] = { 0 };

    glLinkProgram(shader);
    glGetProgramiv(shader, GL_LINK_STATUS, &result);

    if(!result) {
        glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
        printf("Error linking shader program: %s\n", eLog);
        return false;
    }

    return true;
}

bool Shader::validateShader(VAO *vao) {
    GLint result = 0;
    GLchar eLog[1024] = { 0 };

    vao->bind();

    glValidateProgram(shader);
    glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);

    if(!result) {
        glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
        printf("Error validating shader program: %s\n", eLog);
        return false;
    }

    vao->unbind();

    return true;
}

void Shader::use() {
    glUseProgram(shader);
}

std::string Shader::readfile(std::string path) {
    std::ifstream infile;
	infile.open(path);

    std::string s;
    std::stringstream ss;

    while(getline(infile, s)) {
        ss << s;
        ss << '\n';
    }

    infile.close();

    return ss.str();
}