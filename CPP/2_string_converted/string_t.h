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
        String_t& operator = (const String_t& s); 
        
        int lengthString()const; // length of the string
        void setString(const char* s); 
        const char* getString()const; 
        int compareString(const String_t& s)const; //'compare' which compares 2 strings
        void printString(); 

        //PHASE 2
        //1
        void convertUpper();
        void convertLower();
        //2
        void prependFunc(const String_t& s);
        void prependFunc(const char* s);
        //3
        String_t& operator+=(const String_t& s);
        String_t& operator+=(const char* s);
        //4
        bool operator>(const String_t &s)const;
        bool operator<(const String_t &s)const;
        bool operator!=(const String_t &s)const;
        bool operator==(const String_t &s)const;
        bool operator>=(const String_t &s)const;
        bool operator<=(const String_t &s)const;
        //5
        bool containsFunc(const char* s)const;
        //6 
        char operator[](size_t pos)const;
        char& operator[](size_t pos);
        
    
    private:
        char* str;
        char* createString(const char* s);
}; 

#endif 