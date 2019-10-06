#ifndef TEXCEPTION_CLASS_H
#define TEXCEPTION_CLASS_H

using namespace std; 

template <class TEH> class TException_t
{
    public:
        ~TException_t(){} //CTOR
        TException_t(const TEH& exception, const string& message,  const int& line, const string& name); //CTOR
        TException_t(const TException_t& obj){} //copy CTOR
        

        const TEH& getException()const { return m_exception;}
        const int& getLineOfException()const{ return m_lineNum;}
        const string& getMessage()const{ return m_mess;}
        const string& getFileName()const{ return m_fName;}
        

    private:
        TEH m_exception;    //exception object
        int m_lineNum;  // number of exception line
        string m_mess;  // description of exception
        string m_fName; // file name
    
        TException_t& operator=(const TException_t& obj){} //operator =
};

// template <class TEH>
// TException_t::~TException_t()
// {
// }

template <class TEH>
TException_t<TEH>::TException_t(const TEH& exception, const string& message,  const int& line, const string& name)
{
    m_exception = exception;
    m_lineNum = line;
    m_mess = message;
    m_fName = name;
}


/*
template <class TEH>
const TEH& TException_t<TEH>::getException()const
{
    return m_exception;
}

template <class TEH>
int TException_t<TEH>::getLineOfException()const 
{ 
    return m_lineNum;
}

template <class TEH>
string TException_t<TEH>::getMessage()const 
{ 
    return m_mess;
}

template <class TEH>
string TException_t<TEH>::getFileName()const 
{ 
    return m_fName;
}
*/


#endif
