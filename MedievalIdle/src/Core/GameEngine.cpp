// Medieval Idle/src/Core/GameEngine.cpp
#include "MedievalIdlePCH.h"

#include "GameEngine.h"

#include <imgui-SFML.h>
#include <imgui.h>

GameEngine::GameEngine() : window(sf::VideoMode(800, 600), "Medieval Idle"), isRunning(true) {
    ImGui::SFML::Init(window);
    // Initialize other managers here, for example:
    // resourceManager = std::make_unique<ResourceManager>();
}

GameEngine::~GameEngine() {
    ImGui::SFML::Shutdown();
}

void GameEngine::run() {
    sf::Clock clock;
    while (isRunning) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void GameEngine::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);

        if (event.type == sf::Event::Closed) {
            isRunning = false;
        }
        // Handle other events here
    }
}

void GameEngine::update(sf::Time deltaTime) {
    ImGui::SFML::Update(window, deltaTime);
    // Update other managers here
}

void GameEngine::render() {
    window.clear();
    ImGui::SFML::Render(window);
    window.display();
}
