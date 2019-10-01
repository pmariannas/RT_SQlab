#include "memPage.h"
#include <string>

size_t MemPage_t:: m_default_capacity = 6;

MemPage_t::MemPage_t()
{
    m_current_position=0;
    m_capacity = m_default_capacity ;
    m_stream = new char[m_capacity];
}
MemPage_t::MemPage_t(const size_t size)
{
    m_current_position=0;
    m_capacity = size;
    m_stream = new char[size];
}

size_t MemPage_t::write(const void* buffer, size_t size)
{
    
} 
size_t MemPage_t::write(const void* buffer, size_t size, size_t position)
{

} 

size_t MemPage_t::read(const void* buffer, size_t size)
{
    if(buffer !=0 )
    {
        if(size + m_current_position >  m_capacity) //read no more than capacity of page
        {
            memcpy(buffer, (void*)(&(m_stream[m_current_position])), m_capacity - m_current_position);//
            m_current_position += size;
        }
        else
        {
            memcpy(buffer, (void*)(&(m_stream[m_current_position])),size);
            m_current_position += size;
        }
        
    }
    return (size_t)buffer;
}

size_t MemPage_t::read(const void* buffer, size_t size, size_t position)
{
    if(buffer !=0 && position < m_actual_page_size) //check if given position is ok
    {
        if(size + position >  m_capacity) //check is what we want to read no more than capacity of page
            {
                memcpy(buffer, (void*)(&(m_stream[m_current_position])), m_capacity - position);//
                m_current_position += size;
            }
        else
            {
                memcpy(buffer, (void*)(&(m_stream[m_current_position])),size);
                m_current_position += size;
            }
    
    }
    return (size_t)buffer;
        
} 
