#include "virtIO_t.h"

virtIO_t::virtIO_t() //CTOR
{
    m_name = ' ';
    m_mode = ' ';
    m_status = ok_e;
    m_position = 0;
    *m_fp;
}

virtIO_t::virtIO_t(const string& name, const string& mode) //CTOR
{
        m_fp = fopen(name.c_str(),mode.c_str()); //c_str() converts a C++ string into a C-style string.
        if(m_fp==NULL)
        {
            m_status = cant_open_file_e;
            throw m_status;
        }

        m_name = name;
        m_mode = mode;
        m_status = ok_e;
}


bool virtIO_t::open()
{
    m_fp = fopen(m_name.c_str(), m_mode.c_str());
    if(!m_fp)
    {
        m_status = cant_open_file_e;
    }
}

void virtIO_t::close()
{
    fclose(m_fp);
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