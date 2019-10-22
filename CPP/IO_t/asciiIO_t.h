#ifndef asciiIO_T_CLASS_H
#define asciiIO_T_CLASS_H

#include <iostream>
#include <string>

using namespace std;

class asciiIO_t: public virtIO_t
{
    public:
        ~asciiIO_t(){} //DTOR
        asciiIO_t(){} //CTOR
        asciiIO_t(const string& name, const string& mode) : virtIO_t(name, mode) {} //CTOR
       

        virtIO_t& operator>>(int& val);
        virtIO_t& operator<<(int val);

        



    private:
        
};


#endif