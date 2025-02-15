#include <DissensionFramework/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

DissensionFramework::Transform::Transform(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale)
: _transformation_matrix(1.0) {
    _translation = translation;
    _rotation = rotation;
    _scale = scale;
    
    _needs_update = true;
}

glm::mat4 DissensionFramework::Transform::getMatrix() {
    if (_needs_update) {
        _transformation_matrix = glm::translate(_transformation_matrix, _translation);


        _transformation_matrix = glm::rotate(_transformation_matrix, _rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
        _transformation_matrix = glm::rotate(_transformation_matrix, _rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
        _transformation_matrix = glm::rotate(_transformation_matrix, _rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

        _transformation_matrix = glm::scale(_transformation_matrix, _scale);

        _needs_update = false;
    }

    return _transformation_matrix;
}

glm::vec3 DissensionFramework::Transform::getTranslation() {
    return _translation;
}

glm::vec3 DissensionFramework::Transform::getRotation() {
    return _rotation;
}

glm::vec3 DissensionFramework::Transform::getScale() {
    return _scale;
}

void DissensionFramework::Transform::setTranslation(glm::vec3 translation) {
    _needs_update = true;
    _translation = translation;
}

void DissensionFramework::Transform::setRotation(glm::vec3 rotation) {
    _needs_update = true;
    _rotation = rotation;
}

void DissensionFramework::Transform::setScale(glm::vec3 scale) {
    _needs_update = true;
    _scale = scale;
}
