#ifndef VIRIO_T_CLASS_H
#define VIRIO_T_CLASS_H

#include <iostream>
#include <string>

using namespace std;

class virtIO_t
{
    public:
        virtual ~virtIO_t()=0;
        
        
        virtual virtIO_t& operator>>(int& num)=0;
        virtual virtIO_t& operator<<(int num)=0;

        virtual virtIO_t& operator>>(float& num)=0;
        virtual virtIO_t& operator<<(float num)=0;
        /*
        virtual virtIO_t& operator>>(long& num)=0;
        virtual virtIO_t& operator<<(long num)=0;

        virtual virtIO_t& operator>>(short& num)=0;
        virtual virtIO_t& operator<<(short num)=0;

        virtual virtIO_t& operator>>(char& num)=0;
        virtual virtIO_t& operator<<(char num)=0;
        */
       enum status{ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e};
       

    private:
        string m_fileName;
    
        virtIO_t(); //CTOR
        virtIO_t(const virtIO_t& virt); //copy CTOR
        virtIO_t& operator=(const virtIO_t& virt); //operator =
};


#endif