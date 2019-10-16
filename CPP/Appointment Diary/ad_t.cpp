#include "ad_t.h"

using namespace std;
/*
ad_t::ad_t(const ad_t& ad)//copy CTOR
{
    iter_t it;
    it=ad.meetMap.begin();
    for(it ; it!=ad.meetMap.begin() ; it++)
    {
        insertAppointmentToAD(it->second);
    }
}

ad_t& ad_t::operator=(const ad_t& ad)//operator =
{
    if(this!=&ad)
    {
        cleanAD();
        iter_t it;
        it=ad.meetMap.begin();
        for(it ; it!=ad.meetMap.begin() ; it++)
        {
            insertAppointmentToAD(it->second);
        }
    }
    return *this;
}
*/
bool ad_t::insertAppointmentToAD( meeting_t* meet)// insert appointment into AD
{
    
    if(meet == 0)
    {
        return false;
    }

    iter_t it;
    it = meetMap.begin(); //return it to the first element in the container
    meeting_t* currentMeeting;
    meeting_t* nextMeeting;

    //if container empty
    if(it == meetMap.end())
    {   
        float indexMeet = meet->getStartTime();
        meetMap[indexMeet] = meet;
        return true;
    }
    //before the first
    currentMeeting = it->second; //give the value 
    
    if(meet->getEndTime() < currentMeeting->getStartTime())
    {
        float indexMeet = meet->getStartTime();
        meetMap[indexMeet] = meet;
        return true;
    }

    //before the end
    it = meetMap.end();
    it--;
    currentMeeting = it->second; //give the value 

    if(meet->getStartTime() > currentMeeting->getEndTime())
    {
        float indexMeet = meet->getStartTime();
        meetMap[indexMeet] = meet;
        return true;
    }
    //between
    it = meetMap.begin(); //start
    currentMeeting = it->second; 
    it++;
    nextMeeting = it->second;
    
    while (it!=meetMap.end())
    { 
        if(meet->getStartTime() > currentMeeting->getEndTime() && meet->getEndTime() < nextMeeting->getStartTime())
        {
            float indexMeet = meet->getStartTime();
            meetMap[indexMeet] = meet;
            return true;
        }
        else
        {
            currentMeeting = it->second;
            it++;
            nextMeeting = it->second;
        }
    }

    return false;
}

meeting_t* ad_t::removeAppointmentFromAD(float startTime)// remove appointment from AD (return poiter to remeved meeting)
{
    iter_t it;
    it = meetMap.find(startTime);
    if (it == meetMap.end())
    {
        return 0; //NOT found
    }
    else
    {
        meeting_t* removed = it->second;
        meetMap.erase(it);

        return removed;
    }
    
}

meeting_t* ad_t::findAppointmentInAD(float startTime)
{
    iter_t it;
    it = meetMap.find(startTime);
    if (it == meetMap.end())
    {
        return 0; //NOT found
    }
    else
    {
        return it->second;
    }
}
//clean AD
void ad_t::cleanAD()
{
    iter_t it;
    while (!meetMap.empty())
    {
        it=meetMap.begin();
        delete it->second;
        meetMap.erase(it);
    }
}

void ad_t::printAD()
{
    iter_t it = meetMap.begin();;
    while (!meetMap.empty())
    {
        it->second->printMeeting();
        it++;
    }
    
}
