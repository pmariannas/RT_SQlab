#ifndef FILES_EX_H
#define FILES_EX_H

typedef struct 
{
    char* word;
    int count;
    
}FreqWords_t;

int last(/*char* fName,*/ int N);
int freqChar();
int freqWords();

#endif
