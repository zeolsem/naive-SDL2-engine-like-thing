//
// Created by szolim on 12.02.25.
//

#include "CanvasItem.h"

#include <iostream>

#include "Sprite.h"

CanvasItem::CanvasItem(const std::string& name, const bool _visible, std::shared_ptr<Sprite> _sprite, const RLayer& _layer): GameObject(name) {
    visible = _visible;
    sprite = std::move(_sprite);
    layer = _layer;
}

bool CanvasItem::is_canvas_item() const {
    return true;
}

void CanvasItem::set_visible(const bool _visible) {
    visible = _visible;
}

bool CanvasItem::get_visible() const {
    return visible;
}

void CanvasItem::draw(SDL_Renderer* renderer) const {
    if (!visible) {
        return;
    }
    if (sprite) {
        sprite->draw(renderer);
    }
    else {
        std::cerr << "CanvasItem failed attempt to draw an unassigned Sprite\n";
    }
}

void CanvasItem::set_sprite(std::shared_ptr<Sprite> _sprite) {
    sprite = std::move(_sprite);
}

RLayer CanvasItem::get_layer() const {
    return layer;
}

std::shared_ptr<Sprite> CanvasItem::get_sprite() const {
    return sprite;
}

void CanvasItem::set_layer(const RLayer& _layer) {
    layer = _layer;
}
