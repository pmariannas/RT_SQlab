#ifndef MEMMANAGER_T_CLASS_H
#define MEMMANAGER_T_CLASS_H
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class MemManager_t
{
    public:
        MemManager_t(){
            m_current_position = 0;
            m_actual_page_size = 0;
        } // default CTOR
        
        size_t getCurrentPosition()const {return m_current_position;} //(get current position in memory)
        bool setCurrentPosition(const size_t position)
        {
            if(position <= m_actual_page_size)
            {
                m_current_position = position;
                return true;
            }
            return false;
        } //(set current position in memory)

        size_t getActualPagelSize()const {return m_actual_page_size;} //(get actual size of the memory)
        
        bool isMemEmpty()const {/*return m_mem_status;*/return m_actual_page_size==0; } //(memory empty?)

        virtual size_t write(const void* buffer, size_t size){} //(write data into memory - if position is not given)
        virtual size_t write(const void* buffer, size_t size, size_t position){} //(write data into memory - from position given by user)
        
        virtual size_t read(const void* buffer, size_t size){}//(read data from memory-if position is not given)
        virtual size_t read(const void* buffer, size_t size, size_t position){} //(read data from memory - from position given by user)


    protected:
        virtual ~MemManager_t(); // DTOR (object of type memManager_t can 't be constructed)
        
    private:
        MemManager_t(const MemManager_t& mp){} //copy CTOR
        MemManager_t& operator=(const MemManager_t& mp){} // operator =
        
        size_t m_current_position;
        size_t m_actual_page_size;
    
};

/*
MemManager_t::~MemManager_t()
{
}
*/

#endif