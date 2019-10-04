#ifndef BUILDING_T_CLASS_H
#define BUILDING_T_CLASS_H
#include <iostream> 

using namespace std; 

template <class BID> class building_t
{
    public:
        ~building_t();
        building_t(); //CTOR
        building_t(const building_t& build); //copy CTOR 
        building_t& operator=(const building_t& build); //operator =

        const BID& getBuilding()const;
        void setBuilding(const BID& id);

    private:
        BID m_id;

};

template <class BID> 
building_t<BID>::~building_t()
{
}

template <class BID> 
building_t<BID>::building_t()
{
}

template <class BID> 
building_t<BID>::building_t(const building_t& build)
{
    m_id = build.m_id;
}

template <class BID> 
building_t<BID>& building_t<BID>::operator=(const building_t& build)
{
    m_id = build.m_id;
    return *this;
}

template <class BID> 
const BID& building_t<BID>::getBuilding()const
{
    return m_id;
}

template <class BID> 
void building_t<BID>::setBuilding(const BID& id)
{
    m_id = id;
}

 



#endif

