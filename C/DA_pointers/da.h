#ifndef DA_H
#define DA_H

    typedef int* intPtr;

    typedef struct 
    {
        intPtr* arr;
        int capacity;
        int index;
        
    }Da_t;

Da_t* createDA(int capacity);

int insertDA(Da_t* da, intPtr nPtr );
void printDA(Da_t* da);
void destroyDA(Da_t* da);

#endif

