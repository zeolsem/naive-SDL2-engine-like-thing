//
// Created by szolim on 11.02.25.
//

#ifndef SPRITE_H
#define SPRITE_H
#include <memory>

#include "Texture.h"

struct Position {
    int x;
    int y;
};

class Sprite {
    Position pos_;
    std::shared_ptr<Texture> texture_;
public:
    Sprite(const std::shared_ptr<Texture> &texture, const Position& pos);
    ~Sprite();
    [[nodiscard]] Position get_position() const;
    void set_position(int x, int y);
    void update_position(int dx, int dy);

    std::shared_ptr<Texture> get_texture();
    void set_texture(const std::shared_ptr<Texture> &texture);
    void draw(SDL_Renderer* renderer) const;
};



#endif //SPRITE_H
