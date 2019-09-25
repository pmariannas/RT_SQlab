#ifndef BUS_T_CLASS_H 
#define BUS_T_CLASS_H 

#include <iostream>
#include <string>
#include "car_t.h"

using namespace std;

class Bus_t:public Car_t
{
    public:
        ~Bus_t(); //DTOR
        Bus_t(); //default CTOR
        Bus_t(size_t c); //CTOR from capacity
        Bus_t(const Bus_t& b); //copy CTOR

        inline void setCountSeats(size_t value){ countSeats = value;}
        inline void setLineNumber(size_t value){ lineNumber = value;}
        inline size_t getCountSeats(){ return countSeats;}
        inline size_t getLineNumber(){ return lineNumber;}
        void printBus(){
            cout << "car name: " <<getCarName() 
                << " car id: " <<getCarId()
                << " car capacity: " <<getCarCapacity()
                << " count seats: " <<getCountSeats()
                << " line number: " <<getLineNumber()<<endl;
        }
    protected:
        
    
    private:
        size_t countSeats;
        size_t lineNumber;
        
};

#endif 