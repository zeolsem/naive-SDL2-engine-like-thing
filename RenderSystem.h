//
// Created by szolim on 11.02.25.
//

#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H
#include <memory>
#include <SDL_render.h>
#include <vector>

#include "RenderingLayer.h"
#include "Texture.h"

enum class RLayer { BACKGROUND=0, OTHER=1, PLAYER=2, LAYER_AMOUNT=3};

class RenderSystem {
private:
    SDL_Renderer* renderer = nullptr;
    SDL_Color background_color_;
    std::vector<RenderingLayer> layers_;
public:
    explicit RenderSystem(SDL_Window *window);
    void draw_frame();
    void init();
    [[nodiscard]] SDL_Renderer* get_renderer() const;
    void add_sprite(RLayer layer, const std::string &name, const Sprite &sprite);
    Sprite& get_sprite(RLayer layer, const std::string& name);

    void free();

    ~RenderSystem();
};



#endif //RENDERSYSTEM_H
