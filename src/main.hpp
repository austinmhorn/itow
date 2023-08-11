#ifndef _MAIN__HPP
#define _MAIN__HPP

#include "itow.hpp"
#include "rng.hpp"

#include <climits> // ULONG_MAX

///////////////////////////////////////////////////////////////////////
///< @function Abort translation if input has a non digit character
///< @returns True if all characters in the input string are digits
///////////////////////////////////////////////////////////////////////
static bool hasOnlyDigits(const std::string& str)
{
    for (auto ch : str)
        if (!std::isdigit(ch))
            return false;

    return true;
}

const std::string promptUserForInputValue()
{
    std::string input = "";
    std::cout << BOLDYELLOW << "** Enter an integer " << UNDERLINE << "OR" << RESET << BOLDYELLOW << " nothing for a random value **" << RESET << std::endl;
    std::cout << ">> ";
    std::getline(std::cin, input);
    if (!input.size())
        input = std::to_string(random_ranged_ulong(0, ULONG_MAX));
    return input;
}

static std::string fetchRawInput(int argc, const char **argv)
{
    std::string input = "";
    
    try {
        if ( argc > 1 ) {
            input = argv[1];
            
            if ( !hasOnlyDigits(argv[1]) )
                throw std::runtime_error("Invalid command line arguement: \"" + input + "\" for translation -- Expected unsigned value --");
        }
        else
        {
            input = promptUserForInputValue();
            
            if ( !hasOnlyDigits(input) )
                throw std::runtime_error("Invalid command line arguement: \"" + input + "\" for translation -- Expected unsigned value --");
        }
    }
    catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    }
    
    return input;
}

static void printRawInput(const std::string& input)
{
    const unsigned WIDTH = 9;

    std::cout << std::endl;
    std::cout << BOLDYELLOW << "- Raw Input -" << RESET << std::endl;
    std::cout << '*' << std::setw(static_cast<unsigned>(WIDTH+input.size())) << std::setfill('-') << '*' << std::endl;
    std::cout << "|   " << "\"" << input << "\"" << "   |" << std::endl;
    std::cout << '*' << std::setw(static_cast<unsigned>(WIDTH+input.size())) << std::setfill('-') << '*' << std::endl;
}

#endif /* _MAIN__HPP */
