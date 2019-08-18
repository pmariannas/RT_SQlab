#ifndef BITPACK_H
#define BITPACK_H

struct LRside
    {
        unsigned int left;
        unsigned int right;
    };

union un{
    struct LRside lr;
    char c;
    }; 

int compressWithout(char* mystr);

int compressUn(union un Union, char* mystr);





#endif