#ifndef SHADERS_H
#define SHADERS_H

#include <DissensionFramework/shader.hpp>

namespace DissensionFramework {
    namespace Shaders {
        const Shader COLOR_2D("builtin/shaders/color_2d.vs", "builtin/shaders/color_2d.fs"); // muaahahaaaa
        const Shader WHITE_2D("builtin/shaders/white_2d.vs", "builtin/shaders/color_2d.fs");
    }
}

#endif