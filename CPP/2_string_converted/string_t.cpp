#include "string_t.h"
#include <iostream>
#include <string>
using namespace std;

String_t::String_t() //CTOR
{
    this->str = createString(0);
    //this->size = 0;
}

String_t::String_t(const char* s) //CTOR from char*
{
    if(s!=NULL)
    {
        this->str = createString(s);
        //this->size = strlen(s);
    }
    
}

String_t::String_t (const String_t & cs) //copy CTOR
{
    this->str = createString(cs.str);
    //this->size = cs.size;
}

String_t& String_t :: operator = (const String_t& cs)
{
    if(this != &cs)
    {
        delete[] this->str;
        this->str = createString(cs.str);
    }
    return *this;
}

String_t::~String_t ()
{
    delete[] this->str;
}

void String_t::printString() 
{ 
    cout<< this->str;
    /*
    if(this->str!=NULL)
    {
        cout << "String is: " << this->str ; 
    } 
    else
        cout<<"NULL \n"<< endl;
    
    */
    
} 

int String_t::lengthString()const
{
    return strlen(this->str); //return value not add beacouse that we dont return const
}

void String_t::setString(const char* s)
{
    if(s!=NULL)
    {
        delete[] this->str;
        this->str = createString(s);
    }
}

const char* String_t::getString() const
{
    return this->str;      //return add because that we return const
}

int String_t::compareString(const String_t& s)const
{   
    int result = strcmp(this->str, s.str);
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

char* String_t::createString(const char* s)
{
    if(s==0)
    {
        str = new char[8];
        str[0] = '\n';
    }
    else
    {
        this->str = new char [strlen(s)+1];
        strcpy(this->str , s);
    }
    return str;
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
void String_t::prependFunc(const String_t& s)
{
    prependFunc(s.str);
}

void String_t::prependFunc(const char* s)
{
    char* tmp = new char[strlen(s)+strlen(this->str)+1];
    strcpy(tmp, s);
    strcat(tmp, this->str);
    delete[] this->str;
    this->str=tmp;
    //this->str = createString(tmp); 
    //delete[] tmp;
}

/*----------------------------------------------------*/
String_t& String_t::operator+=(const String_t& s)
{
    return *this += s.str;
}

String_t& String_t::operator+=(const char* s)
{
    char* tmp = new char[strlen(s)+strlen(this->str)+1];
    strcpy(tmp, this->str);
    strcat(tmp, s);
    delete[] this->str;
    this->str =tmp;
    //this->str = createString(tmp); 
    //delete[] tmp;
    return *this;
}

/*----------------------------------------------------*/
bool String_t::operator>(const String_t &s)const
{
    return (compareString(s)==2) ? true : false;
}

bool String_t::operator<(const String_t &s)const
{
    return (compareString(s)==1) ? true : false;
}

bool String_t::operator!=(const String_t &s)const
{
    return (compareString(s)!=0) ? true : false;
}

bool String_t::operator==(const String_t &s)const
{
    return (compareString(s)==0) ? true : false;
}

bool String_t::operator>=(const String_t &s)const
{
    return (compareString(s)==2 || compareString(s)==0) ? true : false;
}

bool String_t::operator<=(const String_t &s)const
{
    return (compareString(s)==1 || compareString(s)==0) ? true : false;

}

/*----------------------------------------------------*/
bool String_t::containsFunc(const char* s)const
{
    return strstr(this->str, s);
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

/*----------------------------------------------------*/

