#include <DissensionFramework/shaders.hpp>

DissensionFramework::Shader DissensionFramework::Shaders::COLOR_2D;
DissensionFramework::Shader DissensionFramework::Shaders::WHITE_2D;

void DissensionFramework::Shaders::initShaders(){
    COLOR_2D = Shader("builtin/shaders/color_2d.vs", "builtin/shaders/color_2d.fs");
    WHITE_2D = Shader("builtin/shaders/white_2d.vs", "builtin/shaders/color_2d.fs");
}