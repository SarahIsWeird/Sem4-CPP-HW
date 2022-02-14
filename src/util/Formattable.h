#ifndef FORMATTABLE_H
#define FORMATTABLE_H

#include <istream>
#include <concepts>

namespace util {

/* istream& operator>>(T& t) must be implemented */
template <typename T>
concept Formattable = requires(T& t) {
    std::istream() >> t;
};

}; // namespace util

#endif // FORMATTABLE_H