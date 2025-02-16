#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <DissensionFramework/game.hpp>
#include <DissensionFramework/state.hpp>
#include <DissensionFramework/signal.hpp>

namespace DissensionFramework {
    class Game;

    class GameObject {
    protected:
        Game* _game;
        Signal _deletion_signal;

        virtual void _connectedToGame() {};
    public:
        GameObject() = default;

        virtual State update() {return NORMAL;};
        virtual void draw() const {};

        void connectToGame(Game* game);

        Signal& getDeletionSignal();
    };
}

#endif