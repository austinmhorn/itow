#include "main.hpp"
#include <iomanip>

int main(int argc, const char **argv)
{
    
    //std::string input = promptUserForInputValue();
    
    for (int i = 0; i < 1000000; i++)
    {
        std::string input = std::to_string(i);
        
        printRawInput(input);
        
        ntot converter(input);
        
        converter.printStats();
        converter.print();
    }
    
    
    return (EXIT_SUCCESS);
}
