//
// Created by szolim on 11.02.25.
//

#ifndef RENDERINGLAYER_H
#define RENDERINGLAYER_H
#include <memory>
#include <unordered_map>
#include <vector>

#include "Sprite.h"


class RenderingLayer {
    std::vector<std::shared_ptr<Sprite>> sprites_;
    std::unordered_map<std::string, Sprite> sprite_map;
public:
    void clear();
    void renderLayer(SDL_Renderer *renderer) const;
    void add_sprite(const std::shared_ptr<Sprite>& sprite);
    Sprite& get(const std::string& name);

    void add_sprite(const std::string &name, const Sprite &sprite);
};



#endif //RENDERINGLAYER_H
