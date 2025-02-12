//
// Created by szolim on 11.02.25.
//

#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL_render.h>
#include <string>


class Texture {
public:
    //Initializes variables
    Texture();

    //Deallocates memory
    ~Texture();

    //Loads image at specified path
    bool loadFromFile(SDL_Renderer *renderer, const std::string &path);

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render(SDL_Renderer *renderer, int x, int y) const;

    //Gets image dimensions
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] SDL_Texture* getRawTexture() const;
private:
    //The actual hardware texture
    SDL_Texture* _texture;

    int width;
    int height;
};


#endif //TEXTURE_H
