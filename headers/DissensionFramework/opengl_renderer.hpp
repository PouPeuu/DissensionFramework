#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include <DissensionFramework/renderer.hpp>
#include <DissensionFramework/opengl_includes.hpp>

namespace DissensionFramework {
    class OpenGLRenderer {
    public:
        void clear();
        void drawPolygon(std::vector<glm::vec2> points, Color color);
        void drawEquilateralPolygon(unsigned int count, float radius, Color color);
    };
}

#endif