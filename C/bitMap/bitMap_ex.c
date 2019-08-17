#include <stdio.h>
#include <stdlib.h>
#include "bitMap_ex.h"

static const countBit = (sizeof(char)*8);

static void int2Bin(int num)
{
	int i = 0, binNum=0;
	
    for (i = countBit-1 ; i >= 0 ; i--)
	{
		binNum = num >> i;
		if(binNum & 1)
		{
			printf("1");
		}		  
		else
		{
			printf("0");
		}
	}
}

bitMap_t* createBitMap(int nf)
{
    bitMap_t* m_bm;
    int arrSize;
    
    if(nf%countBit == 0)
    {
        arrSize = nf/countBit;   
    }
    else 
    {
        arrSize = nf/countBit+1;

    }
    
    m_bm = (bitMap_t*)malloc(sizeof(bitMap_t));

    if(m_bm != NULL)
    {
        m_bm->m_bitArray = calloc(arrSize, sizeof(int));
        if (m_bm->m_bitArray == NULL)                     
        {
            free(m_bm);
            return NULL;
        }
        m_bm->m_nf=nf;
    }
    if (m_bm == NULL)                     
    {
        return NULL;
    }
    return m_bm;
}

int bitOn(bitMap_t* bm, int n)
{
    unsigned int indexArr, posOn, flag = 1;
	if (n > bm->m_nf)
    {
        return -1;      /*place of feature to on, not exist*/
    }
	if(bm == NULL)
	{
		return -1;
	}
    n = n-1; /*index of bit between 0-7*/
	indexArr = n/countBit;
	posOn = n%(countBit);
	flag = flag << (countBit - 1- posOn);	
	bm->m_bitArray[indexArr] = bm->m_bitArray[indexArr] | flag;
	
	return 0;

}

int bitOff(bitMap_t* bm, int n)
{
    unsigned int indexArr, posOff, flag = 1;
	if (n > bm->m_nf)
    {
        return -1;      /*place of feature to off, not exist*/
    }
	if(bm == NULL)
	{
		return -1;
	}
    n=n-1; /*index of bit between 0-7*/
    indexArr = n/(countBit);
	posOff = n%(countBit);	

	flag = flag << (countBit -1- posOff);
    flag =~ flag; /*bitwise NOT (one's complement)*/
	bm->m_bitArray[indexArr] = bm->m_bitArray[indexArr] & flag;

    return 0;
}

int bitStatus(bitMap_t* bm, int n)
{
    unsigned int indexArr, posStatus, flag = 1;
    int statusBits;

	if (n > bm->m_nf)
    {
        return -1;      /*place of feature to check, not exist*/
    }
	if(bm == NULL)
	{
		return -1;
	}

    n=n-1;  /*index of bit between 0-7*/
    indexArr = n/(countBit);
	posStatus = n%(countBit);

    flag = flag << (countBit-1-posStatus);

    statusBits = bm->m_bitArray[indexArr] & flag;

    return statusBits;
}

int printBitMap(bitMap_t* bm)
{
    int  i, arrSize=0;
    
    if(bm->m_nf%countBit > 0)
    {
        arrSize = bm->m_nf/countBit+1;

    }
    else 
    {
        arrSize = bm->m_nf/countBit;  
    }
    
    
    if(bm == NULL)
	{
		return -1;
	}
    for (i = 0; i < arrSize ; i++)
    {
        int2Bin(bm->m_bitArray[i]);
    }
    
    printf("\n");
    return 0;
}

void destroyBitMap(bitMap_t* bm)
{
    if(bm->m_bitArray!=NULL)
    {
        free(bm->m_bitArray);
    }

    free(bm);
}


