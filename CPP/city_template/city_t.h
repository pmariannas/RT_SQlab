#ifndef CITY_T_CLASS_H
#define CITY_T_CLASS_H
#include <vector>
#include "building_t.h"
#include "street_t.h"

using namespace std; 

template <class CID, class SID, class BID> class city_t
{
    public:
        ~city_t();
        city_t(); //CTOR
        city_t(const city_t& city); //copy CTOR
        city_t<CID, SID, BID>& operator=(const city_t& city); //operator =

        const CID& getCity()const;
        void setCity(const CID& cityID);
        
        const street_t<SID, BID>& getStreetFromCity(SID streetID)const;
        void setStreetToCity(const street_t<SID, BID>& streetID);
        
        

    private:
        CID m_id;
        vector< street_t<SID, BID> > streets; 

};

template <class CID, class SID, class BID> 
city_t<CID, SID, BID>::~city_t() //DTOR
{
}

template <class CID, class SID, class BID> 
city_t<CID, SID, BID>::city_t() //CTOR
{
}

template <class CID, class SID, class BID> 
city_t<CID, SID, BID>::city_t(const city_t& city) //copy CTOR
{
    m_id = city.m_id;
    streets = city.streets;
}

template <class CID, class SID, class BID> 
city_t<CID, SID, BID>&  city_t<CID, SID, BID>::operator=(const city_t& city) //operator =
{
    m_id = city.m_id;
    streets = city.streets;
    return *this;
}

template <class CID, class SID, class BID> 
void city_t<CID, SID, BID>::setCity(const CID& id) 
{
    m_id = id;
}

template <class CID, class SID, class BID> 
const CID& city_t<CID, SID, BID>::getCity()const
{
    return m_id;
}

template <class CID, class SID, class BID> 
const street_t<SID, BID>& city_t<CID, SID, BID>::getStreetFromCity(SID streetID)const
{
    int i;
    for ( i = 0; i < streets.size() ; i++)
    {
        if(streets[i].getStreet() == streetID)
        {
            return streets[i];
        }
    }
    throw string("id street not exist!");
}

template <class CID, class SID, class BID> 
void city_t<CID, SID, BID>::setStreetToCity(const street_t<SID, BID>& streetID)
{
    streets.push_back(streetID);
}
 
#endif