#include <stdio.h>
#include <stdlib.h>
#include "day_time_converted.h"

int main()
{
    int d,m,y,i,h,min,sec;
    int doy; /*day of year*/
    char* leap[4];
    char* monName[12];
	cDate_t* date;
    cTime_t* time;
	
	while(1)
	{
		printf("1: Create Day \n");
		printf("2: Print date and time \n");
		printf("3: Set New Time \n");
		printf("4: Addition of 2 times(current and new)\n");
        printf("5: Set New Date \n");
        printf("6: functions to retrieve day, month, day of Year \n");
		
		scanf("%d", &i);
		switch(i)
		{
			case 1:
                if(date!=NULL)
                {
                    printf("enter - set new Date \n");

                }
                else
                {
                    while (1)
                    {
                        printf("CREATE - ENTER DATE \n");
                        printf("enter day:\n");
                        scanf("%d", &d);
                        printf("enter month:\n");
                        scanf("%d", &m);
                        printf("enter year:\n");
                        scanf("%d", &y);
                        if(checkDate(d,m,y)==0) /*function check if date correct */
                        {
                            break;
                        }
                        printf("DATE INCCORECT \n");
                    }
                    
                    date = createDate(d,m,y); /*call to create function*/
                    if (date==NULL)
                    {
                        printf("error in creating date\n"); 
                        return 0;
                    }
                    else
                    {
                        printf("DATE created.\n");
                    }
                }
				break;
				
			case 2:			
                if(date!=NULL)
                {
                    printDate(date);
                }
                else 
                {
                    printf("CREATE DATE BEFORE\n");
                }
                
				break;
				
			case 3:
                if(date==NULL)
                {
                    printf("CREATE DATE BEFORE\n");
                }
                else
                {
                    setTime(date->currTime);
                }
                
				break;
            case 4:
                if(date==NULL)
                {
                    printf("CREATE DATE BEFORE\n");
                }
                else
                {
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
                }
                
				break;
            
            case 5:
                if(date==NULL)
                {
                    printf("CREATE DATE BEFORE\n");

                }
                else
                {
                    setNewDate(date);
                }
                
                break;	
            
            case 6:
                if(date==NULL)
                {
                    printf("CREATE DATE BEFORE\n");

                }
                else
                {
                    doy = dayOfYear(date);
                
                    if(checkLeapYear(date->cYear)==0)
                    {
                        *leap = "yes";
                    }
                    else
                    {
                        *leap = "no";
                    }
                
                    printf ("current day in month : %d \n",date->cDay );
                    printf ("current month : %d \n",date->cMon)    ;
                    printf ("current year : %d \n",date->cYear )    ; 
                    printf ("day of year : %d \n",doy)    ;
                    printf ("is year leap or not : %s \n", *leap)  ; 
                    printf ("name of month : %s \n\n\n", monthName(date->cMon))  ;

                }
                
                       
                break;			
		}
	}
    free(time);
	free(date);
	return 0;
}
