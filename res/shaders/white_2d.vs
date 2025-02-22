#version 330 core
layout (location = 0) in vec2 pos;

out vec4 color;

void main() {
    gl_Position = vec4(pos.xy, 0.0, 1.0);
    color = vec4(1.0, 1.0, 1.0, 1.0);
}