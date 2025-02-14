#include <world_object.hpp>

DissensionFramework::WorldObject::WorldObject(glm::vec2 position, glm::vec2 scale, float rotation) {
    _transform.setTranslation(glm::vec3(position.x, position.y, 0.0));
    _transform.setRotation(glm::vec3(rotation));
    _transform.setScale(glm::vec3(scale.x, scale.y, 0.0));
}

glm::vec2 DissensionFramework::WorldObject::getPosition() {
    return _transform.getTranslation();
}

glm::vec2 DissensionFramework::WorldObject::getScale() {
    return _transform.getScale();
}

float DissensionFramework::WorldObject::getRotation() {
    // FIXME: This coulde be wrong!!!
    return _transform.getRotation().x;
}

void DissensionFramework::WorldObject::setPosition(glm::vec2 position) {
    _transform.setTranslation(glm::vec3(position.x, position.y, 0.0));
}

void DissensionFramework::WorldObject::setScale(glm::vec2 scale) {
    _transform.setScale(glm::vec3(scale.x, scale.y, 0.0));
}

void DissensionFramework::WorldObject::setRotation(float rotation) {
    _transform.setRotation(glm::vec3(rotation));
}
