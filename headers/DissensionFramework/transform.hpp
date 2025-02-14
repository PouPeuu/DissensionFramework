#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>

namespace DissensionFramework {
    class Transform {
        private:
            glm::mat4 _transformation_matrix;

            glm::vec3 _translation;
            glm::vec3 _rotation;
            glm::vec3 _scale;

            bool _needs_update;
        public:
            Transform() = default;
            Transform(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale);

            glm::mat4 getMatrix();

            glm::vec3 getTranslation();
            glm::vec3 getRotation();
            glm::vec3 getScale();

            void setTranslation(glm::vec3 translation);
            void setRotation(glm::vec3 rotation);
            void setScale(glm::vec3 scale);
    };
}

#endif