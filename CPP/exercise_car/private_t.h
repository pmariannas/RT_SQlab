
#ifndef PRIVATE_T_CLASS_H 
#define PRIVATE_T_CLASS_H 

#include <iostream>
#include <string>
#include "car_t.h"

using namespace std;

class Private_t:public Car_t
{
    public:
        ~Private_t();
        Private_t(); //CTOR
        Private_t(size_t c);
        Private_t(const Private_t& p); //copy CTOR

        void accelerates(){speed+=10;}
        void reduceSpeed(){
            if(this->speed < 0)
            {
                speed = 0;
            }
            else
            {
               speed-=10;
            }
        }
        void printPrivet(){
            cout << "car name: " <<getCarName() 
                << " car id: " <<getCarId()
                << " car capacity: " <<getCarCapacity()
                << " speed: " <<getSpeed()<<endl;
        }
        size_t getSpeed(){ return speed;}

    
    private:
        size_t speed;
        
        
};

#endif 
