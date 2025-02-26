#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <vector>
#include <DissensionFramework/opengl_includes.hpp>

namespace DissensionFramework {
    class VertexArray {
    private:
        const std::vector<unsigned int> _attributes;
        std::vector<float> _vertices;
        unsigned int _vertex_size;

        unsigned int _VAO;
    public:
        VertexArray(std::vector<unsigned int> attributes);

        void addVertex(std::vector<float> vertex);

        void bind();
    };
}

#endif