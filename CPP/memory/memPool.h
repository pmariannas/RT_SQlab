#ifndef MEMPOOL_T_CLASS_H
#define MEMPOOL_T_CLASS_H


#include "memManager.h"
#include "memPage.h"
#include <vector>
using namespace std;

class MemPool_t : public MemManager_t
{
    public:
        ~MemPool_t(); //DTOR        
        MemPool_t(); //default CTOR
        
        virtual size_t write(const void* buffer, size_t size);
        virtual size_t write(const void* buffer, size_t size, size_t position);
    
        virtual size_t read(const void* buffer, size_t size);
        virtual size_t read(const void* buffer, size_t size, size_t position);

    private:
        MemPool_t(const MemPool_t& mp);
        MemPool_t& operator=(const MemPool_t& mp);

        vector<MemPage_t*> pool;
        
    
};

MemPool_t::~MemPool_t()
{
    for(int i = 0 ; i < pool.size() ; i++)
    {
        delete pool[i];
    }
}
MemPool_t::MemPool_t()
{
    MemPage_t* page = new MemPage_t;
    pool.insert(pool.end(), page);
}




#endif