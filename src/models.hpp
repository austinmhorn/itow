#ifndef _MODELS__HPP
#define _MODELS__HPP

#include <iostream>
#include <map>
#include <vector>
#include <cmath>

/*
static void wait()
{
    std::cout << "\n*** Program Paused ***\n\tPress ENTER to continue...";
    std::cin.ignore();
    std::cout << "*** Program Resumed ***\n" << std::endl;
}
*/
template <typename _Tp> struct map_init_helper {
    _Tp& m_data;
    map_init_helper(_Tp& data) : m_data(data) {}
    map_init_helper& operator() (typename _Tp::key_type const& key, typename _Tp::mapped_type const& value)
        { m_data[key] = value; return *this; }
};

template <typename _Tp>
map_init_helper<_Tp> map_init(_Tp& item)
    { return map_init_helper<_Tp>(item); }

#endif /* _MODELS__HPP */
