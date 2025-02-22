#include <DissensionFramework/polygon.hpp>

DissensionFramework::Polygon::Polygon(std::vector<glm::vec2> points) {
    _points = points;
}

void DissensionFramework::Polygon::addPoint(glm::vec2 point) {
    _points.push_back(point);
}

void DissensionFramework::Polygon::removePoint(size_t index) {
    _points.erase(_points.begin() + index);
}

const std::vector<glm::vec2>& DissensionFramework::Polygon::getPoints() {
    return _points;
}

const glm::vec2& DissensionFramework::Polygon::getPoint(size_t index) {
    return _points[index];
}