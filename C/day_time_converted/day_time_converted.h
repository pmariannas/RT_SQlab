#ifndef DAY_TIME_CONVERTED_H
#define DAY_TIME_CONVERTED_H

typedef struct 
{
    int cSec;         /* seconds */
    int cMin;         /* minutes */
    int cHour;        /* hours */    
}cTime_t;

typedef struct 
{
    int cDay;        /* day of the month */
    int cMon;         /* month */
    int cYear;        /* year */
    cTime_t* currTime;

}cDate_t;

cDate_t* createDate(int day, int month, int year);
int checkLeapYear(int year);
cTime_t* setTime();
int checkDate(int d,int m,int y);
cDate_t* addTimeToTime(cDate_t* curTime, cTime_t* newTime);
cDate_t* setNewDate(cDate_t* date);
int dayOfYear(cDate_t* date);
char* monthName(int month);

#endif
