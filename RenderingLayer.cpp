//
// Created by szolim on 11.02.25.
//

#include "RenderingLayer.h"

#include <memory>

void RenderingLayer::clear() {
    sprites_.clear();
}

void RenderingLayer::renderLayer(SDL_Renderer* renderer) const {
    for (const auto& [name, sprite_shared] : sprite_map) {
        sprite_shared->draw(renderer);
    }
}

void RenderingLayer::add_sprite(const std::string& name, const std::shared_ptr<Sprite> sprite) {
    auto [_, success] = sprite_map.insert({name, sprite});
    if (!success) {
        throw std::runtime_error("Key already exists in the sprite map");
    }
}

std::weak_ptr<Sprite> RenderingLayer::get_sprite(const std::string &name) {
    return sprite_map.at(name);
}
