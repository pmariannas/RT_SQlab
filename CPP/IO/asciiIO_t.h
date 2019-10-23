#ifndef ASCIIIO_T_CLASS_H
#define ASCIIIO_T_CLASS_H
#include "virtIO_t.h"
#include <typeinfo>

class asciiIO_t : public virtIO_t
{
public:
    ~asciiIO_t() {} //DTOR
    asciiIO_t() {}  //CTOR
    asciiIO_t(string newName, string newMode) : virtIO_t(newName, newMode)
    {
        if ((m_mode != "r") && (m_mode != "r+") && (m_mode != "w") && (m_mode != "w+"))
        {
            m_status = bad_access_e;
            throw m_status;
        }
    }
    asciiIO_t &operator<<(int num);
    asciiIO_t &operator>>(int &num);

    asciiIO_t &operator<<(char c);
    asciiIO_t &operator>>(char &c);

    asciiIO_t &operator<<(float num);
    asciiIO_t &operator>>(float &num);

    asciiIO_t &operator<<(short num);
    asciiIO_t &operator>>(short &num);

    asciiIO_t &operator<<(long num);
    asciiIO_t &operator>>(long &num);

    asciiIO_t &operator<<(double num);
    asciiIO_t &operator>>(double &num);

    asciiIO_t &operator<<(unsigned int num);
    asciiIO_t &operator>>(unsigned int &num);

    asciiIO_t &operator<<(unsigned char c);
    asciiIO_t &operator>>(unsigned char &c);

    asciiIO_t &operator<<(unsigned short num);
    asciiIO_t &operator>>(unsigned short &num);

    asciiIO_t &operator<<(unsigned long num);
    asciiIO_t &operator>>(unsigned long &num);

private:
    template <class T>
    asciiIO_t &Read(T &t, const char *format)
    {
        {
            if (validRead())
            {
                int output;
                output = fscanf(m_fp, format, &t);
                return *this;
            }
            throw string("mode error.");
        }
    }

    template <class T>
    asciiIO_t &Write(T t, const char *format)
    {
        if (vaildWrite())
        {
            int output;
            output = fprintf(m_fp, format, t);
            if (output < 0)
            {
                throw string("cant write to file");
            }
            return *this;
        }
        throw string("file didnt open. \n");
    }

    asciiIO_t(const asciiIO_t &t);            //copy CTOR
    asciiIO_t &operator=(const asciiIO_t &t); //operator =
};

// template <class T>
// asciiIO_t& asciiIO_t::Read(T &t, const char *format)
// {
//     if (validRead())
//     {
//         int output;
//         output = fscanf(m_fp, format, &t);
//         return *this;
//     }
//     throw string("mode error.");
// }
// template <class T>
// asciiIO_t& asciiIO_t::Write(T t, const char *format)
// {
//     if (vaildWrite())
//     {
//         int output;
//         output = fprintf(m_fp, format, t);
//         if (output < 0)
//         {
//             throw string("cant write to file");
//         }
//         return *this;
//     }
//     throw string("file didnt open. \n");
// }
#endif