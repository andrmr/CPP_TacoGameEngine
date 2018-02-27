#include "Renderer.h"

using namespace Engine::Graphics;

Renderer::Renderer(const Window& window)
    : m_SDLRenderer {SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)}
{

}

Renderer& Renderer::operator=(Renderer&& rhs)
{
    if (this != &rhs) {
        m_SDLRenderer = std::move(rhs.m_SDLRenderer);
    }

    return *this;
}

SDL_Renderer *Renderer::get() const
{
    return m_SDLRenderer.get();
}
