#include "virtIO_t.h"

virtIO_t::virtIO_t() //CTOR
{
    m_name = ' ';
    m_mode = ' ';
    m_status = ok_e;
    m_position = 0;
    FILE* m_fp = 0;
}

virtIO_t::virtIO_t(const string& name, const string& mode) //CTOR
{
    m_name = name;
    m_mode = mode;
    m_status = ok_e;
    m_position = 0;
    FILE* m_fp = 0;
}


bool virtIO_t::open()
{
    m_fp = fopen(m_name.c_str(), m_mode.c_str()); //c_str() converts a C++ string into a C-style string.
    if(!m_fp)
    {
        m_status = cant_open_file_e;
        throw m_status;
    }
}

void virtIO_t::fClose(FILE* fp)
{
    fclose(fp);
}

bool virtIO_t::checkValidRead()
{
    bool answer = true;
    if(!m_fp)
    {
        m_status = cant_open_file_e;
        answer = false;
    }
    else if( m_mode != "r" || m_mode != "r+")
    {
        m_status = bad_access_e;
        answer = false;
    }
    return answer;
}

bool virtIO_t::checkValidWrite()
{
    bool answer = true;
    if(!m_fp)
    {
        m_status = cant_open_file_e;
        answer = false;
    }
    else if(m_mode != "w" || m_mode != "w+"|| m_mode != "r+")
    {
        m_status = bad_access_e;
        answer = false;
    }
    return answer;
}


void virtIO_t::setPosition(size_t position)
    {
        //need to check possition<lenght
        if (position < getFileLenght())
        {
            fseek(m_fp, position, SEEK_SET);
            m_position = position;
        
        }
    }
//virtIO_t StatusIO getStatus()