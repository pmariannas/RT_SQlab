#ifndef MEMMANAGER_T_CLASS_H
#define MEMMANAGER_T_CLASS_H

using namespace std;
#include <stdlib.h>

class MemManager_t
{
    public:
        MemManager_t(); // default CTOR
        
        size_t getCurrentPosition()const {return m_current_position;} //(get current position in memory)
        size_t setCurrentPosition(const size_t position); //(set current position in memory)

        size_t getActualPagelSize()const {return m_actual_page_size;} //(get actual size of the memory)
        
        bool isMemEmpty()const {/*return m_mem_status;*/return m_actual_page_size==0; } //(memory empty?)

    protected:
        ~MemManager_t(); // DTOR (object of type memManager_t can 't be constructed)
        
        virtual size_t write(const void* buffer, size_t size){return 0;} //(write data into memory - if position is not given)
        virtual size_t write(const void* buffer, size_t size, size_t position){return 0;} //(write data into memory - from position given by user)
        
        virtual size_t read(const void* buffer, size_t size){return 0;}//(read data from memory-if position is not given)
        virtual size_t read(const void* buffer, size_t size, size_t position){return 0;} //(read data from memory - from position given by user)

    private:
        size_t m_current_position;
        size_t m_actual_page_size;
        //size_t m_default_page_size;
        //size_t m_mem_status;
    
};

/*
MemManager_t::~MemManager_t()
{
}
*/

#endif