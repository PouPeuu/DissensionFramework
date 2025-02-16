#ifndef COLOR_H
#define COLOR_H

namespace DissensionFramework {
    struct Color {
        float r, g, b, a;
        Color(float r, float g, float b, float a) {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }
    };
}

#endif