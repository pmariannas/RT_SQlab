#ifndef TEXCEPTION_CLASS_H
#define TEXCEPTION_CLASS_H

using namespace std; 

template <class TEH> class TException_t
{
    public:
    
        TException_t(); //CTOR
        TException_t(const city_t& city); //copy CTOR
        TException_t& operator=(const city_t& city); //operator =

        const TEH& getException()const;/* { return m_exception;}*/
        size_t getLineOfException()const; /*{ return m_lineNum;}*/
        string getMessage()const; /*{ return m_mess;}*/
        string getFileName()const; /*{ return fName;}*/
        

    private:
        TEH m_exception;    //exception object
        size_t m_lineNum;  // number of exception line
        string m_mess;  // description of exception
        string m_fName; // file name
};

template <class TEH>
TException_t::~TException_t()
{
}

template <class TEH>
TException_t::TException_t()
{
}

template <class TEH>
const TEH& TException_t<TEH>::getException()const
{
    return m_exception;
}

template <class TEH>
size_t TException_t<TEH>::getLineOfException()const 
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
    return fName;
}



#endif