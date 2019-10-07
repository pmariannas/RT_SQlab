#ifndef CONTAINER_T_CLASS_H
#define CONTAINER_T_CLASS_H

using namespace std;

template<class T, class C> class tContainer_t
{
    public:
        ~tContainer_t(); //DTOR
        tContainer_t(); //CTOR
       
        bool isEmpty(); //return true/false according to is container empty or not
        size_t getNumOfElements(); // return number of element in container
        void insertEnd(const tContainer_t& cont); // insert a new element in the end of container
        const T& getFirstElement()const; //return first element in container
        const T& getLastElement()const; //return last element in container
        bool findElement(tContainer_t& cont); 
        void removeElement();
        void removeAllElements();
        void removeAndDeleteElement();
        void removeAndDeleteAllElements();
        //tContainer_t<T, C> operator []();


    private:
        typedef typename tContainer_t::
        C container;
        tContainer_t(const tContainer_t& cont); //copy CTOR
        tContainer_t<T, C> operator=(const tContainer_t& cont); //operator =

};

#endif