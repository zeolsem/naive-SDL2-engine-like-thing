//
// Created by szolim on 11.02.25.
//


#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

#include <SDL2/SDL.h>

#include "RenderSystem.h"

class GameInstance {
public:
    SDL_Window* window = nullptr;
    RenderSystem* render_system = nullptr;

    // Rule of three
    GameInstance(int width, int height);
    ~GameInstance();
    GameInstance& operator=(GameInstance other);

    // program flow
    bool init();
    void close();
    [[nodiscard]] int mainLoop();

private:
    int SCREEN_HEIGHT;
    int SCREEN_WIDTH;
};

#endif //GAMEINSTANCE_H
