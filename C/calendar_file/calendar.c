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

    return pMeeting;
}

int insertMeeting(AD_t* ad, MT_t* pMeeting)
{
    MT_t** temp;
    MT_t* checkExistStartTime;
    int valueCheckOverlap , placeToinsert;


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
        valueCheckOverlap = checkOverlap(ad, pMeeting);
        if(valueCheckOverlap != -1)/*no overlap &&index==capacity*/
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

    valueCheckOverlap = checkOverlap(ad, pMeeting);

    if (valueCheckOverlap!=-1) /*no overlap*/
    {
        /*insert in i place ---> need to write*/
        /*insertWithSort(ad,valueCheckOverlap,pMeeting);*/
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
    float startM = meetingToCheck->startT;
    float endM =meetingToCheck->endT;

    for ( i = 0 ; i < ad->index ; i++)
    {
        if(startM >= ad->meetings[i]->startT && endM <= ad->meetings[i]->endT)/*in*/
        {
            return -1; /*overlap*/
        }
        if(startM <= ad->meetings[i]->startT && endM >= ad->meetings[i]->endT ) /*out*/
        {   
            return -1; /*overlap*/
        }
        if(startM < ad->meetings[i]->startT && endM < ad->meetings[i]->endT && endM >ad->meetings[i]->startT )
        {
            return -1;
        }
        if(startM > ad->meetings[i]->startT && startM < ad->meetings[i]->endT && endM >ad->meetings[i]->startT)
        {
            return -1;
        }
    }
    return i;/*no overlap*/
}

AD_t* insertWithSort(AD_t* ad, int indexToInsert, MT_t* pMeeting)
{
    int i;
    
    return ad;

}

MT_t* findMeeting(AD_t* ad, float startFind)
{
    int i;

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
}


void loadFromFile(AD_t* da, char* fName)
{
    FILE* fp = fopen(fName,"r");
    float st, et;
    int room;
    MT_t* mPtr;

    if(fp!=NULL)
    {
        while (1) 
        {
           fscanf(fp, "%f%f%d", &st, &et, &room); 
           if(!feof(fp))
           {
               mPtr = createMT(st, et, room);
               if(mPtr==NULL)
               {
                   return;
               }
               insertMeeting(da, mPtr);
           }
           
        }
    printf("HELLLLO\n");
    fclose(fp);
    }
}

void saveInFile(AD_t* ad, char* fName)
{
    int i=0;
    FILE * fp = fopen(fName, "w");
    for(i=0 ; i < ad->index ; i++)
    {
        fprintf(fp,"%.1f %.1f %d\n", ad->meetings[i]->startT,ad->meetings[i]->endT,ad->meetings[i]->room );

    }
    fclose(fp);

}