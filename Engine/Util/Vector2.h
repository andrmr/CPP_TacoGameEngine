#pragma once

// STD headers
#include <iomanip>
#include <sstream>
#include <type_traits>

// engine headers
#include "Util/Global.h"

namespace Engine {

using namespace Engine::Types;

/// \brief The Vector2 class.
/// Two dimensional vector that can be represented with floating point or integral type values.
template <typename T>
class Vector2
{
    public:
        /// \brief X component
        T x;

        /// \brief Y component
        T y;

        /// \brief Default constructor
        Vector2() = default;

        /// \brief Constructor with parameters
        /// \param x_ X component
        /// \param y_ Y component
        Vector2(T x_, T y_) : x {x_}, y {y_} {
            static_assert(std::is_arithmetic<T>::value, "Arithmetic type required.");
        }

        /// \brief Copy constructor
        /// \param rhs Object to be copied
        Vector2(const Vector2& rhs) : x {rhs.x}, y {rhs.y} {
        }

        /// \brief Assignment operator
        /// \param rhs Object to be copied
        auto operator=(const Vector2& rhs) {
            this->x = rhs.x;
            this->y = rhs.y;

            return *this;
        }

        /// \brief Default destructor
        ~Vector2() = default;

        /// \brief Adds the provided values to the vector's components.
        /// \param x_ Value to be added to the X component
        /// \param y_ Value to be added to the Y component
        auto add(T x_, T y_) {
            this->x += x_;
            this->y += y_;
        }

        /// \brief Adds another vector to the calling vector.
        /// \param rhs Object to be added
        auto add(const Vector2& rhs) {
            this->add(rhs.x, rhs.y);
        }

        /// \brief Adds another vector to the calling vector.
        /// and returns a reference to itself.
        /// \param rhs Object to be added
        auto operator+(const Vector2& rhs) {
            this->add(rhs.x, rhs.y);

            return *this;
        }

        /// \brief Subtracts the provided values from the vector's components.
        /// \param x_ Value to be subtracted from the X component
        /// \param y_ Value to be subtracted from the Y component
        auto subtract(T x_, T y_) {
            this->x += x_;
            this->y += y_;
        }

        /// \brief Subtracts another vector from the calling vector.
        /// \param rhs Object to be subtracted
        auto subtract(const Vector2& rhs) {
            this->subtract(rhs.x, rhs.y);
        }

        /// \brief Subtracts another vector from the calling vector
        /// and returns a reference to itself.
        /// \param rhs Object to be subtracted
        auto operator-(const Vector2& rhs) {
            this->subtract(rhs.x, rhs.y);

            return *this;
        }

        /// \brief Checks equality with another vector.
        /// Two vectors are equal if their components are equal.
        /// \param rhs Object to be compared with.
        template <typename U = T>
        auto equals(const Vector2& rhs) const {
            if (std::is_floating_point<U>::value) {
                return (floatCompare(this->x, rhs.x) && floatCompare(this->y, rhs.y));
            }
            else {
                return (this->x == rhs.x && this->y == rhs.y);
            }
        }

        /// \brief Equality comparison operator
        /// \param rhs Object to be compared with.
        auto operator==(const Vector2 &rhs) const {
            return this->equals(rhs);
        }

        /// \brief Scales the vector by the given value.
        /// \param factor Scaling factor.
        template <typename U>
        auto scale(U factor) {
            static_assert(std::is_arithmetic<U>::value, "Arithmetic type scaling factor required.");

            this->x *= factor;
            this->y *= factor;
        }

        /// \brief Scales the vector by the given value.
        /// \param factor Scaling factor.
        template <typename U>
        auto operator*(U factor) {
            static_assert(std::is_arithmetic<U>::value, "Arithmetic type scaling factor required.");

            this->scale(factor);

            return *this;
        }

        /// \brief Inverts the vector.
        auto invert() {
            this->scale(-1);
        }

        /// \todo
        /// [x] equals
        /// [-] multiply by vector
        /// [-] divide by vector
        /// [-] multiply by scalar
        /// [-] divide by scalar
        /// [] dot product
        /// [] cross product
        /// [x] reverse
        /// [] absolute
        /// [] distanceTo
        ///
        /// [-] reset
        /// [] rotate
        /// [] normalize
        /// [] length
        /// [] lengthSq ?

        /// \brief Provides a literal representation of the vector eg. {X, Y}
        template <typename U = T>
        auto toString() const {
            std::ostringstream out;

            if (std::is_floating_point<U>::value) {
                out << std::fixed << std::setprecision(2);
            }

            out << "{" << x << ", " << y << "}";

            return out.str();
        }
};

using vec2  = Vector2<double>;  //!< Vector2 specialization for <i>double</i>
using vec2f = Vector2<float>;   //!< Vector2 specialization for <i>float</i>
using vec2i = Vector2<int32>;   //!< Vector2 specialization for <i>int32_t</i>

} //< namespace Engine
