// GameEngine.h

#include "Events/EventDispatcher.h"
#include "Events/Event.h"
#include "Resources/ResourceManager.h"

#include <imgui-SFML.h>
#include <imgui.h>

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
    bool buttonClicked; // Now a member variable

    EventDispatcher dispatcher; // Ensure dispatcher is also a member variable
    ResourceManager resourceManager;
};
