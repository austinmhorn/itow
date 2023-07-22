#ifndef RNG_HPP
#define RNG_HPP

#if __cplusplus < 201103L
#error "A version of c++11 or higher is required for this program"
#else

#include <random>

unsigned int random_ranged_uint(unsigned int min, unsigned int max) noexcept {
    std::mt19937 gen32(std::random_device{}());
    std::uniform_int_distribution<unsigned int> distrib(min, max);
    return distrib(gen32);
}
signed int random_ranged_int(signed int min, signed int max) noexcept {
    std::mt19937 gen32(std::random_device{}());
    std::uniform_int_distribution<signed int> distrib(min, max);
    return distrib(gen32);
}
unsigned long random_ranged_ulong(unsigned long min, unsigned long max) noexcept {
    std::mt19937 gen32(std::random_device{}());
    std::uniform_int_distribution<unsigned long> distrib(min, max);
    return distrib(gen32);
}
signed long random_ranged_long(signed long min, signed long max) noexcept {
    std::mt19937 gen32(std::random_device{}());
    std::uniform_int_distribution<signed long> distrib(min, max);
    return distrib(gen32);
}

#endif /* __cplusplus */
#endif /* RNG_HPP */
