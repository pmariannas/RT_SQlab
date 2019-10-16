#ifndef AD_T_CLASS_H
#define AD_T_CLASS_H

#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <typeinfo>
#include <algorithm>
#include <string>
#include <map>
#include "meeting_t.h"

using namespace std;

class ad_t
{
    public:
        virtual ~ad_t(){} //DTOR
        ad_t(){} //CTOR
        ad_t(const ad_t& ad){}; //copy CTOR
        ad_t& operator=(const ad_t& ad){}; //operator =
        
        bool insertAppointmentToAD(meeting_t* meet); // insert appointment into AD
        meeting_t* removeAppointmentFromAD(float startTime); // remove appointment from AD (return poiter to remeved meeting)
        meeting_t* findAppointmentInAD(float startTime); // fin dAppointment In AD by hour
        void cleanAD(); //clean AD

        void printAD();


      
    private:
        map<float, meeting_t* > meetMap;
        typedef typename map<float, meeting_t* >::iterator iter_t;
        typedef typename map<float, meeting_t* >::const_iterator citer_t;

        //meeting_t m_meet;
        
        
};

#endif