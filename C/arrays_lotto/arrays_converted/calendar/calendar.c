#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"

AD_t* createAD(int capacity)
{
	AD_t* ad;

    ad = (AD_t*)malloc(sizeof(AD_t));
    if (ad == NULL)                     
        {
            return NULL;
        }

    ad->meetings= (MT_t**)malloc(capacity * sizeof(MT_t*));

    if(ad->meetings == NULL)                     
    {
    	free(ad);
        return NULL;
    }

    ad->index =0;
    ad->capacity = capacity;
    
    printf("Calendar created!!!\n");
    return ad;

}

MT_t* createMT() /**/
{
    MT_t* pMeeting = NULL;
    int room = 0;
    float startT=0, endT=0;

    pMeeting = (MT_t*)malloc(sizeof(MT_t));

    if(pMeeting == NULL)
    {
        return NULL;
    }

    while (1)
    {
        printf("Enter meeting details\n");
        printf("start time:\n");
        scanf("%f", &(startT));
        printf("end time:\n");
        scanf("%f", &(endT));
        printf("room number:\n");
        scanf("%d", &(room));

        /*check if startT&&endT&&room is legal between 0-24 and room more than 0 */
        if(startT > 0 && startT < 24 && endT > 0 && endT < 24 && startT < endT && room > 0)
		{
			break;
		}
    }

    pMeeting->startT = startT;
    pMeeting->endT = endT;
    pMeeting->room = room;

    printf("Meeting created!!!\n");
    return pMeeting;
}

int insertMeeting(AD_t* ad, MT_t* pMeeting)
{
    MT_t** temp;
    MT_t* checkExistStartTime;
    int valueCheckOverlap;

    if (ad == NULL || pMeeting ==NULL)
    {
        return -1;
    }
    
    if(ad->index == 0) /*no meetings in calendar*/
    {
        ad->meetings[ad->index] = pMeeting;
        ad->index++;
        return 0;
    }
    else if (ad->index == ad->capacity) /*realloc*/
    {
        /*check if exist start time*/
        checkExistStartTime = findMeeting(ad, pMeeting->startT);
        
        if (checkExistStartTime!=NULL)
        {
            printf("cannot create this meeting\n");
            return -1;
        }
        else
        {
            valueCheckOverlap = checkOverlap(ad, pMeeting);
            if(valueCheckOverlap == 0)/*no overlap &&index==capacity*/
            {
                temp = ad->meetings;
                temp = realloc(ad->meetings, sizeof(MT_t)*((ad->capacity)*2));
                if(ad->meetings != NULL)
                {
                    ad->meetings = temp;
                    ad->capacity *=2;
                }
                else 
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
            
        }
        
    }
    valueCheckOverlap = checkOverlap(ad, pMeeting);
    if (valueCheckOverlap==0) /*no overlap*/
    {
        ad->meetings[ad->index] = pMeeting;
        ad->index++;  
        return 0;
    }
    else
    {
        return -1;
    }   
    }
    

int deleteMeeting(AD_t* ad)
{
    return 0;

}

int checkOverlap(AD_t* ad, MT_t* meetingToCheck)
{
     int i;

    for ( i = 0 ; i < ad->index ; i++)
    {
        if(meetingToCheck->startT <= ad->meetings[i]->startT && meetingToCheck->endT > ad->meetings[i]->endT)
        {   
            return -1; /*overlap*/
        }
    }
    return 0;/*no overlap*/
}

MT_t* findMeeting(AD_t* ad, float startFind)
{
    int i;
    /*float startFind = 0;
    
    printf("Enter start time you want to find:\n");
    scanf("%f", &startFind);*/
    

    for ( i = 0 ; i < ad->index ; i++)
    {
        if(startFind == ad->meetings[i]->startT)
        {   
            return ad->meetings[i];
        }
    }
}

void printAD(AD_t* ad) /*print calendar*/
{
    int i = 0;
    if (ad == NULL)
    {
        printf("Calendar not exist\n");
        return;
    }
            printf("%d   ", ad->index);

    for( i = 0 ; i< ad->index ; i++)
    {
        printf("start time: %.1f   |", ad->meetings[i]->startT);
        printf("end time: %.1f   |", ad->meetings[i]->endT);
        /*printf("room: %d"), ad->meetings[i]->room;*/
        printf("\n");
    }

}

void destroyAD(AD_t* ad)
{
    int i=0;

	if(ad == NULL)
    {
        return;
    }
	
    for (i=0 ; i< ad->index ; i++)
    {
        free(ad->meetings[i]);
    } 
    free(ad->meetings);
    free(ad);

    printf("DESTROY!!!!!!!!!!!!!\n");
}
