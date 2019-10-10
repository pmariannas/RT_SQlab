#ifndef ISEQUAL_T_CLASS_H
#define ISEQUAL_T_CLASS_H

template <class T> class isEqual_t //example page 400
{

    public:
        ~isEqual_t(){}
        isEqual_t(T& t):val(t){}
        bool operator()(T* t)const{return *t==val;}
        
    private:
        T val;
};


#endif