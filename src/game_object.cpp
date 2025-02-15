#include <DissensionFramework/game_object.hpp>

void DissensionFramework::GameObject::connect_to_game(Game* game) {
    _game = game;
}