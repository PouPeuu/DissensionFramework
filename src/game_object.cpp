#include <DissensionFramework/game_object.hpp>

void DissensionFramework::GameObject::connectToGame(Game* game) {
    _game = game;
    _connectedToGame();
}

DissensionFramework::Signal& DissensionFramework::GameObject::getDeletionSignal() {
    return _deletion_signal;
}