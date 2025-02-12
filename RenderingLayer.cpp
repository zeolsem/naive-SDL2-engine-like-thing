//
// Created by szolim on 11.02.25.
//

#include "RenderingLayer.h"

#include <memory>

void RenderingLayer::clear() {
    sprites_.clear();
}

void RenderingLayer::renderLayer(SDL_Renderer* renderer) const {
    for (const auto& sprite : sprites_) {
        sprite->draw(renderer);
    }
}

void RenderingLayer::add_sprite(const std::shared_ptr<Sprite>& sprite) {
    sprites_.emplace_back(sprite);
}
