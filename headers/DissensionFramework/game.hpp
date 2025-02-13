#ifndef GAME_H
#define GAME_H

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace DissensionFramework {
    class Game {
        private:
            int _window_width, _window_height;
            std::string _window_title;

            static void _setFramebufferSize(GLFWwindow* window, int width, int height);
            void _processInput(GLFWwindow* window);
        public:
            Game(int window_width, int window_height, std::string window_title = "DissensionFramework");

            void run();
    };
}

#endif