#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <DissensionFramework/game_object.hpp>
#include <DissensionFramework/renderer.hpp>


namespace DissensionFramework {
    class GameObject;

    class Game {
        private:
            int _window_width, _window_height;
            std::string _window_title;

            std::vector<GameObject*> _game_objects;

            Renderer* _renderer;

            double _last_time;

            static void _setFramebufferSize(GLFWwindow* window, int width, int height);
            void _processInput(GLFWwindow* window);

            void _main();
        public:
            Game(int window_width, int window_height, Renderer* renderer, std::string window_title = "DissensionFramework");

            void run();

            void addGameObject(GameObject* game_object);

            const Renderer* getRenderer();
    };
}

#endif