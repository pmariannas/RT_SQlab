#ifndef VIRIO_T_CLASS_H
#define VIRIO_T_CLASS_H

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class virtIO_t
{
public:
    typedef enum status{ ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e } StatusIO;

    virtual ~virtIO_t(){ fClose(m_fp); } 
    virtIO_t();                                       //CTOR
    virtIO_t(const string &name, const string &mode); //CTOR

    const string& getFileName() const { return m_name; }
    const string& getFileMode() const { return m_mode; }

    size_t getPosition() const { return m_position; }
    
    size_t getFileLenght() const
    {
        size_t currPos = ftell(m_fp); 
        size_t lenght = 0;
        if (m_fp)
        {
            fseek(m_fp, 0, SEEK_END);
            lenght = ftell(m_fp);
            fseek(m_fp, currPos, SEEK_SET); //back to the currect position
        }
        return lenght;
    }

    void setPosition(size_t position);

    StatusIO getStatus() const { return m_status; }

    bool open();
    void fClose(FILE* fp);

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
    FILE* m_fp;
    string m_name;
    string m_mode;
    StatusIO m_status;
    size_t m_position;

    //void setStatus(StatusIO status) { m_status = status; }

private:
    virtIO_t(const virtIO_t &virt);            //copy CTOR
    virtIO_t &operator=(const virtIO_t &virt); //operator =
};

#endif