#ifndef _DICTIONARY__HPP
#define _DICTIONARY__HPP

#include "models.hpp"

#include <iomanip>

typedef std::tuple<int, int, int> Group;

static void printGroup(const Group& group, const int num)
{
    const unsigned WIDTH = 20;
    
    std::cout << std::endl;
    std::cout << BOLDYELLOW << "- Digesting Group " << num << " -" << RESET << std::endl;
    std::cout << '*'  << std::setw(WIDTH) << std::setfill('-') << '*' << std::endl;
    std::cout << "|     ";
    std::cout << std::get<0>(group) << "   " << std::get<1>(group) << "   " << std::get<2>(group) << "     |" << std::endl;
    std::cout << '*' << std::setw(WIDTH) << std::setfill('-') << '*' << std::endl;
}

enum class Dictionary : unsigned {
    Zero        = 0,
    One         = 1,
    Two         = 2,
    Three       = 3,
    Four        = 4,
    Five        = 5,
    Six         = 6,
    Seven       = 7,
    Eight       = 8,
    Nine        = 9,
    Ten         = 10,
    Eleven      = 11,
    Twelve      = 12,
    Thirteen    = 13,
    Fourteen    = 14,
    Fifteen     = 15,
    Sixteen     = 16,
    Seventeen   = 17,
    Eighteen    = 18,
    Nineteen    = 19,
    Twenty      = 20,
    Thirty      = 21,
    Fourty      = 22,
    Fifty       = 23,
    Sixty       = 24,
    Seventy     = 25,
    Eighty      = 26,
    Ninety      = 27,
    Hundred     = 28,
    Thousand    = 29,
    Million     = 30,
    Billion     = 31,
    Trillion    = 32,
    Quadrillion = 33,
    Quintillion = 34,
    Sextillion  = 35,
    Septillion  = 36,
    Octillion   = 37,
    Nonillion   = 38,
    Decillion   = 39,
    
    ///< Keep Last -- determines number of enumerations
    Count = 40
};

static std::map<Dictionary, const char *> dictmap;

static void __init_dictmap() {
    init_primitive_map(dictmap)
        (Dictionary::Zero,        "Zero")
        (Dictionary::One,         "One")
        (Dictionary::Two,         "Two")
        (Dictionary::Three,       "Three")
        (Dictionary::Four,        "Four")
        (Dictionary::Five,        "Five")
        (Dictionary::Six,         "Six")
        (Dictionary::Seven,       "Seven")
        (Dictionary::Eight,       "Eight")
        (Dictionary::Nine,        "Nine")
        (Dictionary::Ten,         "Ten")
        (Dictionary::Eleven,      "Eleven")
        (Dictionary::Twelve,      "Twelve")
        (Dictionary::Thirteen,    "Thirteen")
        (Dictionary::Fourteen,    "Fourteen")
        (Dictionary::Fifteen,     "Fifteen")
        (Dictionary::Sixteen,     "Sixteen")
        (Dictionary::Seventeen,   "Seventeen")
        (Dictionary::Eighteen,    "Eighteen")
        (Dictionary::Nineteen,    "Nineteen")
        (Dictionary::Twenty,      "Twenty")
        (Dictionary::Thirty,      "Thirty")
        (Dictionary::Fourty,      "Fourty")
        (Dictionary::Fifty,       "Fifty")
        (Dictionary::Sixty,       "Sixty")
        (Dictionary::Seventy,     "Seventy")
        (Dictionary::Eighty,      "Eighty")
        (Dictionary::Ninety,      "Ninety")
        (Dictionary::Hundred,     "Hundred")
        (Dictionary::Thousand,    "Thousand")
        (Dictionary::Million,     "Million")
        (Dictionary::Billion,     "Billion")
        (Dictionary::Trillion,    "Trillion")
        (Dictionary::Quadrillion, "Quadrillion")
        (Dictionary::Quintillion, "Quintillion")
        (Dictionary::Sextillion,  "Sextillion")
        (Dictionary::Septillion,  "Septillion")
        (Dictionary::Octillion,   "Octillion")
        (Dictionary::Nonillion,   "Nonillion")
        (Dictionary::Decillion,   "Decillion")
    ;
}

#endif /* _DICTIONARY__HPP */
