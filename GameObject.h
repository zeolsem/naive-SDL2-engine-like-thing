//
// Created by szolim on 12.02.25.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <functional>
#include <memory>
#include <utility>
#include <vector>

#include "RenderingLayer.h"
#include "Sprite.h"


class GameObject {
    std::vector<std::shared_ptr<GameObject>> children;
    std::string name;
public:
    std::function<void()> _update;

    explicit GameObject(std::string  _name) : name(std::move(_name)), _update([]{}) {}
    GameObject(const std::string& _name, const std::function<void()> &update);
    virtual ~GameObject() = default;
    [[nodiscard]] virtual RLayer get_layer() const;
    [[nodiscard]] virtual std::shared_ptr<Sprite> get_sprite() const;
    [[nodiscard]] virtual bool is_canvas_item() const;

    void update() const { _update(); }

    [[nodiscard]] std::string get_name() const;
    void set_name(const std::string &_name);

    void add_child(const std::shared_ptr<GameObject> &child);
    std::vector<std::shared_ptr<GameObject>>& get_children();
};



#endif //GAMEOBJECT_H
