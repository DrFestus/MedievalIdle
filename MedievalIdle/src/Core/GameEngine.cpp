// Medieval Idle/src/Core/GameEngine.cpp
#include "MedievalIdlePCH.h"

#include "GameEngine.h"


GameEngine::GameEngine() : window(sf::VideoMode(800, 600), "Medieval Idle"), isRunning(true), buttonClicked(false) {
    ImGui::SFML::Init(window);
    // Initialize other managers...

    dispatcher.subscribe<ButtonClickedEvent>([this](const Event& e) {
        this->buttonClicked = !this->buttonClicked;
        LOG_INFO("Button Clicked Event Dispatched. ButtonClicked: {}", this->buttonClicked);
        });
}

GameEngine::~GameEngine() {
    ImGui::SFML::Shutdown();
}

void GameEngine::run() {
    sf::Clock clock;
    while (isRunning) {
        sf::Time deltaTime = clock.restart();

        processEvents(); // Process SFML events, including those for ImGui

        // Start a new ImGui frame
        ImGui::SFML::Update(window, deltaTime);

        update(deltaTime); // Update your game logic

        render(); // Render your game, encapsulating ImGui render calls

        // SFML display should be the last thing called
        window.display();
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


}

void GameEngine::render() {
    window.clear();

    // Your ImGui window creation and rendering logic
    ImGui::Begin("Test Event Dispatcher");
    if (ImGui::Button("Click Me")) {
        dispatcher.dispatch(ButtonClickedEvent());
    }

    if (buttonClicked) {
        ImGui::Text("Button was clicked!");
    }
    else {
        ImGui::Text("Click the button.");
    }
    ImGui::End();

    ImGui::Begin("Resources");
    for (const auto& [name, resource] : resourceManager.getResources()) {
        ImGui::Text("%s: %d", name.c_str(), resource->getAmount());
    }
    ImGui::End();

    // Render ImGui draw data
    ImGui::SFML::Render(window);

    // Do NOT call window.display() here; it should be called at the end of the run loop
}
