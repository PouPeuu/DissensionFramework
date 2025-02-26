#include <DissensionFramework/vertex_arrays.hpp>
#include <DissensionFramework/vertex_array_builder.hpp>

using namespace DissensionFramework;

VertexArray* VertexArrays::SIMPLE_COLOR = nullptr;

void VertexArrays::initVertexArrays() {
    SIMPLE_COLOR = &VertexArrayBuilder()
                    .addAttribute(3) // Position
                    .addAttribute(4) // Color RGBA
                    .build();
}