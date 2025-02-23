#ifndef STATE_H
#define STATE_H

namespace DissensionFramework {
    struct State {
        bool should_delete = false;
        bool should_redraw = false;
        State(bool should_delete = false, bool should_redraw = false) {
            this->should_delete = should_delete;
            this->should_redraw = should_redraw;
        }
    };
}

#endif