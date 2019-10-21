#ifndef MEETING_T_CLASS_H
#define MEETING_T_CLASS_H

#include <iostream>
#include <string>

using namespace std;

class meeting_t
{
    public:
        virtual ~meeting_t(){}; //DTOR
        //CTOR
        meeting_t(const float& startT, const float& endT,const string& sub) 
        {
            
            int e = -1;
            if(startT > 0 && startT <= 24 && endT > 0 && endT <= 24 && startT < endT)
            {
                m_startTime = startT;
                m_endTime = endT;
                m_subject = sub;
            }
            else
            {
                throw e;
            }
            
        }
        const float& getStartTime()const{ return this->m_startTime; }
        const float& getEndTime()const{ return this->m_endTime; }
        const string& getSubject()const{ return this->m_subject; }

        void printMeeting()
        { cout<<"The meeting: " <<
          getStartTime() << "-" << getEndTime() << " subject: " << getSubject() <<endl;}

        
      
    private:
        float m_startTime;
        float m_endTime;
        string m_subject;

        meeting_t(const meeting_t& meet){}; //copy CTOR
        meeting_t& operator=(const meeting_t& meet){}; //operator =

       
};


#endif