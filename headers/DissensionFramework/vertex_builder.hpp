#ifndef VERTEX_BUILDER_H
#define VERTEX_BUILDER_H

#include <DissensionFramework/color.hpp>
#include <vector>
#include <glm/glm.hpp>

namespace DissensionFramework {
    class VertexBuilder {
        std::vector<float> _vertex;
        public:
            VertexBuilder() = default;

            VertexBuilder& vertex(float x, float y, float z);
            VertexBuilder& vertex(glm::vec3 pos);
            VertexBuilder& color(float r, float g, float b, float a);
            VertexBuilder& color(Color __color);
            VertexBuilder& uv(float u, float v);
            VertexBuilder& uv(glm::vec2 __uv);

            std::vector<float> build();
    };
}

#endif