#include "memPool.h"
#include "memPage.h"

size_t MemPool_t::write(const void* buffer, size_t mysize)
{        
    size_t writtenTotal=0;
    if(buffer == 0 || mysize == 0 )
    {   
        return 0;
    }
    size_t writeSize=0;
    cout<<"my size:"<<mysize<<endl;
   // cout<<" pool.back()->getCapacity(): "<< pool.push_back()->getCapacity() <<endl;
    size_t s, p;
    int i=0;
    while(mysize>0)
    {
        // i++;
        // if (i>10) return writtenTotal;

        if(pool.back()->getActualPagelSize()==pool.back()->getCapacity())//if need to open new page 
        {
            MemPage_t* page = new MemPage_t;
            pool.push_back(page);
        }

        s = pool.back()->getCapacity()-pool.back()->getActualPagelSize();
        s = min(s, mysize);
        p = pool.back()->getActualPagelSize();
        
        writeSize = pool.back()->write(buffer, s/*, p*/); //position from ActualPagelSize
        buffer+=writeSize;
        mysize-=writeSize;
        writtenTotal+=writeSize;
    }  
    return writtenTotal;
}

size_t MemPool_t::write(const void* buffer, size_t mysize, size_t position)
{
    size_t writtenTotal=0;
    if(buffer == 0 || mysize == 0 )
    {   
        return 0;
    }
    size_t writeSize=0;
    cout<<"my size:"<<mysize<<endl;
   // cout<<" pool.back()->getCapacity(): "<< pool.push_back()->getCapacity() <<endl;
    size_t s, p;
    int i=0;
    while(mysize>0)
    {
        // i++;
        // if (i>10) return writtenTotal;

        if(pool.back()->getActualPagelSize()==pool.back()->getCapacity())//if need to open new page 
        {
            MemPage_t* page = new MemPage_t;
            pool.push_back(page);
        }

        s = pool.back()->getCapacity()-pool.back()->getActualPagelSize();
        s = min(s, mysize);
        p = pool.back()->getActualPagelSize();
        
        writeSize = pool.back()->write(buffer, s, p); //position from ActualPagelSize
        buffer+=writeSize;
        mysize-=writeSize;
        writtenTotal+=writeSize;
    }  
    return writtenTotal;
}

size_t MemPool_t::read( void* buffer, size_t mysize)
{
    size_t readenTotal=0;

    size_t readSize=0;
    size_t s, p;
    int i=0;
    while(mysize>0)
    {
        // i++;
        // if (i>10) return writtenTotal;

        if(pool.back()->getActualPagelSize()==pool.back()->getCapacity())//if need to open new page 
        {
            MemPage_t* page = new MemPage_t;
            pool.push_back(page);
        }

        s = pool.back()->getCapacity()-pool.back()->getActualPagelSize();
        s = min(s, mysize);
        p = pool.back()->getActualPagelSize();
        
        readSize = pool.back()->read(buffer, s/*, p*/); //position from ActualPagelSize
        buffer+=readSize;
        mysize-=readSize;
        readenTotal+=readSize;
    }  
    return readenTotal;
}

size_t MemPool_t::read( void* buffer, size_t mysize, size_t position)
{
    size_t readenTotal=0;

    size_t readSize=0;
    size_t s, p;
    int i=0;
    while(mysize>0)
    {
        // i++;
        // if (i>10) return writtenTotal;

        if(pool.back()->getActualPagelSize()==pool.back()->getCapacity())//if need to open new page 
        {
            MemPage_t* page = new MemPage_t;
            pool.push_back(page);
        }

        s = pool.back()->getCapacity()-pool.back()->getActualPagelSize();
        s = min(s, mysize);
        p = pool.back()->getActualPagelSize();
        
        readSize = pool.back()->read(buffer, s/*, p*/); //position from ActualPagelSize
        buffer+=readSize;
        mysize-=readSize;
        readenTotal+=readSize;
    }  
    return readenTotal;   
}