#pragma once

#include <cmath>
#include <limits>
#include <type_traits>
#include <stdint.h>

namespace Engine {

    namespace Types {

        using cstring   = const char*;
        using uint8     = uint8_t;
        using uint32    = uint32_t;
        using int8      = int8_t;
        using int32     = int32_t;
    }

template <typename T>
inline bool floatCompare(T a, T b)
{
    static_assert(std::is_floating_point<T>::value, "Floating point type required.");

    return std::nextafter(a, std::numeric_limits<double>::lowest()) <= b
        && std::nextafter(a, std::numeric_limits<double>::max()) >= b;
}

template <typename T>
struct SDLTypeDeleter
{
    void (*Deleter)(T*);

    SDLTypeDeleter(void (*Deleter_)(T*) ) : Deleter {Deleter_}
    {

    }

    auto operator()(T* object) const {
        this->Deleter(object);
    }
};

}
