//
// Created by szolim on 11.02.25.
//

#include "Texture.h"

#include <SDL_image.h>

Texture::Texture() {
    _texture = nullptr;
    width = 0;
    height = 0;
}

Texture::~Texture() {
    free();
}

bool Texture::loadFromFile(SDL_Renderer* renderer, const std::string &path) {
    free();
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        return false;
    }
    SDL_SetColorKey( surface, SDL_TRUE, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ) );

    SDL_Texture* new_texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!new_texture) {
        printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        return false;
    }
    width = surface->w;
    height = surface->h;

    SDL_FreeSurface(surface);
    _texture = new_texture;
    return true;
}

void Texture::free() {
    if (_texture) {
        SDL_DestroyTexture(_texture);
        _texture = nullptr;
        width = 0;
        height = 0;
    }
}

void Texture::render(SDL_Renderer* renderer, const int x, const int y) const {
    const SDL_Rect renderQuad = {x, y, width, height};
    SDL_RenderCopy(renderer, _texture, nullptr, &renderQuad);
}

int Texture::getWidth() const {
    return width;
}

int Texture::getHeight() const {
    return height;
}

SDL_Texture * Texture::getRawTexture() const {
    return _texture;
}