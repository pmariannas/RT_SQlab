#include "bus_t.h"

using namespace std;


Bus_t::~Bus_t()
{
}

Bus_t::Bus_t()
{
    setCarName("BUS");
    //setCarGear('Standart');
    setCarCapacity(1500);
    this->countSeats = 50;
    this->lineNumber = 15;

}

Bus_t::Bus_t(const size_t capacity)
{
    setCarName("BUS");
    //setCarGear('Standart');
    setCarCapacity(capacity);
    this->countSeats = 50;
    this->lineNumber = 15;
}

Bus_t::Bus_t(const Bus_t & c)
{
    setCarName("BUS");
    //setCarGear('Standart');
    setCarCapacity(1500);
    this->countSeats = 50;
    this->lineNumber = 15;
}
