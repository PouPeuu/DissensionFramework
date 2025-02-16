#ifndef SIGNAL_H
#define SIGNAL_H

#include <functional>
#include <unordered_map>

namespace DissensionFramework {
    class Signal {
        private:
            unsigned int _next_id = -1;

            std::unordered_map<unsigned int, std::function<void()>> _subscribers;
        public:
            Signal() = default;

            unsigned int subscribe(std::function<void()> subscriber);
            void unsubscribe(unsigned int id);

            void unsubscribeAll();

            void emit();
    };
}

#endif