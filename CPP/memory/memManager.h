#ifndef MEMMANAGER_T_CLASS_H
#define MEMMANAGER_T_CLASS_H
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class MemManager_t
{
    public:
        virtual ~MemManager_t(){} // DTOR (object of type memManager_t can 't be constructed)
        
        MemManager_t(){
            m_current_position = 0;
            m_actual_page_size = 0;
        } // default CTOR
        
        size_t getCurrentPosition()const {return m_current_position;} //(get current position in memory)
        void setCurrentPosition(const size_t position)
        {
            if(position <= getActualPagelSize())
            {
                m_current_position = position;
            }
            else
            {
                throw string("not good position");
            }

        } //(set current position in memory)

        size_t getActualPagelSize()const {return m_actual_page_size;} //(get actual size of the memory)
        
        void setActualPageSize(size_t size)
        {
            if((m_current_position+size) > m_actual_page_size)
            {
                // m_actual_page_size = m_current_position + size;
                m_actual_page_size = size;

            }  
        }
        
        
        bool isMemEmpty()const {/*return m_mem_status;*/return m_actual_page_size==0; } //(memory empty?)

        virtual size_t write(const void* buffer, size_t size)=0; /*{return 0;}*/ //(write data into memory - if position is not given)
        virtual size_t write(const void* buffer, size_t size, size_t position)=0; /*{return 0;}*/ //(write data into memory - from position given by user)
        
        virtual size_t read(void* buffer, size_t size)=0; /*{return 0;}*/ //(read data from memory-if position is not given)
        virtual size_t read(void* buffer, size_t size, size_t position)=0; /*{return 0;}*/ //(read data from memory - from position given by user)


    protected:
       
        
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