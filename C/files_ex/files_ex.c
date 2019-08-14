#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files_ex.h"

int last( int N)
{
	FILE* fp;
	char str[1024];
	int* array;
	int i = 0;

	fp = fopen("myfile.txt", "r");

	if(fp== NULL)
	{
		return -1;
	}
	
	array = (int*)malloc(N*sizeof(int));

	if(array == NULL)
	{
		return -1;
	}

	for (i = 0; i < N; i++)
    {
        array[i] = 0;
    }
	
	
	while(fgets(str, 1024, fp) != NULL) /*reads a line from the specified stream and stores it into the string*/
	{
        if(fgetc(fp) != EOF) /*gets the next character from the specified stream*/
        {
		    i = (i + 1)%N;
		    array[i] = ftell(fp) - 1;/*ftell-returns the current file position of the given stream*/
        }				
	}
	
    /*fseek -  function is used to move file pointer position to the given location.*/
	fseek(fp, array[(i + 1)%N],0); 
	
	while(fgets(str, 1024, fp) != NULL) 
    {

		printf("%s", str);
	}
	
	
	free(array);

    return 0;
}

int freqChar()
{
    int ch, frequency[26];
    
    FILE* fp = fopen ("myfile.txt", "r");
    FILE* output = fopen ("output1.txt", "w");
    if(fp== NULL)
	{
		return -1;
	}
	
    /* init the freq with 0 */
    for (ch = 0; ch < 26; ch++)
    {
        frequency[ch] = 0;
    }
        
    while (1) 
    {
        ch = fgetc(fp);
        if (ch == EOF) 
        {
            break; /* end of file */
        }
    
        /* assuming ASCII */
        if (ch >='a' && ch <= 'z')    
            {
                frequency[ch-'a']++;
            }
        else if (ch >= 'A' && ch <= 'Z') 
            {
                frequency[ch-'A']++;
            }
    }

    for (ch = 0; ch < 26; ch++)
    {
        if(frequency[ch]!=0)
            {
                printf ("%d  %c\n", frequency[ch], 'A'+ch);
            }
    }

    if(fclose(fp) != 0)
	{
		return -1;
	}
	
    return 0;
}

int freqWords()
{
    FreqWords_t* array[512];
    FILE* fp = fopen ("myfile.txt", "r");
    FILE* output = fopen ("output.txt", "w");
    char *word;
    int index=0 , i=0, j=0, f=0;
	char str[32];

    for(i=0 ; i<512 ; i++)
    {
        array[i] = (FreqWords_t*)malloc(128*sizeof(FreqWords_t));
        if(array == NULL)
        {
            return -1;
        }
    }
    
   
/*while ( != NULL)
    {
        for(j=0; j<i ; j++)
        {   
            if(str==array[j]->word)
            {
                array[j]->count++;
            }

        }
        if(i==0)
        {
            array[i]->word = str;
            array[i]->count++;
        }
        i++;
    }
    */

	

    for (j = 0; j < i; j++)
    {
        fprintf(output, "%s = %d\n", array[j]->word, array[j]->count);
    }
    /*FREE*/

    if(fp== NULL)
	{
		return -1;
	}
	 
 
   
    if(fclose(fp) != 0)
	{
		return -1;
	}
	
}

