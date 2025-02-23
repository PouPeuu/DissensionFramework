#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <glm/glm.hpp>
#include <DissensionFramework/color.hpp>

namespace DissensionFramework {
    class Renderer {
    public:
        virtual void clear() const = 0;
        virtual void drawPolygon(std::vector<glm::vec2> points, Color color) const = 0;
        virtual void drawEquilateralPolygon(unsigned int count, float radius, Color color, float offset = 0.0) const = 0;
    };
}

#endif