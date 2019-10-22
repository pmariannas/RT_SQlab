#include "ad_t.h"

using namespace std;
/*
ad_t::ad_t(const ad_t& ad)//copy CTOR
{
    
}

ad_t& ad_t::operator=(const ad_t& ad)//operator =
{
    
}
*/

bool ad_t::insertAppointmentToAD(const meeting_t* meet)// insert appointment into AD
{
    bool status = false;
    if(meet == 0)
    {
        return status;
    }

    iter_t it;
    it = meetMap.begin(); //return it to the first element in the container
    meeting_t* currentMeeting;
    meeting_t* nextMeeting;

    //if container empty
    if(it == meetMap.end())
    {   
        meetMap[meet->getStartTime()] = (meeting_t*)meet;
        //status = true;
        return true;
    }
    //before the first
    currentMeeting = it->second; //give the value 
    
    if(meet->getEndTime() <= currentMeeting->getStartTime())
    {
        meetMap[meet->getStartTime()] = (meeting_t*)meet;
        //status = true;
        return true;
    }

    //after the end
    it = meetMap.end();
    it--;
    currentMeeting = it->second; //give the value 

    if(meet->getStartTime() >= currentMeeting->getEndTime())
    {
        meetMap[meet->getStartTime()] = (meeting_t*)meet;
        //status = true;
        return true;
    }
    //between
    it = meetMap.begin(); //start
    currentMeeting = it->second; 
    it++;
    nextMeeting = it->second;
    
    while (it!=meetMap.end())
    { 
        if(meet->getStartTime() >= currentMeeting->getEndTime())
        {
            if(meet->getEndTime() <= nextMeeting->getStartTime())
            {
                meetMap[meet->getStartTime()] = (meeting_t*)meet;
                //status = true;
                return true;
            }
        }

        currentMeeting = it->second;
        it++;
        nextMeeting = it->second;
    }

    // if(status == false)
    // {
    //     delete meet;
    // }
    
    return false;
}

meeting_t* ad_t::removeAppointmentFromAD(const float& timeToRemove)// remove appointment from AD (return poiter to remeved meeting)
{
    iter_t it;
    meeting_t* meet = findAppointmentInAD(timeToRemove);
    if(meet == 0)
    {
        return 0;
    }
    it = meetMap.find(meet->getStartTime());
    meetMap.erase(it);
    return meet;
}

meeting_t* ad_t::findAppointmentInAD(const float& timeToFind)const
{
    citer_t it;
    it = meetMap.begin();
    while (it!=meetMap.end())
    {
        if(timeToFind >= it->second->getStartTime() && timeToFind <= it->second->getEndTime())
        {
            return it->second;
        }
        it++;
    }
    return 0;//not found
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

void ad_t::printAD()const
{
    citer_t it = meetMap.begin();;
    while (it!=meetMap.end())
    {
        it->second->printMeeting();
        it++;
    }
}

/* void ad_t::saveToFile()
 {
    
 }*/