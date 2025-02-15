#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <DissensionFramework/state.hpp>

namespace DissensionFramework {
    class GameObject
    {
    private:
        
    public:
        GameObject() = default;

        virtual State update() {return NORMAL;};
        virtual void draw() const {};
    };
}

#endif