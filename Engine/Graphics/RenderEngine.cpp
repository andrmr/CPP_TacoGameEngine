#include "RenderEngine.h"

using namespace Engine::Graphics;

void RenderEngine::Begin() {
    SDL_Init(SDL_INIT_VIDEO);

    m_window = Window("My Window", 640, 480);
    m_renderer = Renderer(m_window);
}

void RenderEngine::Draw() {
    SDL_Surface* bmp = SDL_LoadBMP("mario.bmp");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(m_renderer.get(), bmp);
    SDL_FreeSurface(bmp);
    SDL_RenderClear(m_renderer.get());
    SDL_RenderCopy(m_renderer.get(), tex, NULL, NULL);
    SDL_RenderPresent(m_renderer.get());
}

void RenderEngine::Stop() {
    SDL_Quit();
}
