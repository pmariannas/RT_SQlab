#ifndef calendar_h
#define calendar_h

typedef struct 
    {
        float startT;
        float endT;
        int room;
        
    }MT_t; /*Meeting*/

typedef struct 
{
    MT_t** meetings;
    int capacity;
    int index;
    
}AD_t; /*calendar*/


AD_t* createAD(int capacity); /*create calendar*/
MT_t* createMT(); /*create meeting*/
int insertMeeting(AD_t* ad, MT_t* pMeeting); /*insert meeting in to calendar*/
int deleteMeeting(AD_t* ad);
MT_t* findMeeting(AD_t* ad,float startFind);
void printAD(AD_t* ad); /*print calendar*/
void destroyAD(AD_t* ad); /*destroy pointers*/



#endif
