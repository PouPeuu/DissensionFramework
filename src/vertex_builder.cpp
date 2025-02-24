#include <DissensionFramework/vertex_builder.hpp>

using namespace DissensionFramework;

VertexBuilder& VertexBuilder::vertex(glm::vec3 pos) {
    return vertex(pos.x, pos.y, pos.z);
}

VertexBuilder& VertexBuilder::vertex(float x, float y, float z) {
    _vertex.push_back(x);
    _vertex.push_back(y);
    _vertex.push_back(z);
    return *this;
}

VertexBuilder& VertexBuilder::color(Color __color) {
    return color(__color.r, __color.g, __color.b, __color.a);
}

VertexBuilder& VertexBuilder::color(float r, float g, float b, float a) {
    _vertex.push_back(r);
    _vertex.push_back(g);
    _vertex.push_back(b);
    _vertex.push_back(a);
    return *this;
}

VertexBuilder& VertexBuilder::uv(float u, float v) {
    _vertex.push_back(u);
    _vertex.push_back(v);
    return *this;
}

VertexBuilder& VertexBuilder::uv(glm::vec2 __uv) {
    return uv(__uv.x, __uv.y);
}

std::vector<float> VertexBuilder::build() {
    return _vertex;
}