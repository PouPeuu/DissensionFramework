#include <DissensionFramework/signal.hpp>

unsigned int DissensionFramework::Signal::subscribe(std::function<void()> subscriber) {
    while (_subscribers.contains(_next_id)){
        _next_id++;
    }
    _subscribers[_next_id] = subscriber;
    return _next_id;
}

void DissensionFramework::Signal::unsubscribe(unsigned int id) {
    _subscribers.erase(id);
}

void DissensionFramework::Signal::emit() {
    for (auto& pair : _subscribers) {
        pair.second();
    }
}