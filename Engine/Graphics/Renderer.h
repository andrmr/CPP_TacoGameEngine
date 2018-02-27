#pragma once

// STD headers
#include <memory>

// SDL headers
#include <SDL2/SDL.h>

// engine headers
#include "Graphics/Window.h"
#include "Util/Global.h"

namespace Engine {
namespace Graphics {

/// \brief
/// This class is a wrapper for SDL_Renderer.
class Renderer final
{
    private:
        /// \brief Deleter functor for SDL_Renderer unique_ptr.
        struct SDLRendererDeleter {
            auto operator()(SDL_Renderer* r) const {
                SDL_DestroyRenderer(r);
            }
        };

        /// \brief Pointer to SDL_Renderer
        std::unique_ptr<SDL_Renderer, SDLRendererDeleter> m_SDLRenderer {nullptr};

    public:
        /// \brief Constructor
        /// \param window Window object
        explicit Renderer(const Window& window);

        /// \brief Move operator
        /// \param rhs
        Renderer& operator=(Renderer&& rhs);

        /// \brief
        Renderer() = default;

        /// \brief
        ~Renderer() = default;

        /// \brief
        SDL_Renderer* get() const;
};

}} //< namespace Engine::Graphics
