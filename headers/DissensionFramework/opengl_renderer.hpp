#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include <DissensionFramework/renderer.hpp>
#include <DissensionFramework/opengl_includes.hpp>

namespace DissensionFramework {
    class OpenGLRenderer : public Renderer {
    public:
        void clear() const override;
        void drawPolygon(std::vector<glm::vec2> points, Color color) const override;
        void drawEquilateralPolygon(unsigned int count, float radius, Color color) const override;
    };
}

#endif