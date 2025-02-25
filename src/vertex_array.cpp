#include <DissensionFramework/vertex_array.hpp>
#include <stdexcept>

using namespace DissensionFramework;

VertexArray::VertexArray(std::vector<unsigned int> attributes) :
_attributes(attributes)
{
    for (unsigned int attribute : _attributes) {
        _vertex_size += attribute;
    }
}

void VertexArray::addVertex(std::vector<float> vertex) {
    if (vertex.size() > _vertex_size)
        throw std::runtime_error("Wrong vertex size " + std::to_string(vertex.size()) + " vs VertexArray " + std::to_string(_vertex_size));
    _vertices.insert(_vertices.end(), vertex.begin(), vertex.end());
}