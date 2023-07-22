#include "ntot.hpp"
#include <iomanip>

ntot::ntot(const std::string& input)
    : m_input(input)
    , m_size(input.size())
    , m_numGroups(0)
    , m_numUngrouped(m_size % 3)
    , m_ungrouped(0)
    , m_npos(0)
{
    __init_dictmap();
    
    m_grpVect.clear();
    m_strVect.clear();
    
    init();
    
    digest();
}

ntot::~ntot()
{
    m_grpVect.clear();
    m_strVect.clear();
}

void ntot::setInput(const std::string& input)
{
    m_input = input;
}

const std::string& ntot::getInput() const
{
    return m_input;
}

void ntot::print()
{
    unsigned spacing = static_cast<unsigned>(calcSpacing() + m_input.size() + 4);
    
    std::cout << '\n' << "- Result" << std::endl;
    std::cout << '*' << std::setw(spacing) << std::setfill('-') << '*' << std::endl;
    std::cout << "| " << m_input << " -> ";
    for (auto s : m_strVect)
        std::cout << s << " ";
    std::cout << "|";
    std::cout << '\n' << '*' << std::setw(spacing) << std::setfill('-') << '*' << std::endl;
}

void ntot::printStats()
{
    const int WIDTH = 60;
    std::string ungroupedStr = std::to_string(m_ungrouped);
    std::string sizeStr = std::to_string(m_size);
    std::string numUngroupedStr = std::to_string(m_numUngrouped);
    
    std::cout << '\n' << "- Transliteration Statistics" << std::endl;
    std::cout << '*' << std::setw(WIDTH) << std::setfill('-') << '*' << std::endl;
    std::cout << MSG_STAT_INPUT        << m_input        << std::setw(static_cast<unsigned>(WIDTH-strlen(MSG_STAT_INPUT)-static_cast<unsigned>(m_input.size()) + 1))                << std::setfill(' ') << '|' <<std::endl;
    std::cout << MSG_STAT_SIZE         << m_size         << std::setw(static_cast<unsigned>(WIDTH-strlen(MSG_STAT_SIZE)-static_cast<unsigned>(sizeStr.size()) + 1))                 << std::setfill(' ') << '|' <<std::endl;
    std::cout << MSG_STAT_NUMGROUPS    << m_numGroups    << std::setw(static_cast<unsigned>(WIDTH-strlen(MSG_STAT_NUMGROUPS)-static_cast<unsigned>(m_numGroups) + 1))               << std::setfill(' ') << '|' <<std::endl;
    std::cout << MSG_STAT_NUMUNGROUPED << m_numUngrouped << std::setw(static_cast<unsigned>(WIDTH-strlen(MSG_STAT_NUMUNGROUPED)-static_cast<unsigned>(numUngroupedStr.size()) + 1)) << std::setfill(' ') << '|' <<std::endl;
    std::cout << MSG_STAT_UNGROUPED    << m_ungrouped    << std::setw(static_cast<unsigned>(WIDTH-strlen(MSG_STAT_UNGROUPED)-static_cast<unsigned>(ungroupedStr.size()) + 1))       << std::setfill(' ') << '|' <<std::endl;
    std::cout << '*' << std::setw(WIDTH) << std::setfill('-') << '*' << std::endl;
}

void ntot::init()

{
    if ( !hasOnlyDigits() )
        return;
    calcNumGroups();
    calcNumUngrouped();
    assignUngrouped();
    populateGrpVect();
}

bool ntot::hasOnlyDigits()
{
    for (auto ch : m_input)
    {
        if (!std::isdigit(ch))
            return false;
    }
    return true;
}

unsigned int ntot::calcSpacing()
{
    unsigned int chCount = 0;
    unsigned int wdCount = 0;
    // Determine # of characters in the entire result string
    for (auto s : m_strVect)
    {
        chCount += s.size();
        wdCount++;
    }
    
    // Configure left/right padding with respect to word count
    if (wdCount < 2)
        chCount += (2 * m_strVect.size()) + 1;
    else if (wdCount % 2 == 0) // Even
        chCount += (2 * m_strVect.size()) - 2;
    else
        chCount += (2 * m_strVect.size()) - 1;
    
    return chCount;
}

void ntot::calcNumGroups()
{
    std::size_t size = m_size;
    while (size >= 3)
    { m_numGroups++; size -= 3; }
}

void ntot::calcNumUngrouped()
{
    m_numUngrouped = m_size % 3;
}

void ntot::assignUngrouped()
{
    std::string str = m_input.substr(0, m_numUngrouped);
    if ( str.size() )
        m_ungrouped = std::stoi(str);
}

void ntot::populateGrpVect()
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
        
        // New group
        //std::cout << "Group added: " << std::get<0>(m_grpVect.at(i)) << std::get<1>(m_grpVect.at(i)) << std::get<2>(m_grpVect.at(i)) << std::endl;
    }
}

void ntot::digest()
{
    digestSmall();
    
}

void ntot::digestGroup(const Group& group)
{
    
}

void ntot::digestSmall()
{
    std::string str = std::to_string(m_ungrouped);
    int val = std::stoi(str);
    char ch0, ch1;
    int i0, i1;
    bool isTeenVal = false;
    
    switch(m_numUngrouped)
    {
        case 0:
            str = m_input;
            val = std::stoi(str);
            ch0 = str.at(0);
            i0 = std::atoi(&ch0);
                            
            if (i0 != 0)
            {
                m_strVect.push_back( dictmap.at(static_cast<Dictionary>( i0 )) );
                m_strVect.push_back( dictmap.at( Dictionary::Hundred ));
            }
            
            val = val % 100;
            str = std::to_string(val);
            ch0 = str.at(0);
            i0 = std::atoi(&ch0);

            if (i0 > 1)
                m_strVect.push_back( dictmap.at(static_cast<Dictionary>( i0 + 18 )) );
            isTeenVal = (i0 == 1) ? true : false;
            
            val = val % 10;
            str = std::to_string(val);
            ch0 = str.at(0);
            i0 = std::atoi(&ch0);
            
            if (i0 != 0 && isTeenVal)
            {
                m_strVect.push_back( dictmap.at(static_cast<Dictionary>( i0 + 10 )) );
                
                val = val % 10;
                str = std::to_string(val);
                ch0 = str.at(0);
                i0 = std::atoi(&ch0);
            }
            
            if (i0 != 0 && i0 != 1)
                m_strVect.push_back( dictmap.at(static_cast<Dictionary>( i0 )) );

            break;
            
        case 1:
            ch0 = str.at(0);
            m_strVect.push_back( dictmap.at(static_cast<Dictionary>(std::stoi(&ch0))) );
            break;
            
        case 2:
            ch0 = str.at(0);
            ch1 = str.at(1);
            i0 = std::atoi(&ch0);
            i1 = std::atoi(&str.at(1));
            
            if (i0 != 1)
            {
                m_strVect.push_back( dictmap.at(static_cast<Dictionary>( i0 + 18 )) );
                
                if (i1 != 0)
                    m_strVect.push_back( dictmap.at(static_cast<Dictionary>( i1 )) );
            }
            else
                m_strVect.push_back( dictmap.at(static_cast<Dictionary>( i1 + 10 )) );
            break;
            
        default:
            break;
    }
    
    if ( m_numGroups > 1 )
        m_strVect.push_back( dictmap.at(static_cast<Dictionary>( m_numGroups + 28 )) );
    
    // Move cursor
    m_npos = static_cast<unsigned>(m_numUngrouped);
}
