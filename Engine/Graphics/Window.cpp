#include "Window.h"

using namespace Engine::Graphics;

Window::Window(const std::string& title, int32 width, int32 height)
    : m_SDLWindow {SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL)}
{
    if (m_SDLWindow.get() == nullptr) {
        throw std::runtime_error("SDL_Window is NULL");
    }
}

Window& Window::operator=(Window&& rhs)
{
    if (this != &rhs) {
        m_SDLWindow = std::move(rhs.m_SDLWindow);
    }

    return *this;
}

SDL_Window *Window::get() const
{
    return m_SDLWindow.get();
}
