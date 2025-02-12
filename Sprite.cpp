//
// Created by szolim on 11.02.25.
//

#include "Sprite.h"

#include <iostream>

    Sprite::Sprite(const std::shared_ptr<Texture> &texture, const Position& pos): pos_(pos), texture_(texture) {}

Sprite::~Sprite() = default;

Position Sprite::get_position() const {
    return pos_;
}

void Sprite::set_position(const int x, const int y) {
    pos_.x = x;
    pos_.y = y;
}

void Sprite::update_position(const int dx, const int dy) {
    pos_.x += dx;
    pos_.y += dy;
}

std::shared_ptr<Texture> Sprite::get_texture() {
    return texture_;
}

void Sprite::set_texture(const std::shared_ptr<Texture> &texture) {
    texture_->free();
    texture_ = texture;
}

void Sprite::draw(SDL_Renderer* renderer) const {
    const SDL_Rect renderQuad = {pos_.x, pos_.y, texture_->getWidth(), texture_->getHeight()};
    SDL_RenderCopy(renderer, texture_->getRawTexture(), nullptr, &renderQuad);
}
