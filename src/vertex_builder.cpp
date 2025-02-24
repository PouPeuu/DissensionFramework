#include <DissensionFramework/vertex_builder.hpp>

using namespace DissensionFramework;

VertexBuilder& VertexBuilder::vertex(glm::vec3 pos) {
    vertex(pos.x, pos.y, pos.z);
}

VertexBuilder& VertexBuilder::vertex(float x, float y, float z) {
    _vertex.push_back(x);
    _vertex.push_back(y);
    _vertex.push_back(z);
}

VertexBuilder& VertexBuilder::color(Color _color) {
    color(_color.r, _color.g, _color.b, _color.a);
}

VertexBuilder& VertexBuilder::color(float r, float g, float b, float a) {
    _vertex.push_back(r);
    _vertex.push_back(g);
    _vertex.push_back(b);
    _vertex.push_back(a);
}

std::vector<float> VertexBuilder::build() {
    return _vertex;
}