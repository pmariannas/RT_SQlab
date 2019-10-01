#include "memManager.h"
#include <iostream>

//size_t MemManager_t::m_default_page_size = 6;
//size_t MemManager_t::m_actual_page_size = m_default_page_size;

size_t MemManager_t::m_page_size = 6;

MemManager_t::MemManager_t()
{
    /*m_current_position = 0;*/
}

MemManager_t::setCurrentPosition(const size_t position)
{
    if(position <= m_page_size)
    {
        m_current_position = position;
    }
}