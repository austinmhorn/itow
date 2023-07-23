#ifndef _MAIN__HPP
#define _MAIN__HPP

#include "itow.hpp"
#include "rng.hpp"

#include <climits> // ULONG_MAX

/* Escape Codes */
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
