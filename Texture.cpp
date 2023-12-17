//
// Created by tfraisse on 17/12/23.
//

#include "Texture.hpp"
using namespace std;
Texture::Texture():m_height(0),m_widht(0),m_texture(nullptr){}
Texture::~Texture() {
    free();
}
void Texture::render(int x,int y,SDL_Renderer *w_renderer){
    SDL_Rect render= {x,y,m_widht,m_height};
    SDL_RenderCopy(w_renderer,m_texture,NULL,&render);
}
bool Texture::load_image(string path,SDL_Renderer *w_renderer){
    SDL_Surface *optimize_surface = IMG_Load(path.c_str());
    if(!optimize_surface){
        printf("Unable to load image : %s \n",IMG_GetError());
        return false;
    }
    SDL_SetColorKey(optimize_surface,SDL_TRUE,SDL_MapRGB( optimize_surface->format, 0, 0xFF, 0xFF ));
    m_texture= SDL_CreateTextureFromSurface(w_renderer,optimize_surface);
    if(!m_texture){
        printf("Unable to create texture : %s \n", IMG_GetError());
    }
    m_widht=optimize_surface->w;
    m_height=optimize_surface->h;
    SDL_FreeSurface(optimize_surface);
    return m_texture != NULL;
}
void Texture::free(){
    if(m_texture) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
        m_widht = 0;
        m_height = 0;
    }
}
int Texture::get_width(){
    return m_widht;
}
int Texture::get_height(){
    return m_height;
}