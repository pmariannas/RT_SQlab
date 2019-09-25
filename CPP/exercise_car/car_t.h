#ifndef CAR_T_CLASS_H 
#define CAR_T_CLASS_H 

using namespace std;

#include <iostream>
#include <string>

enum Gear {Standart, Automatic};

class Car_t
{
    public:
        Car_t(); //CTOR
        Car_t (size_t capacity); 
        Car_t (const Car_t & c); //copy CTOR

        inline string getCarName(){return car_name;}
        inline Gear getCarGear(){return car_gear_type;}
        inline size_t getCarCapacity(){return car_capacity;}
        inline size_t getCarId(){return car_id;}
        Car_t& operator=(const Car_t& c);
        bool operator<(const Car_t& c)const;
        bool compare(const Car_t& c)const;
        void printCar()
        {
            cout << "car name: " <<getCarName() 
                << " car id: " <<getCarId()
                << " car capacity: " <<getCarCapacity()
               <<endl;
        }

    protected:
        ~Car_t();
        inline void setCarName(string name){ car_name = name;}
        inline void setCarGear(Gear gear){ car_gear_type = gear;}
        inline void setCarCapacity(size_t capacity){ car_capacity = capacity;}
    
    private:
        static size_t default_car_id;
        const size_t car_id;
        size_t car_capacity;
        string car_name;
        Gear car_gear_type;
        
        
};

#endif 