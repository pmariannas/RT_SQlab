#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread1(void *arg)
{
    int count;
    for(count = 0 ; count <= 3 ; count++)
    {
        printf(">>>> 1: (count %d) \n", count);
        sleep(1);
    }
    
}

void *thread2(void *arg)
{
    int count;
    for(count = 0 ; count <= 5 ; count++)
        {
            printf("    >>>> 2: (count %d) \n", count);
            sleep(3);
        }

}

int main()
{

    int status;
    pthread_t tid1, tid2;

    status = pthread_create(&tid1, NULL, thread1, NULL);
    status = pthread_create(&tid2, NULL, thread2, NULL);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    

    /*sleep(15);*/
}