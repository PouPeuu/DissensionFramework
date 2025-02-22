#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <glm/glm.hpp>

namespace DissensionFramework {
    class Polygon {
    private:
        std::vector<glm::vec2> _points;
    public:
        Polygon() = default;
        Polygon(std::vector<glm::vec2> points);

        void addPoint(glm::vec2 point);
        void removePoint(size_t index);

        const std::vector<glm::vec2>& getPoints();
        const glm::vec2& getPoint(size_t index);
    };
}

#endif