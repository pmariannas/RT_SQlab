#include <stdio.h>
#include <stdlib.h>
#include "day_time_converted.h"

int main()
{
    int d,m,y,i,h,min,sec;
	cDate_t* date;
    cTime_t* time;
	
	while(1)
	{
		printf("1: Create Day \n");
		printf("2: Print date \n");
		printf("3: Set New Time \n");
		printf("4: Addition of 2 times(current and new)\n");
		
		scanf("%d", &i);
		switch(i)
		{
			case 1:
                while (1)
                {
                    printf("PLEASE ENTER DATE \n");
                    printf("enter day:\n");
                    scanf("%d", &d);
                    printf("enter month:\n");
                    scanf("%d", &m);
                    printf("enter year:\n");
                    scanf("%d", &y);
                    if(checkDate(d,m,y)==0)
                    {
                        break;
                    }
                   
                    printf("DATE INCCORECT \n");
                }
                
                date = createDate(d,m,y);
                if (date==NULL)
                {
                    printf("error in creating date\n"); 
                    return 0;
                }
                else
                {
                    printf("DATE created.\n");
                }

				break;
				
			case 2:			
                printDate(date);
				break;
				
			case 3:
                if(date->currTime==NULL)
                {
                    printf("CREATE DATE BEFORE\n");
                }
                else
                {
                    setTime(date->currTime);
                }
                
				break;
            case 4:
                printf("enter time to add to current time: \n");
                time = malloc(sizeof(cTime_t*));
                printf("enter hour:\n");
                scanf("%d", &h);
                printf("enter min:\n");
                scanf("%d", &m);
                printf("enter sec:\n");
                scanf("%d", &sec);
                time->cHour = h;
                time->cMin = m;
                time->cSec =sec;
                addTimeToTime(date, time);
				break;				
		}
	}
	
	return 0;
}
