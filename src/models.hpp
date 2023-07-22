#ifndef _MODELS__HPP
#define _MODELS__HPP

#include <iostream>
#include <map>
#include <vector>
#include <cmath>

#define RESET       "\033[0m"         ///< Reset
#define BLACK       "\033[30m"        ///< Black
#define RED         "\033[31m"        ///< Red
#define GREEN       "\033[32m"        ///< Green
#define YELLOW      "\033[33m"        ///< Yellow
#define BLUE        "\033[34m"        ///< Blue
#define MAGENTA     "\033[35m"        ///< Magenta
#define CYAN        "\033[36m"        ///< Cyan
#define WHITE       "\033[37m"        ///< White
#define BOLDBLACK   "\033[1m\033[30m" ///< Bold Black
#define BOLDRED     "\033[1m\033[31m" ///< Bold Red
#define BOLDGREEN   "\033[1m\033[32m" ///< Bold Green
#define BOLDYELLOW  "\033[1m\033[33m" ///< Bold Yellow
#define BOLDBLUE    "\033[1m\033[34m" ///< Bold Blue
#define BOLDMAGENTA "\033[1m\033[35m" ///< Bold Magenta
#define BOLDCYAN    "\033[1m\033[36m" ///< Bold Cyan
#define BOLDWHITE   "\033[1m\033[37m" ///< Bold White
#define BOLD        "\033[1m"         ///< Bold
#define ITALIC      "\033[3m"         ///< Italic
#define UNDERLINE   "\033[4m"         ///< Underline

static void waitForEnter()
{
    std::cout << ITALIC << "\n>> Press " << RESET << BOLDGREEN << "ENTER" << RESET << ITALIC << " to continue..." << RESET;
    std::cin.ignore();
    std::cout << std::flush;
}

template <
    typename _Tp,
    typename _Alloc     = std::allocator<_Tp>,
    typename _Distance  = std::ptrdiff_t,
    typename _Pointer   = _Tp*,
    typename _Reference = _Tp&
> struct primitive_map {
protected:
    typedef _Tp                       value_type;
    typedef _Alloc                    allocator;
    typedef _Pointer                  pointer;
    typedef _Reference                reference;
    typedef typename _Tp::key_type    key_type;
    typedef typename _Tp::mapped_type mapped_type;

    reference m_data;
public:
    primitive_map(reference data)
        : m_data(data) {}
    primitive_map& operator() (key_type const& key, mapped_type const& value)
        { m_data[key] = value; return *this; }
};

template <typename _Tp>
primitive_map<_Tp> init_primitive_map(_Tp& item)
    { return primitive_map<_Tp>(item); }



#endif /* _MODELS__HPP */
