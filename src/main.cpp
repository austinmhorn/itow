#include "ntot.hpp"

int main(int argc, const char **argv)
{
    
    std::string value = "511";
    std::cout << "*** Initializing conversion (#1) ***\n" << std::endl;
    std::cout << "String Input: \"" << value << "\"" << std::endl << std::endl;
    
    ntot firstConv(value);
    firstConv.printStats();
    firstConv.print();
    
    std::cout << "\n*** Terminating conversion (#1) ***" << std::endl;
    
    
    return (EXIT_SUCCESS);
}
