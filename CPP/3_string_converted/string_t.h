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
        
        
        void setString(const char* s); 
        int compareString(const String_t& s)const; //'compare' which compares 2 strings

        inline const char* getString()const; 
        inline int lengthString()const; // length of the string
        inline void printString(); 

        void convertUpper();
        void convertLower();
        
        inline void prependFunc(const String_t& s);
        void prependFunc(const char* s);
        
        inline String_t& operator+=(const String_t& s);
        String_t& operator+=(const char* s);
        
        inline bool operator>(const String_t &s)const;
        inline bool operator<(const String_t &s)const;
        inline bool operator!=(const String_t &s)const;
        inline bool operator==(const String_t &s)const;
        inline bool operator>=(const String_t &s)const;
        inline bool operator<=(const String_t &s)const;
        
        inline bool containsFunc(const char* s)const;
        
        char operator[](size_t pos)const;
        char& operator[](size_t pos);
        
        //3
        inline static bool getSensitiveFlag(){return caseSens;}
        inline static bool setSensitiveFlag(bool sensFlag);

        inline static int getCurrDefCapacity(){return defaultCapacity;}
        inline static int setCurrDefCapacity(int newDefCap);
            
        String_t operator()(int start, int len);

        inline int firstOccur(char c)const;
        inline int lastOccur(char c)const;


    private:
        char* str;
        char* createString(const char* s);
        int capacity;
        
        static int numberOfString;
        static int defaultCapacity;
        static bool caseSens;
        static int nextPowerOf2(int capacity);

                

}; 


/*----------------------------------------------------*/

inline int String_t::lengthString()const
{
    return strlen(this->str); 
}
/*----------------------------------------------------*/

inline const char* String_t::getString() const
{
    return this->str;      
} 
/*----------------------------------------------------*/

inline void String_t::printString() 
{ 
    cout<< this->str;
} 
/*----------------------------------------------------*/

inline void String_t::prependFunc(const String_t& s)
{
    prependFunc(s.str);
}
/*----------------------------------------------------*/

inline String_t& String_t::operator+=(const String_t& s)
{
    return *this += s.str;
}
/*----------------------------------------------------*/

inline bool String_t::operator>(const String_t &s)const
{
    return (compareString(s)==2) ? true : false;
}
/*----------------------------------------------------*/

inline bool String_t::operator<(const String_t &s)const
{
    return (compareString(s)==1) ? true : false;
}
/*----------------------------------------------------*/

inline bool String_t::operator!=(const String_t &s)const
{
    return (compareString(s)!=0) ? true : false;
}
/*----------------------------------------------------*/

inline bool String_t::operator==(const String_t &s)const
{
    return (compareString(s)==0) ? true : false;
}
/*----------------------------------------------------*/

inline bool String_t::operator>=(const String_t &s)const
{
    return (compareString(s)==2 || compareString(s)==0) ? true : false;
}
/*----------------------------------------------------*/

inline bool String_t::operator<=(const String_t &s)const
{
    return (compareString(s)==1 || compareString(s)==0) ? true : false;
}
/*----------------------------------------------------*/

inline bool String_t::containsFunc(const char* s)const
{
    return strstr(this->str, s);
}
/*----------------------------------------------------*/
    
inline int String_t::setCurrDefCapacity(int newDefCap)
{
    int prevCap = getCurrDefCapacity();
    defaultCapacity = newDefCap;
    return prevCap;
}
/*----------------------------------------------------*/

inline bool String_t::setSensitiveFlag(bool sensFlag)
 {
     bool prevSens = getSensitiveFlag();
     caseSens = sensFlag;
     return prevSens;
 }
/*----------------------------------------------------*/

inline int String_t::firstOccur(char c)const
{
    char* result = strchr(this->str, c);
    return result ? result-this->str : -1;
}

/*----------------------------------------------------*/

inline int String_t::lastOccur(char c)const
{
    char* result = strrchr(this->str, c);
    return result ? result-this->str : -1;
}




#endif 