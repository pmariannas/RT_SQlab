#include "string_t.h"
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int String_t::numberOfString = 0; //init once 
int String_t::defaultCapacity = 8; //init once
bool String_t::caseSens = 0; //init once

/*----------------------------------------------------*/

char* String_t::createString(const char* s)
{
    numberOfString++;

    if(s==0)
    {
        this->str = new char[this->defaultCapacity];
        str[0] = '\0';
    }
    else
    {
        if(strlen(s)+1 < this->defaultCapacity)
        {
            this->str = new char [this->defaultCapacity];
        }
        else
        {
            int lenStr = nextPowerOf2(strlen(s));
            this->str = new char [lenStr+1];
        }
        
        strcpy(this->str , s);
    }
    return str;
}
/*----------------------------------------------------*/

String_t::String_t() //CTOR
{
    createString(0);
    this->capacity = this->defaultCapacity;
}
/*----------------------------------------------------*/

String_t::String_t(const char* s) //CTOR from char*
{
    if(s!=NULL)
    {
        createString(s);
        this->capacity = nextPowerOf2(strlen(s));
    } 
}
/*----------------------------------------------------*/

String_t::String_t (const String_t & cs) //copy CTOR
{
    createString(cs.str);
    this->capacity = nextPowerOf2(strlen(cs.str));
}
/*----------------------------------------------------*/

String_t& String_t :: operator = (const String_t& cs)
{
    if(this != &cs)
    {
        delete[] this->str;
        createString(cs.str);
        this->capacity = nextPowerOf2(strlen(cs.str));
    }
    return *this;
}
/*----------------------------------------------------*/

String_t::~String_t ()
{
    numberOfString--;
    delete[] this->str;
}
/*----------------------------------------------------*/

void String_t::setString(const char* s)
{
    if(s!=NULL)
    {
        if(this->capacity < strlen(s)+1)
        {
            delete[] this->str;
            createString(s);
            this->capacity = nextPowerOf2(strlen(s));
        }
        else
        {
            strcpy(this->str, s);
        }
        
    }
}
/*----------------------------------------------------*/

int String_t::compareString(const String_t& s)const
{   
    int result;
    if(caseSens)
    {
        result = strcasecmp(this->str, s.str);
    }
    else 
    {
        result = strcmp(this->str, s.str);
    }

    if(result < 0)
    {
        return 1;
    }
    else if(result > 0)
    {
        return 2;
    }
    else    //if they are equal
    {
        return 0;
    }

    //return result==0?2:result>0?:2 result<0?:1
}

/*----------------------------------------------------*/
void String_t::convertUpper() 
{
    for (int i=0 ; i<strlen(str) ; i++)
    {
        this->str[i] = toupper(this->str[i]);
    }
}

void String_t::convertLower() 
{   
    for (int i=0 ; i<strlen(str) ; i++)
    {
        this->str[i] = tolower(this->str[i]);
    }
}

/*----------------------------------------------------*/


void String_t::prependFunc(const char* s)
{
    int newLen = nextPowerOf2(strlen(s)+strlen(this->str));
    char* tmp = new char[newLen+1];
    strcpy(tmp, s);
    strcat(tmp, this->str);
    delete[] this->str;
    this->str=tmp;
    this->capacity = newLen;
    delete[] tmp;
}

/*----------------------------------------------------*/


String_t& String_t::operator+=(const char* s)
{
    int newLen = nextPowerOf2(strlen(s)+strlen(this->str));
    char* tmp = new char[newLen+1];
    strcpy(tmp, this->str);
    strcat(tmp, s);
    delete[] this->str;
    this->str =tmp;
    this->capacity = newLen;
    return *this;
}

/*----------------------------------------------------*/
char String_t::operator[](size_t pos)const
{
    if(pos > strlen(this->str))
    {
        pos = strlen(this->str);
    }
    return this->str[pos];
}

char& String_t::operator[](size_t pos)
{
    if(pos > strlen(this->str))
    {
        pos = strlen(this->str);
    }
    return this->str[pos];
}


int String_t::nextPowerOf2(int capacity)
{
    unsigned int p = 1;  
    if (capacity && !(capacity & (capacity - 1)))  
        return capacity;  
  
    while (p < capacity)  
        p <<= 1;  
      
    return p;  
}
/*----------------------------------------------------*/

String_t String_t::operator()(int start, int len)
{
    if(start < strlen(this->str))
    {
        char tmp[strlen(this->str)];
        strncpy(tmp, this->str + start, len);
        return String_t(tmp);
    }
    else
    {
        return String_t();
    }
    
}

