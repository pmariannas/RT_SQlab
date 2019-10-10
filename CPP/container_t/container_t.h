#ifndef CONTAINER_T_CLASS_H
#define CONTAINER_T_CLASS_H

#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <typeinfo>
#include <algorithm>
#include <string>
#include "isEqual_t.h"

using namespace std;

template<class T, class C> class tContainer_t
{
    public:
        virtual ~tContainer_t(){} //DTOR
        tContainer_t(){} //CTOR
       
        bool isEmpty()const {return m_container.empty();} //return true/false according to is container empty or not
        size_t getNumOfElements()const {return m_container.size();} // return number of element in container
        void insertEnd(T* value) { m_container.push_back(value);} // insert a new element in the end of container
        const T* getFirstElement()const 
        {return isEmpty()? throw string("container empty"):(m_container.front());} //return first element in container
        const T* getLastElement()const 
        {return isEmpty()?throw string("container empty"):(m_container.back());} //return last element in container
        
        bool findElement(T& value)//<algorithm> --> find_if - find element int range 
        {
            iter it = find_if(m_container.begin(), m_container.end(),isEqual_t<T>(value) );
            if(it!=m_container.end())
            {
                return true;
            }
            else
            {
                return false;
            }
            

            
        } 
        
        //void removeElement();
        void removeAllElements()
        {
            if(isEmpty())
            {
                throw string("container empty");
            }
            else
            {
                iter m_it = m_container.begin();
                while(m_it != m_container.end())
                {
                    m_it = m_container.erase(m_it);
                }
            }
        }
        //void removeAndDeleteElement();
        void removeAndDeleteAllElements()
        {
            if(isEmpty())
            {
                throw string("container empty");
            }
            else
            {
                iter m_it = m_container.begin();
                T* tmp;
                while(m_it != m_container.end())
                {
                    tmp = *m_it;
                    m_it = m_container.erase(m_it);
                    delete tmp;
                } 
            }  
        }
        /*T* operator [](size_t index)const
        {
           
        }
        */


    private:
        typedef typename C::iterator iter;
        typedef typename C::const_iterator c_iter;

        C m_container;

        tContainer_t(const tContainer_t& cont); //copy CTOR
        tContainer_t<T, C> operator=(const tContainer_t& cont); //operator =

};

#endif