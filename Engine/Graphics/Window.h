#pragma once

// STD headers
#include <memory>
#include <string>

// SDL headers
#include <SDL2/SDL.h>

// engine headers
#include "Util/Global.h"

namespace Engine {
namespace Graphics {

using namespace Engine::Types;

/// \brief The Window class
/// This class is a wrapper for SDL_Window.
class Window final
{
    private:
        /// \brief Deleter functor for the SDL_Window unique_ptr.
        struct SDLWindowDeleter {
            auto operator()(SDL_Window* w) const {
                SDL_DestroyWindow(w);
            }
        };

        /// \brief Pointer which holds an SDL2 window.
        std::unique_ptr<SDL_Window, SDLWindowDeleter> m_SDLWindow {nullptr};

    public:
        /// \brief Constructor
        /// \param title Title of the window
        /// \param width Width of the window, in pixels
        /// \param height Height of the window, in pixels
        explicit Window(const std::string& title, int32 width, int32 height);

        /// \brief Move operator
        Window& operator=(Window&& rhs);

        /// \brief Default constructor
        Window() = default;

        /// \brief Default destructor
        ~Window() = default;

        /// \brief Returns an observing raw pointer
        SDL_Window* get() const;
};

}} //< namespace Engine::Graphics
