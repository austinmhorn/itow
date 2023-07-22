#include "ntot.hpp"

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

void ntot::print()
{
    std::cout << std::endl << "*****************************************************" << std::endl;
    for (auto s : m_strVect)
        std::cout << s << " ";
    std::cout << std::endl << "*****************************************************" << std::endl << std::endl;
}

void ntot::printStats()
{
    std::cout << "input:        " << m_input << std::endl;
    std::cout << "size:         " << m_size << std::endl;
    std::cout << "numGroups:    " << m_numGroups << std::endl;
    std::cout << "numUngrouped: " << m_numUngrouped << std::endl;
    std::cout << "ungrouped:    " << m_ungrouped << std::endl;
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
    char ch0, ch1, ch2;
    int i0, i1, i2;
    
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
            
            //ch1 = str.at(1);
            //i1 = std::atoi(&ch1);
            
            val = val % 10;
            str = std::to_string(val);
            ch0 = str.at(0);
            i0 = std::atoi(&ch0);
            
            
            
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
