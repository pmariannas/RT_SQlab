#ifndef MEMPAGE_T_CLASS_H
#define MEMPAGE_T_CLASS_H

using namespace std;

#include "memManager.h"

class MemPage_t : MemManager_t
{

    public:
        virtual ~MemPage_t(){ delete[] m_stream;}
        MemPage_t();
        MemPage_t(const size_t size); //(object constructed from some default size

        size_t getCapacity()const{return m_capacity;} 
        size_t getDefaultCapacity()const{return m_default_capacity;} 
        size_t setDefaultCapacity(size_t capacity){m_default_capacity = capacity;} //(set current position in memory buffer)
        bool isFull()const{return m_default_capacity==m_capacity;}
        
        virtual size_t write(const void* buffer, size_t size){return 0;} 
        virtual size_t write(const void* buffer, size_t size, size_t position){return 0;} 
        
        virtual size_t read(const void* buffer, size_t size){return 0;}
        virtual size_t read(const void* buffer, size_t size, size_t position){return 0;} 

    
    private:
        MemPage_t(const MemPage_t& mp){} //(copy of object of type memPage_t is forbidden)
        MemPage_t& operator=(const MemPage_t& mp){} //(copy of object of type memPage_t is forbidden)

        char* m_stream;
        size_t m_capacity;
        size_t m_default_capacity;


    
};

MemPage_t::MemPage_t()
{
}


#endif