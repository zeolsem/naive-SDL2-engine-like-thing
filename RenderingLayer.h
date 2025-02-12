//
// Created by szolim on 11.02.25.
//

#ifndef RENDERINGLAYER_H
#define RENDERINGLAYER_H
#include <memory>
#include <unordered_map>
#include <vector>

#include "Sprite.h"

enum class RLayer { BACKGROUND=0, OTHER=1, PLAYER=2, LAYER_AMOUNT=3};

class RenderingLayer {
    std::vector<std::shared_ptr<Sprite>> sprites_;
    std::unordered_map<std::string, std::shared_ptr<Sprite>> sprite_map;
public:
    void clear();
    void renderLayer(SDL_Renderer *renderer) const;
    void add_sprite(const std::string &name, std::shared_ptr<Sprite> sprite);

    std::weak_ptr<Sprite> get_sprite(const std::string &name);
};



#endif //RENDERINGLAYER_H
