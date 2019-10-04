#ifndef STREET_T_CLASS_H
#define STREET_T_CLASS_H
#include <iostream> 
#include <vector>
#include "building_t.h"

using namespace std; 

template <class SID, class BID> class street_t
{
    public:
        ~street_t();
        street_t(); // CTOR
        street_t(const street_t& street); //copy CTOR
        street_t<SID, BID>& operator=(const street_t& street); //operator =

        const SID& getStreet()const;
        void setStreet(const SID& streetID);
        
        const building_t<BID>& getBuildingFromStreet(BID buildingID)const;
        void setBuildingToStreet(const building_t<BID>& buildingID);


    private:
        SID m_id;
        vector< building_t<BID> > buildings; 
};

template <class SID, class BID> 
street_t<SID, BID>::~street_t()
{
}

template <class SID, class BID> 
street_t<SID, BID>::street_t()
{
}

template <class SID, class BID> 
street_t<SID, BID>::street_t(const street_t<SID, BID>& street) //copy CTOR
{
    m_id = street.m_id;
    buildings = street.buildings;
}

template <class SID, class BID> 
street_t<SID, BID>& street_t<SID, BID>::operator=(const street_t<SID, BID>& street) //operator =
{
    m_id = street.m_id;
    buildings = street.buildings;
    return *this;
}

template <class SID, class BID> 
void street_t<SID, BID>::setStreet(const SID& streetID) //
{
    m_id = streetID;
}

template <class SID, class BID> 
const SID& street_t<SID, BID>::getStreet()const
{
    return m_id;
}

template <class SID, class BID> 
const building_t<BID>& street_t<SID, BID>::getBuildingFromStreet(BID buildingID)const
{
    int i;
    for ( i = 0; i < buildings.size() ; i++)
    {
        if(buildings[i].getBuilding() == buildingID)
        {
            return buildings[i];
        }
    }
    throw string("id building not exist!");
    
}

template <class SID, class BID> 
void street_t<SID, BID>::setBuildingToStreet(const building_t<BID>& buildingID)
{
    buildings.push_back(buildingID);
}
 

#endif

