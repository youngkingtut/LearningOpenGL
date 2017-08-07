#ifndef LEARNINGOPENGL_SHADER_H
#define LEARNINGOPENGL_SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader {
public:
    unsigned int ID = 0;

    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    void use();

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

private:
    GLuint loadShader(const char* filePath, GLuint type);
};


#endif //LEARNINGOPENGL_SHADER_H
