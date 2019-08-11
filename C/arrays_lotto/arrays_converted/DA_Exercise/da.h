#ifndef DA_H
#define DA_H

    typedef struct 
    {
        int* arr;
        int capacity;
        int index;
        
    }Da_t;

Da_t* createDA(int capacity);
int insertDA(Da_t* da, int num );
void printDA(Da_t* da);
void destroyDA(Da_t* da);

#endif
