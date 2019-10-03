#ifndef MEMPOOL_T_CLASS_H
#define MEMPOOL_T_CLASS_H

#include "memManager.h"
#include "memPage.h"
#include <vector>

using namespace std;

class MemPool_t : public MemManager_t
{
    public:
        virtual ~MemPool_t()
        {
            for(int i = 0 ; i < pool.size() ; i++)
            {
                delete pool[i];
            }
        }    //DTOR        

        MemPool_t()
        {
            MemPage_t* page = new MemPage_t;
            //pageCapacity = getPageCapacity();
            pool.push_back(page);
            //pool.insert(pool.end(), page);
        } //default CTOR

        

        //size_t getPageCapacity()const{return MemPage_t::getCapacity();}
        //size_t getDefaultCapacity(){return MemPage_t::getDefaultCapacity();}
        //size_t setDefaultCapacity(size_t capacity){return MemPage_t::setDefaultCapacity(capacity);}
        
        virtual size_t write(const void* buffer, size_t size);
        virtual size_t write(const void* buffer, size_t size, size_t position);
    
        virtual size_t read(void* buffer, size_t size);
        virtual size_t read(void* buffer, size_t size, size_t position);

    private:
        MemPool_t(const MemPool_t& mp);
        MemPool_t& operator=(const MemPool_t& mp);
        //size_t pageCapacity;
        vector<MemPage_t*> pool;
        
    
};
/*
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

*/


#endif