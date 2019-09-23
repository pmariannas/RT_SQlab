#ifndef STRING_T_CLASS_H 
#define STRING_T_CLASS_H 

#include <string.h> 
#include <iostream> 

using namespace std; 

class String_t 
{ 
    public: 
        ~String_t (); //DTOR
        String_t();   //default CTOR
        String_t (const char* s);  //CTOR from char*
        String_t (const String_t & cs); //copy CTOR
        String_t& operator = (const String_t& s); //hasama
        
        const int lengthString(); //'length' which returns length of the string
        void setString(const char* s); //'setString' which gets as a parameter "const char*"
        const char* getString()const; //'getString' which returns "const char*"
        int compareString(const String_t& s)const; //'compare' which compares 2 strings
        void printString(); 

        //PHASE 2
        void convertUpper(const String_t& s);
        void convertLower(const String_t& s);
        //void prependFunc();
        //void addFunc();
        //void logicOpFunc(char op, const String_t& s1);
        //containsFunc();
        //void add(const String_t &text);

        //char operator[](size_t pos);
    
    private:
        char* str; 
        char* createString(const char* s);
}; 

String_t operator+(const String_t &string1, const String_t &string2);

bool operator>(const String_t &string1, const String_t &string2);
bool operator<(const String_t &string1, const String_t &string2);
bool operator!=(const String_t &string1, const String_t &string2);
bool operator==(const String_t &string1, const String_t &string2);


#endif 