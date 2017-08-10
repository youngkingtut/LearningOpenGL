#include "Shader.h"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath){
    unsigned int vertex = loadShader(vertexPath, GL_VERTEX_SHADER);;
    unsigned int fragment = loadShader(fragmentPath, GL_FRAGMENT_SHADER);;

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    int success;
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!(bool)success)
    {
        char infoLog[512];
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cerr << "failed to link shaders\n" << infoLog << std::endl;

    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

GLuint Shader::loadShader(const char* filePath, GLuint type){
    std::string codeString;

    try{
        std::ifstream shaderFile;
        shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        shaderFile.open(filePath);
        std::stringstream shaderStream;

        shaderStream << shaderFile.rdbuf();

        shaderFile.close();

        codeString = shaderStream.str();
    } catch(std::ifstream::failure &e) {
        std::cerr << "failed to read: " << filePath << std::endl;
    }

    const char* code = codeString.c_str();

    GLint success = 0;
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &code, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!(bool)success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "failed to compile shader\n" << infoLog << std::endl;
    };

    return shader;
}

void Shader::use() { glUseProgram(ID); }
void Shader::setBool(const std::string &name, bool value) const { glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); }
void Shader::setInt(const std::string &name, int value) const { glUniform1i(glGetUniformLocation(ID, name.c_str()), value); }
void Shader::setFloat(const std::string &name, float value) const { glUniform1f(glGetUniformLocation(ID, name.c_str()), value); }
void Shader::set4f(const std::string &name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const { glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);}
