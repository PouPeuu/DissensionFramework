#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <DissensionFramework/game.hpp>
#include <DissensionFramework/state.hpp>

namespace DissensionFramework {
    class Game;

    class GameObject
    {
    private:
        Game* _game;
    public:
        GameObject() = default;

        virtual State update() {return NORMAL;};
        virtual void draw() const {};

        void connect_to_game(Game* game);
    };
}

#endif