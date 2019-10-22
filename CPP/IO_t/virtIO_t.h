#ifndef VIRIO_T_CLASS_H
#define VIRIO_T_CLASS_H

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

typedef enum status
{
    ok_e,
    cant_open_file_e,
    bad_access_e,
    writeErr_e,
    readErr_e
} StatusIO;

class virtIO_t
{
public:
    virtual ~virtIO_t() = 0;
    virtIO_t();                                       //CTOR
    virtIO_t(const string &name, const string &mode); //CTOR

    const string &getFileName() const { return m_name; }
    const string &getFileMode() const { return m_mode; }

    size_t getPosition() const { return m_position; /*return ftell(m_fp);*/ }
    void setPosition(size_t position)
    {
        if (m_fp)
        {
            fseek(m_fp, position, SEEK_SET);
            m_position = position;
        }
    }
    size_t getFileLenght() const
    {
        size_t lenght = 0;
        if (m_fp)
        {
            fseek(m_fp, 0, SEEK_END);
            lenght = ftell(m_fp);
        }
        return lenght;
    }

    StatusIO getStatus() const { return m_status; }

    bool open();
    void close();

    bool checkValidWrite();
    bool checkValidRead();

    virtual virtIO_t &operator>>(int &num) = 0;
    virtual virtIO_t &operator<<(int num) = 0;
    /*
        virtual virtIO_t& operator>>(float& num)=0;
        virtual virtIO_t& operator<<(float num)=0;
        
        virtual virtIO_t& operator>>(long& num)=0;
        virtual virtIO_t& operator<<(long num)=0;

        virtual virtIO_t& operator>>(short& num)=0;
        virtual virtIO_t& operator<<(short num)=0;

        virtual virtIO_t& operator>>(char& num)=0;
        virtual virtIO_t& operator<<(char num)=0;

        virtual virtIO_t& operator>>(unsigned int& num)=0;
        virtual virtIO_t& operator<<(unsigned int num)=0;

        virtual virtIO_t& operator>>(unsigned float& num)=0;
        virtual virtIO_t& operator<<(unsigned float num)=0;

        virtual virtIO_t& operator>>(unsigned long& num)=0;
        virtual virtIO_t& operator<<(unsigned long num)=0;

        virtual virtIO_t& operator>>(unsigned short& num)=0;
        virtual virtIO_t& operator<<(unsigned short num)=0;

        virtual virtIO_t& operator>>(unsigned char& num)=0;
        virtual virtIO_t& operator<<(unsigned char num)=0;
        */

protected:
    string m_name;
    string m_mode;
    StatusIO m_status;
    size_t m_position;
    FILE *m_fp;

    StatusIO setStatus(StatusIO status) { m_status = status; }

private:
    virtIO_t(const virtIO_t &virt);            //copy CTOR
    virtIO_t &operator=(const virtIO_t &virt); //operator =
};

#endif