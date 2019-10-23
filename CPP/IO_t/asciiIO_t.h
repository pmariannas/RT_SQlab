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
        asciiIO_t(const string& name, const string& mode){}/* : virtIO_t(name, mode) {}*/ //CTOR
       
        void fRead();
        void fWrite();

        asciiIO_t& operator>>(int& val);//{return fRead(name , "%d"); }return *this;
        asciiIO_t& operator<<(int val);//return *this;

        



    private:
        asciiIO_t(const asciiIO_t& ascii);            //copy CTOR
        asciiIO_t& operator=(const asciiIO_t& ascii); //operator 
        
};


#endif