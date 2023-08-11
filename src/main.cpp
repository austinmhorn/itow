#include "main.hpp"

int main(int argc, const char **argv) {
    
    std::string input = fetchRawInput(argc, argv);
    
    printRawInput(input);
    itow converter(input);
    converter.printStats();
    converter.print();
    
    return (EXIT_SUCCESS);
}
