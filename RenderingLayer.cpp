//
// Created by szolim on 11.02.25.
//

#include "RenderingLayer.h"

#include <memory>

void RenderingLayer::clear() {
    sprites_.clear();
}

void RenderingLayer::renderLayer(SDL_Renderer* renderer) const {
    for (const auto& [name, sprite] : sprite_map) {
        sprite.draw(renderer);
    }
}

void RenderingLayer::add_sprite(const std::shared_ptr<Sprite>& sprite) {
    sprites_.emplace_back(sprite);
}

Sprite& RenderingLayer::get(const std::string &name) {
    return sprite_map.at(name);
}


void RenderingLayer::add_sprite(const std::string &name, const Sprite& sprite) {
    auto [fst, snd] = sprite_map.insert({name, sprite});
    if (!snd) {
        throw std::runtime_error("Key already exists in the sprite map");
    }

}
