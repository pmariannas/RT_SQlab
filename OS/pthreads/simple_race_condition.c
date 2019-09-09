#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_OF_THREADS 10000
int count = 0;


/*
void *thread1(void *arg)
{
    
    incFunc(arg);
    
}
*/


void *incFunc(void *arg)
{
    /*
     int local;
    local = count;
    local++;
    count = local;
    */
    count++;
    sleep(1);

}

int main()
{
    int status, i;
    
    pthread_t tids[NUM_OF_THREADS];

    for(i = 0 ; i < NUM_OF_THREADS ; i++)
    {
        status = pthread_create(&tids[i], NULL, incFunc, NULL);
    }

    for(i = 0 ; i < NUM_OF_THREADS ; i++)
    {
        pthread_join(tids[i], NULL);
    }
    
    printf("count: %d \n", count);
    

}