//
// Created by tfraisse on 17/12/23.
//
#include "Window.hpp"

#include <utility>
using namespace std;
Window::Window():m_window(nullptr),m_renderer(nullptr),m_background_texture(),m_forward(){ }
Window::~Window(){
    m_background_texture.free();
    m_forward.free();
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    m_renderer = nullptr;
    m_window = nullptr;
}
bool Window::setup_window(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf(" Error during SDL init : %s \n", SDL_GetError());
        return false;
    }

    m_window=SDL_CreateWindow("Connect Four",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,0);
    if(!m_window){
        printf(" Error during window creation : %s \n", SDL_GetError());
        return false;
    }
    m_renderer= SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED);
    if(!m_renderer){
        printf(" Error during rendering : %s \n", SDL_GetError());
        return false;
    }
    //set the color of the window after rendering
    SDL_SetRenderDrawColor(m_renderer,0xFF,0xFF,0xFF,0xFF);
    int imgFLAGS=IMG_INIT_PNG;
    if(IMG_Init(imgFLAGS) < 0){
        printf(" Error during img init : %s \n", SDL_GetError());
        return false;
    }
    return true;
}
bool Window::load_background(){
    if(!m_background_texture.load_image("./image/plateau.png",m_renderer)){
        printf("Unable to load image: %s \n",IMG_GetError());
        return false;
    }
    SDL_RenderClear(m_renderer);
    m_background_texture.render(0,0,m_renderer);
    SDL_RenderPresent(m_renderer);
    return true;
}
bool Window::event_handler(){
}
bool Window::load_pion(string path, int x, int y ){
    if(!m_forward.load_image(std::move(path),m_renderer)){
        printf("Unable to load image: %s \n",IMG_GetError());
        return false;
    }
    m_forward.render(x,y,m_renderer);
    SDL_RenderPresent(m_renderer);
}