#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <DissensionFramework/game.hpp>
#include <DissensionFramework/renderer.hpp>
#include <DissensionFramework/state.hpp>
#include <DissensionFramework/signal.hpp>

namespace DissensionFramework {
    class Game;

    class GameObject {
    protected:
        Game* _game;
        Signal _deletion_signal;
        State _state;

        virtual void _connectedToGame() {};
    public:
        GameObject() = default;

        virtual void update(double delta_time) {};
        virtual void draw(const Renderer* renderer) const {};

        void connectToGame(Game* game);
        
        State getState() {return _state;};

        Signal& getDeletionSignal();
    };
}

#endif