#include <DissensionFramework/shader.hpp>

#include <iostream>

unsigned int DissensionFramework::Shader::_compileShader(Resource shader_resource, GLuint shader_type) {
    unsigned int shader;

    shader = glCreateShader(shader_type);
    
    std::vector<unsigned char> data = shader_resource.getData();
    const char* shader_source = reinterpret_cast<const char*>(data.data());

    const int size = (unsigned int)shader_resource.getSize();
    glShaderSource(shader, 1, &shader_source, &size);

    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "Shader " << shader_resource.getRealPath() << " compilation failed:\n" << infoLog << std::endl;
    }

    return shader;
}

DissensionFramework::Shader::Shader(Resource vertex_shader_resource, Resource fragment_shader_resource) {
    _id = glCreateProgram();
    unsigned int vertex_shader = _compileShader(vertex_shader_resource, GL_VERTEX_SHADER);
    glAttachShader(_id, vertex_shader);
    unsigned int fragment_shader = _compileShader(fragment_shader_resource, GL_FRAGMENT_SHADER);
    glAttachShader(_id, fragment_shader);
    glLinkProgram(_id);

    int success;
    char infoLog[512];
    glGetProgramiv(_id, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(_id, 512, NULL, infoLog);
        std::cerr << "Shader program linking failed:\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void DissensionFramework::Shader::use() const {
    glUseProgram(_id);
}