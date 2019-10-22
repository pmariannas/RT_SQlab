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
        
        bool insertAppointmentToAD(const meeting_t* meet); // insert appointment into AD
        meeting_t* removeAppointmentFromAD(const float& timeToRemove); // remove appointment from AD (return poiter to remeved meeting)
        meeting_t* findAppointmentInAD(const float& timeToFind)const; // find Appointment In AD by hour
        void cleanAD(); //clean AD
        void printAD()const; //print all meetings in AD

        //void saveToFile();
      
    private:
        map<float, meeting_t* > meetMap;
        typedef typename map<float, meeting_t* >::iterator iter_t;
        typedef typename map<float, meeting_t* >::const_iterator citer_t;

        ad_t(const ad_t& ad){}; //copy CTOR
        ad_t& operator=(const ad_t& ad){}; //operator =        
};

#endif