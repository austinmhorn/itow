#ifndef _NTOT__HPP
#define _NTOT__HPP

#include "dictionary.hpp"

#define MSG_STAT_INPUT        "| input:        "
#define MSG_STAT_SIZE         "| size:         "
#define MSG_STAT_NUMGROUPS    "| numGroups:    "
#define MSG_STAT_NUMUNGROUPED "| numUngrouped: "
#define MSG_STAT_UNGROUPED    "| ungrouped:    "



class ntot
{
public:
    // Default constructor
    ntot(const std::string& input);
    // Destructor
    ~ntot();
    
    // Mutators
    void setInput(const std::string& input);
    
    // Accessors
    const std::string& getInput() const;
    
    // Print Functions
    void print();
    void printStats();
    
private:
    
    void init();
    
    // Aborts translation if any character in the input is not a digit
    bool hasOnlyDigits();
    // Helper function for drawing box around result
    unsigned int calcSpacing();
    // Calculates # of "Groups", or tuple or 3 numbers
    void calcNumGroups();
    // Calculates # of ungrouped members
    void calcNumUngrouped();
    // Set ungrouped value
    void assignUngrouped();
    // Populate group vector with each complete group
    void populateGrpVect();
    
    // Main digestion call
    void digest();
    // Digest input value that has 0 complete groups
    void digestSmall();
    // Digest a single group
    void digestGroup(const Group& group);
    
    
private:
    
    std::string              m_input;        ///< Raw input string
    std::size_t              m_size;         ///< Length of input string
    std::size_t              m_numGroups;    ///< Number of groups 
    std::size_t              m_numUngrouped; ///< Number of ungrouped values [0-2]
    unsigned short int       m_ungrouped;    ///< Integer value of ungrouped numbers
    unsigned int             m_npos;         ///< Input string cursor position
    std::vector<Group>       m_grpVect;      ///< Stores groups in order of processing
    std::vector<std::string> m_strVect;      ///< Stores result translations
};

#endif /* _NTOT__HPP */
