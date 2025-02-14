#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#include <DissensionFramework/game_object.hpp>
#include <DissensionFramework/transform.hpp>

namespace DissensionFramework {
    class WorldObject : public GameObject {
        private:
            Transform _transform;
        public:
            WorldObject() = default;
            WorldObject(glm::vec2 position, glm::vec2 scale, float rotation);

            glm::vec2 getPosition();
            glm::vec2 getScale();
            float getRotation();

            void setPosition(glm::vec2 position);
            void setScale(glm::vec2 scale);
            void setRotation(float rotation);
    };
}

#endif