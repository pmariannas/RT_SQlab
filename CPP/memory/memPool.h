#ifndef MEMPOOL_T_CLASS_H
#define MEMPOOL_T_CLASS_H

using namespace std;

#include "memManager.h"
#include "memPage.h"
#include <vector>

class MemPool_t : MemManager_t
{
    public:
        ~MemPool_t(); //DTOR        
        MemPool_t(); //default CTOR
        
        virtual size_t write(const void* buffer, size_t size){return 0;} 
        virtual size_t write(const void* buffer, size_t size, size_t position){return 0;} 
        
        virtual size_t read(const void* buffer, size_t size){return 0;}
        virtual size_t read(const void* buffer, size_t size, size_t position){return 0;} 

    private:
        MemPool_t(const MemPool_t& mp);
        MemPool_t& operator=(const MemPool_t& mp);

        vector<MemPage_t*> pool;
        
    
};

MemPool_t::~MemPool_t()
{
}
MemPool_t::MemPool_t()
{
}




#endif