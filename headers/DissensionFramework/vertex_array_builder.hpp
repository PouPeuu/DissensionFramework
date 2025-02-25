#ifndef VERTEX_ARRAY_BUILDER_H
#define VERTEX_ARRAY_BUILDER_H

#include <DissensionFramework/vertex_array.hpp>
#include <vector>

namespace DissensionFramework {
    class VertexArrayBuilder {
    private:
        std::vector<unsigned int> _attributes;
    public:
        VertexArrayBuilder() = default;

        VertexArrayBuilder& addAttribute(unsigned int attribute_size);

        VertexArray build();
    };
}

#endif