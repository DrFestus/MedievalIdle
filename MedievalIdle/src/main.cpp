// Medieval Idle/src/Main.cpp
#include "MedievalIdlePCH.h"

#include "Core/GameEngine.h"
#include "Core/Log.h"

int main() {

    Log::Init();
    LOG_INFO("Game Starting...");
    GameEngine gameEngine;
    gameEngine.run();
    return 0;
}
