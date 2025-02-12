//
// Created by szolim on 12.02.25.
//

#ifndef CANVASITEM_H
#define CANVASITEM_H
#include <SDL_render.h>

#include "GameObject.h"


enum class RLayer;
class Sprite;

class CanvasItem : public GameObject {
    bool visible;
    std::shared_ptr<Sprite> sprite;
    RLayer layer;
public:
    CanvasItem(const std::string& name, bool _visible, std::shared_ptr<Sprite> _sprite, const RLayer& _layer);

    [[nodiscard]] bool is_canvas_item() const override;
    void set_visible(bool _visible);
    [[nodiscard]] bool get_visible() const;
    void draw(SDL_Renderer* renderer) const;
    void set_sprite(std::shared_ptr<Sprite> _sprite);
    [[nodiscard]] RLayer get_layer() const override;
    [[nodiscard]] std::shared_ptr<Sprite> get_sprite() const override;
    void set_layer(const RLayer& _layer);
};



#endif //CANVASITEM_H
