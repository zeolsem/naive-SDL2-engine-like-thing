//
// Created by szolim on 11.02.25.
//

#ifndef RENDERINGLAYER_H
#define RENDERINGLAYER_H
#include <memory>
#include <vector>

#include "Sprite.h"


class RenderingLayer {
    std::vector<std::shared_ptr<Sprite>> sprites_;
public:
    void clear();
    void renderLayer(SDL_Renderer *renderer) const;
    void add_sprite(const std::shared_ptr<Sprite>& sprite);
};



#endif //RENDERINGLAYER_H
