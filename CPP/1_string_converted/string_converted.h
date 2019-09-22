#ifndef STRING_CONVERTED_CLASS_H 
#define STRING_CONVERTED_CLASS_H 

#include <string.h> 
#include <iostream> 

using namespace std; 

class String_t 
{ 
    public: 
        String_t();   //default CTOR
        String_t (const char* s);  //CTOR from char*
        String_t (const String_t & cs); //copy CTOR
        ~String_t (); //DTOR

        String_t& operator = (const String_t& s);
        void printString(); 
        const int lengthString(); //'length' which returns length of the string
        void setString(const char* s); //'setString' which gets as a parameter "const char*"
        const char* getString()const; //'getString' which returns "const char*"
        int compareString(const String_t& s)const; //'compare' which compares 2 strings
    
    private:
        char* str; 


   
}; 
  
#endif 