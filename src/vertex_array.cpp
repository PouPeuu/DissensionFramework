#include <DissensionFramework/vertex_array.hpp>
#include <stdexcept>

using namespace DissensionFramework;

VertexArray::VertexArray(std::vector<unsigned int> attributes) :
_attributes(attributes)
{
    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);

    for (unsigned int attribute : _attributes) {
        _vertex_size += attribute;
    }

    unsigned int current_pos = 0;
    for (unsigned int i = 0; i < _attributes.size(); i++) {
        unsigned int attribute = _attributes[i];
        glVertexAttribPointer(i, attribute, GL_FLOAT, GL_FALSE, _vertex_size * sizeof(float), (void*)(intptr_t) current_pos);
        glEnableVertexAttribArray(i);
        current_pos += attribute;
    }
}

void VertexArray::addVertex(std::vector<float> vertex) {
    if (vertex.size() > _vertex_size)
        throw std::runtime_error("Wrong vertex size " + std::to_string(vertex.size()) + " vs VertexArray " + std::to_string(_vertex_size));
    _vertices.insert(_vertices.end(), vertex.begin(), vertex.end());
}

void VertexArray::bind() {
    glBindVertexArray(_VAO);
}