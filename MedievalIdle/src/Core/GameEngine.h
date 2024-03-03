// Medieval Idle/src/Core/GameEngine.h
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class GameEngine {
public:
    GameEngine();
    ~GameEngine();

    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
    bool isRunning;

    // Example: std::unique_ptr<ResourceManager> resourceManager;
};
#pragma once
