#include "GameInstance.h"

int main() {
    GameInstance game_instance(1280, 720);
    const int result = game_instance.mainLoop();
    game_instance.close();

    return result;
}
