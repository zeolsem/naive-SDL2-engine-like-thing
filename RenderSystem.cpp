//
// Created by szolim on 11.02.25.
//

#include "RenderSystem.h"

#include <iostream>
#include <memory>
#include <stdexcept>

#include "Texture.h"

RenderSystem::RenderSystem(SDL_Window* window): background_color_() {
    background_color_ = {0x00, 0xFF, 0xFF, 0xFF};
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        throw std::runtime_error("Failed to create SDL renderer: " + std::string(SDL_GetError()));
    }
}

void RenderSystem::draw_frame() {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, background_color_.r, background_color_.g, background_color_.b, background_color_.a);
    SDL_RenderClear(renderer);

    for (RenderingLayer& layer : layers_) {
        layer.renderLayer(renderer);
    }

    // Update the screen
    SDL_RenderPresent(renderer);
}

void RenderSystem::init() {
    for (int i = 0; i < static_cast<int>(RLayer::LAYER_AMOUNT); i++) {
        layers_.emplace_back();
    }
}

SDL_Renderer * RenderSystem::get_renderer() const {
    return renderer;
}

void RenderSystem::add_sprite(RLayer layer, const std::string &name, const std::shared_ptr<Sprite> &sprite) {
    layers_[static_cast<int>(layer)].add_sprite(name, sprite);
}

void RenderSystem::add_tree(const std::shared_ptr<GameObject> &root) {
    if (root->is_canvas_item()) {
        layers_[static_cast<int>(root->get_layer())].add_sprite(root->get_name(), root->get_sprite());
    }
    for (std::shared_ptr<GameObject>& obj : root->get_children()) {
        add_tree(obj);
    }
}

void RenderSystem::free() {
    for (RenderingLayer& layer : layers_) {
        layer.clear();
    }
}

RenderSystem::~RenderSystem() {
    free();
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
}
