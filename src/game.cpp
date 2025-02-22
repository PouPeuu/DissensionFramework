#include <DissensionFramework/game.hpp>
#include <DissensionFramework/shaders.hpp>

#include <stdexcept>
#include <algorithm>

void DissensionFramework::Game::_setFramebufferSize(GLFWwindow* window, int width, int height) {
    Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
    glViewport(0, 0, width, height);
    game->_window_width = width;
    game->_window_height = height;
}

DissensionFramework::Game::Game(int window_width, int window_height, Renderer* renderer, std::string window_title) {
    _window_width = window_width;
    _window_height = window_height;
    _renderer = renderer;
    _window_title = window_title;
}

void DissensionFramework::Game::_processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


void DissensionFramework::Game::_main() {
    std::vector<unsigned int> deletion_queue;

    for (unsigned int i = 0; i < _game_objects.size(); i++) {
        GameObject* game_object = _game_objects[i];

        State return_state = game_object->update();
        if (return_state == QUEUE_DELETE) {
            game_object->getDeletionSignal().emit();
            deletion_queue.push_back(i);
        }
    }

    for (unsigned int i : deletion_queue) {
        std::swap(_game_objects[i], _game_objects[_game_objects.size() - 1]);
        _game_objects.pop_back();
    }

    for (unsigned int i = 0; i < _game_objects.size(); i++) {
        GameObject* game_object = _game_objects[i];
        game_object->draw(_renderer);
    }
}

void DissensionFramework::Game::addGameObject(GameObject* game_object) {
    _game_objects.push_back(game_object);
    game_object->connectToGame(this);
}

const DissensionFramework::Renderer* DissensionFramework::Game::getRenderer() {
    return _renderer;
}


void DissensionFramework::Game::run() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(_window_width, _window_height, _window_title.c_str(), NULL, NULL);
    if (window == NULL) {
        throw std::runtime_error("Failed to create GLFW window");
        glfwTerminate();
        return;
    }

    glfwSetWindowUserPointer(window, this);

    glfwMakeContextCurrent(window);
    glewInit();

    glViewport(0, 0, _window_width, _window_height);
    glfwSetFramebufferSizeCallback(window, _setFramebufferSize);

    Shaders::initShaders();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        _processInput(window);
        
        _renderer->clear();
        
        _main();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}