#include <DissensionFramework/vertex_array_builder.hpp>

using namespace DissensionFramework;

VertexArrayBuilder& VertexArrayBuilder::addAttribute(unsigned int attribute_size) {
    _attributes.push_back(attribute_size);
    return *this;
}

VertexArray VertexArrayBuilder::build() {
    return VertexArray(_attributes);
}