#include "itow.hpp"

#include <iomanip> // std::setw, std::setfill
#include <cstring> // strlen
#include <string>  // std::stoi
#include <cstdlib> // std::atoi

itow::itow(const std::string& input)
    : m_input(input)
    , m_size(input.size())
    , m_numGroups(0)
    , m_numUngrouped(m_size % 3)
    , m_ungrouped(0)
    , m_hasOneNonzero(false)
{
    __init_dictmap();
    
    m_grpVect.clear();
    m_strVect.clear();
    
    init();
    
    digest();
}

itow::~itow()
{
    m_grpVect.clear();
    m_strVect.clear();
}

void itow::print()
{
    auto spacing = static_cast<unsigned>(calcSpacing() + m_input.size() + 6 + m_strVect.size());
    
    std::cout << '\n' << BOLDGREEN << "- Result -" << RESET << std::endl;
    std::cout << '*' << std::setw(spacing) << std::setfill('-') << '*' << std::endl;
    std::cout << "| " << m_input << " -> ";
    for (auto s : m_strVect)
        std::cout << s << " ";
    std::cout << "|";
    std::cout << '\n' << '*' << std::setw(spacing) << std::setfill('-') << '*' << std::endl;
}

void itow::printStats()
{
    const int WIDTH = 40;
    std::string ungroupedStr = std::to_string(m_ungrouped);
    std::string sizeStr = std::to_string(m_size);
    std::string numGroupsStr = std::to_string(m_numGroups);
    std::string numUngroupedStr = std::to_string(m_numUngrouped);
    
    std::cout << '\n' << BOLDYELLOW << "- Transliteration Statistics -" << RESET << std::endl;
    std::cout << '*' << std::setw(WIDTH) << std::setfill('-') << '*' << std::endl;
    std::cout << MSG_STAT_INPUT        << m_input        << std::setw(static_cast<unsigned>(WIDTH-strlen(MSG_STAT_INPUT)-static_cast<unsigned>(m_input.size()) + 1))                << std::setfill(' ') << '|' <<std::endl;
    std::cout << MSG_STAT_SIZE         << m_size         << std::setw(static_cast<unsigned>(WIDTH-strlen(MSG_STAT_SIZE)-static_cast<unsigned>(sizeStr.size()) + 1))                 << std::setfill(' ') << '|' <<std::endl;
    std::cout << MSG_STAT_NUMGROUPS    << m_numGroups    << std::setw(static_cast<unsigned>(WIDTH-strlen(MSG_STAT_NUMGROUPS)-static_cast<unsigned>(numGroupsStr.size()) + 1))       << std::setfill(' ') << '|' <<std::endl;
    std::cout << MSG_STAT_NUMUNGROUPED << m_numUngrouped << std::setw(static_cast<unsigned>(WIDTH-strlen(MSG_STAT_NUMUNGROUPED)-static_cast<unsigned>(numUngroupedStr.size()) + 1)) << std::setfill(' ') << '|' <<std::endl;
    std::cout << MSG_STAT_UNGROUPED    << m_ungrouped    << std::setw(static_cast<unsigned>(WIDTH-strlen(MSG_STAT_UNGROUPED)-static_cast<unsigned>(ungroupedStr.size()) + 1))       << std::setfill(' ') << '|' <<std::endl;
    std::cout << '*' << std::setw(WIDTH) << std::setfill('-') << '*' << std::endl;
}

void itow::init()
{
    m_hasOneNonzero = hasOneNonzero();
    
    calcNumGroups();
    calcNumUngrouped();
    assignUngrouped();
    populateGrpVect();
}

bool itow::hasOneNonzero()
{
    unsigned int zeroCnt = 0;
    unsigned int nonZeroCnt = 0;
    
    for (auto ch : m_input)
        ( ch == '0' ) ? zeroCnt++ : nonZeroCnt++ ;
    
    return (nonZeroCnt == 1 && zeroCnt >= 3);
}

unsigned int itow::calcSpacing()
{
    unsigned int chCount = 0;
    // Determine # of characters in the entire result string
    for (auto s : m_strVect)
        chCount += s.size();

    return chCount;
}

void itow::calcNumGroups()
{
    std::size_t size = m_size;
    while (size >= 3)
        { m_numGroups++; size -= 3; }
}

void itow::calcNumUngrouped()
{
    m_numUngrouped = m_size % 3;
}

void itow::assignUngrouped()
{
    std::string str = m_input.substr(0, m_numUngrouped);
    if ( str.size() )
        m_ungrouped = std::stoi(str);
}

void itow::populateGrpVect()
{
    unsigned long pos = m_numUngrouped;
    for (int i = 0; i < m_numGroups; i++)
    {
        std::string grpStr = m_input.substr(pos, 3);
        Group group;
        
        char ch = grpStr.at(0);
        std::get<0>(group) = std::stoi(&ch);
        ch = grpStr.at(1);
        std::get<1>(group) = std::stoi(&ch);
        ch = grpStr.at(2);
        std::get<2>(group) = std::stoi(&ch);
        
        m_grpVect.push_back(group);
        
        // Move cursor position
        pos+=3;
    }
}

void itow::digest()
{
    // Digest ungrouped values
    if ( m_numUngrouped )
        digestUngrouped();
    // Digest grouped values group by group
    if ( m_hasOneNonzero && m_size >= 4 )
        m_strVect.push_back( dictmap.at(static_cast<Dictionary>( 28 + m_numGroups )) );
    else {
        unsigned num = 0;
        for (auto group : m_grpVect)
            digestGroup(group, ++num);
    }
}

void itow::digestUngrouped()
{
    std::string str = std::to_string(m_ungrouped);
    
    if ( m_numUngrouped == 1 )
    {
        m_strVect.push_back( dictmap.at(static_cast<Dictionary>( m_ungrouped )) );
        
        if ( m_size >= 4 )
            m_strVect.push_back( dictmap.at(static_cast<Dictionary>( m_numGroups + 28 )) );
    }
    else if ( m_numUngrouped == 2 )
    {
        std::pair<unsigned int, unsigned int> p = std::make_pair(std::stoi(str.substr(0, 1)), std::atoi(&str.at(1)));
        
        if ( p.first > 1 ) {
            m_strVect.push_back( dictmap.at(static_cast<Dictionary>( p.first + 18 )) );
            
            if ( p.second != 0 )
                m_strVect.push_back( dictmap.at(static_cast<Dictionary>( p.second )) );
        }
        else
            m_strVect.push_back( dictmap.at(static_cast<Dictionary>( p.second + 10 )) );
        
        if (m_size > 2)
            m_strVect.push_back( dictmap.at(static_cast<Dictionary>( m_numGroups + 28 )) );
    }
}

void itow::digestGroup(const Group& group, const int num)
{
    printGroup(group, num);
    
    int ones = std::get<2>(group);
    int tens = std::get<1>(group);
    int hnds = std::get<0>(group);
    
    if ( hnds > 0 ) {
        m_strVect.push_back( dictmap.at(static_cast<Dictionary>(std::get<0>(group))) );
        m_strVect.push_back( dictmap.at(Dictionary::Hundred) );
    }
    
    if ( tens > 1 )
        m_strVect.push_back( dictmap.at(static_cast<Dictionary>( tens + 18 )) );
    else if ( tens == 1 )
        m_strVect.push_back( dictmap.at(static_cast<Dictionary>( ones + 10 )) );

    if ( tens != 1 && ones != 0 )
        m_strVect.push_back( dictmap.at(static_cast<Dictionary>( ones )) );
    
    if ( m_numGroups - num > 0 )
        m_strVect.push_back( dictmap.at((static_cast<Dictionary>(static_cast<unsigned>(m_numGroups - num) + 28))) );
}
