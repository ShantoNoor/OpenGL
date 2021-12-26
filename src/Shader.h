#include <GL/glew.h>
#include "VAO.h"
#include <string>

class Shader {
private:
    GLuint shader;
public:
    Shader();
    bool addShader(std::string path, GLenum shaderType);
    bool linkShader();
    bool validateShader(VAO *vao);
    void use();
    std::string readfile(std::string path);
};