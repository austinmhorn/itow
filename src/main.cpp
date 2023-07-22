#include <iostream>
#include <map>

template <typename _Tp> struct map_init_helper {
    _Tp& m_data;
    map_init_helper(_Tp& data) : m_data(data) {}
    map_init_helper& operator() (typename _Tp::key_type const& key, typename _Tp::mapped_type const& value)
        { m_data[key] = value; return *this; }
};

template <typename _Tp>
map_init_helper<_Tp> map_init(_Tp& item)
    { return map_init_helper<_Tp>(item); }








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
    Seventy     = 26,
    Eighty      = 27,
    Ninety      = 28,
    Hundred     = 29,
    Thousand    = 30,
    Million     = 31,
    Billion     = 32,
    Trillion    = 33,
    Quadrillion = 34,
    Quintillion = 35,
    Sextillion  = 36,
    Septillion  = 37,
    Octillion   = 38,
    Nonillion   = 39,
    Decillion   = 40,
    
    ///< Keep Last -- determines number of enumerations
    Count = 41
};

static const std::map<Dictionary, const char *> dictmap;

static void init_dictmap() {
    map_init(dictmap)
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



int main(int argc, const char **argv)
{
    
    
    return (EXIT_SUCCESS);
}
