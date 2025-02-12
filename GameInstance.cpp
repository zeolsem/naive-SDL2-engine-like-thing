//
// Created by szolim on 11.02.25.
//

#include "GameInstance.h"

#include <iostream>
#include <thread>
#include <SDL2/SDL_image.h>

#include "CanvasItem.h"

GameInstance::GameInstance(const int width, const int height): SCREEN_HEIGHT(height), SCREEN_WIDTH(width) {
    root = std::make_unique<GameObject>("root");
}

GameInstance::~GameInstance() = default;

GameInstance & GameInstance::operator=(GameInstance other) {
    if (this != &other) {
        SCREEN_WIDTH = other.SCREEN_WIDTH;
        SCREEN_HEIGHT = other.SCREEN_HEIGHT;
        std::swap(window, other.window);
    }

    return *this;
}

bool GameInstance::init() {
    bool success = true;

    // Initialize SDL
    if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    if ( !(IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) ) {
        printf("SDL IMG could not initialize! Error:%s\n", IMG_GetError());
        SDL_Quit();
        return false;
    }
    // Create window
    window = SDL_CreateWindow(
        "SDL Tutorial",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    if (!window) {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    try {
        render_system = new RenderSystem(window);
        render_system->init();
    }
    catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
        success = false;
    }

    return success;
}

void GameInstance::close() {
    SDL_DestroyWindow( window );
    if (render_system) {
        render_system->free();
        delete render_system;
        render_system = nullptr;
    }
    window = nullptr;

    IMG_Quit();
    SDL_Quit();
}

void GameInstance::setup_test_tree() const {
    printf("1");
    auto obj1 = std::make_shared<GameObject>("obj1");
    auto obj2 = std::make_shared<GameObject>("obj2");
    auto obj3 = std::make_shared<GameObject>("obj3");
    root->add_child(obj1);
    root->add_child(obj2);
    root->add_child(obj3);
    std::cout << "2";

    auto txt1 = std::make_shared<Texture>();
    txt1->loadFromFile(render_system->get_renderer(), "assets/Sprite-0001.png");
    auto spr1 = std::make_shared<Sprite>(txt1, Position{0, 0});

    std::cout << "3";
    auto cnvitm1 = std::make_shared<CanvasItem>("cnv1", true, spr1, RLayer::PLAYER);
    obj1->add_child(cnvitm1);
    std::cout << "4";
    render_system->add_tree(root);
    std::cout << "5";
}

int GameInstance::mainLoop() {
    if (!init()) {
        printf( "Something went wrong! Error is: %s\n", SDL_GetError());
        return -1;
    }

    setup_test_tree();

    // std::shared_ptr<Texture> txt1 = std::make_shared<Texture>();
    // txt1->loadFromFile(render_system->get_renderer(), "assets/Sprite-0001.png");
    // Sprite spr1(txt1, {0, 0});
    // CHANGE SPRITE TO BE A CANVASITEM MEMBER
    // std::shared_ptr<Sprite> spr = std::make_shared<Sprite>(txt1, Position(0, 0));
    // render_system->add_sprite(RLayer::BACKGROUND, "player", spr);

    // Main loop flag
    bool quit = false;
    // Event handler
    SDL_Event e;
    // Main loop for running app
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if  (e.type == SDL_KEYDOWN) {
                //Select surfaces based on key press
                switch( e.key.keysym.sym ) {
                    default:
                    break;
                }
            }
        }

        render_system->draw_frame();
        SDL_Delay(16);
    }

    close();

    return 0;
}
