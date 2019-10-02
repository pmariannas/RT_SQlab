#ifndef MEMPAGE_T_CLASS_H
#define MEMPAGE_T_CLASS_H
#include "memManager.h"

using namespace std;


class MemPage_t : public MemManager_t
{

    public:
        virtual ~MemPage_t(){ delete[] m_stream; }
        
        MemPage_t()
        {
            m_capacity = m_default_capacity;
            m_stream = new char[m_default_capacity];
        }
        
        MemPage_t(const size_t size)
        {
            m_stream = new char[size];
            m_capacity = size;
        } //(object constructed from some default size

        size_t getCapacity()const{return m_capacity;} 

        size_t getDefaultCapacity()const{return m_default_capacity;} 
        size_t setDefaultCapacity(size_t capacity){m_default_capacity = capacity;} //(set current position in memory buffer)
        
        bool isFull()const
        {
            if(getActualPagelSize() == m_capacity)
            {
                return true;
            }
            return false;
        }
        
        virtual size_t write(const void* buffer, size_t size);
        virtual size_t write(const void* buffer, size_t size, size_t position);
        
        virtual size_t read(void* buffer, size_t size);
        virtual size_t read(void* buffer, size_t size, size_t position);

    
    private:
        MemPage_t(const MemPage_t& mp){} //(copy of object of type memPage_t is forbidden)
        MemPage_t& operator=(const MemPage_t& mp){} //(copy of object of type memPage_t is forbidden)

        char* m_stream;
        size_t m_capacity;
        static size_t m_default_capacity;


    
};

#endif