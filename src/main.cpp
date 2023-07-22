#include "main.hpp"
#include <iomanip>

const std::string promptUserForInputValue();

int main(int argc, const char **argv)
{
    
    std::string value = promptUserForInputValue();
    const unsigned WIDTH = 9;
    
    std::cout << std::endl << std::endl;
    std::cout << BOLDYELLOW << "- Raw Input -" << RESET << std::endl;
    std::cout << '*' << std::setw(static_cast<unsigned>(WIDTH+value.size())) << std::setfill('-') << '*' << std::endl;
    std::cout << "|   " << "\"" << value << "\"" << "   |" << std::endl;
    std::cout << '*' << std::setw(static_cast<unsigned>(WIDTH+value.size())) << std::setfill('-') << '*' << std::endl;
    
    //waitForEnter();
    
    ntot converter(value);
    converter.printStats();
    converter.print();
    
    //std::cout << "\n*** Terminating conversion (#1) ***" << std::endl;
    
    return (EXIT_SUCCESS);
}
