#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <glm/glm.hpp>
#include <DissensionFramework/color.hpp>

namespace DissensionFramework {
    class Renderer {
    public:
        virtual void clear() = 0;
        virtual void drawPolygon(std::vector<glm::vec2> points, Color color) = 0;
        virtual void drawEquilateralPolygon(unsigned int count, float radius, Color color) = 0;
    };
}

#endif