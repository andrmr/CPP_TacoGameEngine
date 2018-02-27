#pragma once

// SDL headers
#include <SDL2/SDL.h>

// project headers
#include "Renderer.h"
#include "Window.h"

namespace Engine {
namespace Graphics {

/// \brief
class RenderEngine final
{
    private:
        /// \brief
        Renderer m_renderer;

        /// \brief
        Window m_window;

        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window_ {nullptr, SDL_DestroyWindow};

    public:
        /// \brief Default constructor
        RenderEngine() = default;

        ~RenderEngine() = default;

        /// \brief Starts the rendering
        void Begin();

        /// \brief Draws the texture
        void Draw();

        /// \brief Stops the rendering
        void Stop();
};

}} //< namespace Engine::Graphics
