#include "string_converted.h"
#include <iostream>
#include <string>
using namespace std;

String_t::String_t() //CTOR
{
    this->str = 0;
}

String_t::String_t(const char* s)
{
    if(s!=NULL)
    {
        this->str = new char [strlen(s)+1];
        strcpy(this->str , s);
    }
}

String_t::String_t (const String_t & cs)
{
    this->str = cs.str;
}

String_t& String_t :: operator = (const String_t& cs)
{
    if(this != &cs)
    {
        delete[]str;
        this->str = new char [strlen(cs.str)+1];
        strcpy(this->str , cs.str);
    }
}

String_t::~String_t ()
{
    delete[]this->str;
}

void String_t::printString() 
{ 
    if(this->str!=NULL)
    {
        cout << "String is: " << this->str << " \n";  
    }
    else
        cout<<"NULL \n"<< endl;
} 

const int String_t::lengthString()
{
    return (unsigned)strlen(this->str);
}

void String_t::setString(const char* s)
{
    delete[]str;
    this->str = new char [strlen(s)+1];
    strcpy(this->str , s);

}

const char* String_t::getString() const
{
    return this->str;
}

int String_t::compareString(const String_t& s)const
{   
    int result;
    result = strcmp(this->str, s.str);
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
}

