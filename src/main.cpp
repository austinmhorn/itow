#include "ntot.hpp"

const std::string promptUserForInputValue();

int main(int argc, const char **argv)
{
    
    std::string value = promptUserForInputValue();
    
    //std::cout << "*** Initializing conversion (#1) ***" << std::endl;
    std::cout << '\n' << "Input being translated: \"" << value << "\"" << std::endl;
    
    ntot converter(value);
    converter.printStats();
    converter.print();
    
    //std::cout << "\n*** Terminating conversion (#1) ***" << std::endl;
    
    
    return (EXIT_SUCCESS);
}

const std::string promptUserForInputValue()
{
    std::cout << "** Enter an integer OR nothing for a random value **" << std::endl;
    std::string input = "11897";
    //std::getline(std::cin, input);
    return input;
}
