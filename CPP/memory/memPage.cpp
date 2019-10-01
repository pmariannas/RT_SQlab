#include "memPage.h"
#include <string>
#include <iostream>

size_t MemPage_t:: m_default_capacity = 6;
/*
MemPage_t::MemPage_t()
{
    m_current_position=0;
    m_capacity = m_default_capacity ;
    m_stream = new char[m_capacity];
}
*/
/*
MemPage_t::MemPage_t(const size_t size)
{
    m_current_position=0;
    m_capacity = size;
    m_stream = new char[size];
}
*/
size_t MemPage_t::write(void* buffer, size_t size)
{
    
} 
size_t MemPage_t::write(void* buffer, size_t size, size_t position)
{

} 

size_t MemPage_t::read(void* buffer, size_t size)
{
  
    if(size + getCurrentPosition() >  m_capacity) //read no more than capacity of page
    {
        size = m_capacity - getCurrentPosition();
    }
    
    memcpy(buffer, m_stream+getCurrentPosition() ,size);
    //m_current_position += size;

    return size;
}

size_t MemPage_t::read(void* buffer, size_t size, size_t position)
{
    if(size + position >  m_capacity) //read no more than capacity of page
    {
        size = m_capacity - position;
    }
    
    memcpy(buffer, m_stream+position ,size);
    //m_current_position += size;

    return size;
        
} 
