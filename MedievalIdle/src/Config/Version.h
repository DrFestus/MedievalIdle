#pragma once

#define GAME_VERSION_MAJOR 0
#define GAME_VERSION_MINOR 1
#define GAME_VERSION_PATCH 0
#define GAME_VERSION_ALPHA 1

// Generates a string literal representation of the version number
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

// Full version string
#define GAME_VERSION "v" TOSTRING(GAME_VERSION_MAJOR) "." TOSTRING(GAME_VERSION_MINOR) "." TOSTRING(GAME_VERSION_PATCH) "-alpha"