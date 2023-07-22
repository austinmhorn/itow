#ifndef _NTOT__HPP
#define _NTOT__HPP

#include "dictionary.hpp"

class ntot
{
public:
    ntot(const std::string& input);
    
    ~ntot();
    
    void print();
    void printStats();
    
private:
    
    void init();
    
    bool hasOnlyDigits();
    void calcNumGroups();
    void calcNumUngrouped();
    void assignUngrouped();
    void populateGrpVect();
    
    void digest();
    void digestSmall();
    void digestGroup(const Group& group);
    
    
private:
    
    std::string              m_input;
    std::size_t              m_size;
    std::size_t              m_numGroups;
    std::size_t              m_numUngrouped;
    unsigned short int       m_ungrouped;
    unsigned int             m_npos;
    std::vector<Group>       m_grpVect;
    std::vector<std::string> m_strVect;
};

#endif /* _NTOT__HPP */
