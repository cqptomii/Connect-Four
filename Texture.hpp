//
// Created by tfraisse on 17/12/23.
//

#ifndef CONNECT_FOUR_TEXTURE_HPP
#define CONNECT_FOUR_TEXTURE_HPP
#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"
#include <string>
class Texture {
public:
    Texture();
    ~Texture();
    bool load_image(std::string path,SDL_Renderer *w_renderer);
    virtual void render(int x,int y,SDL_Renderer *w_renderer);
    int get_width();
    void free();
    int get_height();
protected:
    int m_widht;
    int m_height;
    SDL_Texture *m_texture;
};
#endif //CONNECT_FOUR_TEXTURE_HPP
