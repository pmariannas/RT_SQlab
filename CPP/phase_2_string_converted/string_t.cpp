#include "string_t.h"
#include <iostream>
#include <string>
using namespace std;

String_t::String_t() //CTOR
{
    str = new char[8];
    str[0] = '\n';
}

String_t::String_t(const char* s)
{
    if(!s)
    {
        createString(s);
    }
    else
    {
        int newLen =strlen(s);
        this->str = new char [newLen+1];
        strcpy(this->str , s);
    }
}

String_t::String_t (const String_t & cs)
{
    createString(cs.str);
}

String_t& String_t :: operator = (const String_t& cs)
{
    if(this != &cs)
    {
        delete[] str;
        createString(cs.str);
    }
}

String_t::~String_t ()
{
    delete[] this->str;
}

void String_t::printString() 
{ 
    if(this->str!=NULL)
    {
        cout << "String is: " << this->str ; 
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
    if(s)
    {
        delete[]str;
        createString(s);
    }
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

/*-----------------------------*/

void String_t::convertUpper(const String_t& s) {
    for (int i=0; i<strlen(str); i++)
        putchar(toupper(str[i]));
}
void String_t::convertLower(const String_t& s) {
	for (int i=0; i<strlen(str); i++)
        putchar(tolower(str[i]));
}
/*
void logicOpFunc(char op, const String_t& s1)
{
    

}

*/
/*
char String_t::operator[](size_t pos)const {
        return this->getString(pos);
    }
char& String_t::operator[](size_t pos) {
        return this->getString(pos);
    }
*/
/*
void String_t::add(const String_t &text) {
        size_t new_size = this->str.lengthString() + text.lengthString();
        for (size_t i = new_size+1 ; i < new_size ; i++) 
        {
            this->str[i] = text.str[i - new_size+1];
        }
    }
*/


/*
String_t operator+(const String_t &string1, const String_t &string2) {
        String_t string = String_t(string1);
        this->str.add(string2);

        return str;
    }
*/

/*
bool operator==(const String_t &string1, const String_t &string2) {
        return string1.compareString(string2);
    }
*/


/*
std::ostream &operator<<(std::ostream &ostream, const MyString::String_t &string) {
        return (ostream << string.data);
    }
*/
