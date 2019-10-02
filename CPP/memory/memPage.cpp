#include "memPage.h"
#include <string>
#include <iostream>

size_t MemPage_t:: m_default_capacity = 6;
/*
MemPage_t::MemPage_t()
{
    m_capacity = m_default_capacity;
    m_stream = new char[m_default_capacity];
}
*/
/*
MemPage_t::MemPage_t(const size_t size)
{
    m_capacity = size;
    m_stream = new char[size];
}
*/
size_t MemPage_t::write(const void* buffer, size_t size)
{
    if(buffer == 0 || size == 0 )
    {   
        return 0;
    }
    
    if(size + getCurrentPosition() >  m_capacity) //write no more than capacity of page
    {
        size = m_capacity - getCurrentPosition();
    }
    
    memcpy((m_stream+getCurrentPosition()),buffer,size);
    setActualPageSize(size);
    setCurrentPosition(getCurrentPosition()+size);
    
    return size;
} 

size_t MemPage_t::write(const void* buffer, size_t size, size_t position)
{
    if(buffer == 0 || size == 0 )
    {   
        return 0;
    }
    
    if(size + position >  m_capacity) //read no more than capacity of page
    {
        size = m_capacity - position;
    }
    
    memcpy((m_stream+position),buffer,size);
    
    
    setActualPageSize(size);  
    setCurrentPosition(position+size);
   
    return size;
} 

size_t MemPage_t::read(void* buffer, size_t size)
{   
    if(buffer == 0 || size == 0 )
    {   
        return 0;
    }
    if(size + getCurrentPosition() >  m_capacity) //read no more than capacity of page
    {
        size = m_capacity - getCurrentPosition();
    }
    
    memcpy(buffer, m_stream+getCurrentPosition() ,size);
    
    return size;
}

size_t MemPage_t::read(void* buffer, size_t size, size_t position)
{
    if(buffer == 0 || size == 0 )
    {   
        return 0;
    }

    if(size + position >  m_capacity) //read no more than capacity of page
    {
        size = m_capacity - position;
    }
    
    memcpy(buffer, m_stream+position,size);

    return size;
        
} 
