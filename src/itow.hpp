#ifndef _ITOW__HPP
#define _ITOW__HPP

#include "dictionary.hpp"

#include <iomanip>

#define MSG_STAT_INPUT        "| input:        "
#define MSG_STAT_SIZE         "| size:         "
#define MSG_STAT_NUMGROUPS    "| numGroups:    "
#define MSG_STAT_NUMUNGROUPED "| numUngrouped: "
#define MSG_STAT_UNGROUPED    "| ungrouped:    "

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

class itow
{
public:
    // Default constructor
    itow(const std::string& input);
    // Destructor
    ~itow();
    
    // Print Functions
    void print();
    void printStats();
    
private:
    
    void init();
    
    ///////////////////////////////////////////////////////////////////////
    ///< @function Abort translation if input has a non digit character
    ///< @returns True if all characters in the input string are digits
    ///< @see init
    ///////////////////////////////////////////////////////////////////////
    bool hasOnlyDigits();
    
    ///////////////////////////////////////////////////////////////////////
    ///< @function Determines if input has one or more non-zero value(s)
    ///< @returns True if input has 1 and only 1 non-zero value
    ///< @see init
    ///////////////////////////////////////////////////////////////////////
    bool hasOneNonzero();
    
    ///////////////////////////////////////////////////////////////////////
    ///< @function Helper function for drawing box around result
    ///< @returns # of characters in result string
    ///< @see print
    ///////////////////////////////////////////////////////////////////////
    unsigned int calcSpacing();

    ///////////////////////////////////////////////////////////////////////
    ///< @function Calculates # of "Groups", or tuple or 3 numbers
    ///< @see init
    ///////////////////////////////////////////////////////////////////////
    void calcNumGroups();
    
    ///////////////////////////////////////////////////////////////////////
    ///< @function Calculates # of ungrouped members
    ///< @see init
    ///////////////////////////////////////////////////////////////////////
    void calcNumUngrouped();
    
    ///////////////////////////////////////////////////////////////////////
    ///< @function Determine ungrouped integer value
    ///< @see init
    ///////////////////////////////////////////////////////////////////////
    void assignUngrouped();
    
    ///////////////////////////////////////////////////////////////////////
    ///< @function Populate group vector with each complete group
    ///< @see init
    ///////////////////////////////////////////////////////////////////////
    void populateGrpVect();
    
    ///////////////////////////////////////////////////////////////////////
    ///< @function Heart of digestion
    ///< @see init
    ///////////////////////////////////////////////////////////////////////
    void digest();
    
    ///////////////////////////////////////////////////////////////////////
    ///< @function Digest ungrouped values
    ///< @see init
    ///////////////////////////////////////////////////////////////////////
    void digestUngrouped();
    
    ///////////////////////////////////////////////////////////////////////
    ///< @function Digest a single group
    ///< @see init
    ///////////////////////////////////////////////////////////////////////
    void digestGroup(const Group& group, const int groupNum);
    
    
private:
    
    std::string              m_input;         ///< Raw input string
    std::size_t              m_size;          ///< Length of input string
    std::size_t              m_numGroups;     ///< Number of groups
    std::size_t              m_numUngrouped;  ///< Number of ungrouped values [0-2]
    unsigned short int       m_ungrouped;     ///< Integer value of ungrouped numbers
    std::vector<Group>       m_grpVect;       ///< Stores groups in order of processing
    std::vector<std::string> m_strVect;       ///< Stores result translations
    bool                     m_hasOneNonzero;
};

#endif /* _ITOW__HPP */
