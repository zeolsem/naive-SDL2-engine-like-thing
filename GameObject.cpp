//
// Created by szolim on 12.02.25.
//

#include "GameObject.h"

GameObject::GameObject(const std::string &_name, const std::function<void()> &update) {
    name = _name;
    _update = update;
}

RLayer GameObject::get_layer() const {
    throw std::logic_error("get_layer() cannot be called on a base GameObject instance.");
}

std::shared_ptr<Sprite> GameObject::get_sprite() const {
    throw std::logic_error("get_sprite() cannot be called on a base GameObject instance.");
}

bool GameObject::is_canvas_item() const {
    return false;
}

std::string GameObject::get_name() const {
    return name;
}

void GameObject::set_name(const std::string &_name) {
    name = _name;
}

void GameObject::add_child(const std::shared_ptr<GameObject>& child) {
    children.emplace_back(child);
}

std::vector<std::shared_ptr<GameObject>>& GameObject::get_children() {
    return children;
}
