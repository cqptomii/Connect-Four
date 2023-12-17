//
// Created by tfraisse on 17/12/23.
//
#ifndef CONNECT_FOUR_WINDOW_HPP
#define CONNECT_FOUR_WINDOW_HPP
#include "Texture.hpp"
#include "string"
#define SCREEN_WIDTH 649
#define SCREEN_HEIGHT 642
class Window{
public:
    Window();
    ~Window();
    bool setup_window();
    bool event_handler();
    bool load_background();
    bool load_pion(std::string path, int x, int y);
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    Texture m_background_texture;
    Texture m_forward;
};
#endif //CONNECT_FOUR_WINDOW_HPP
