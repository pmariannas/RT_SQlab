#include "car_t.h"

using namespace std;

size_t Car_t::default_car_id = 0; //init once

Car_t::~Car_t()
{
}

Car_t::Car_t():car_id(default_car_id++)
{
}

Car_t::Car_t(size_t capacity):car_id(default_car_id++)
{
    this->car_capacity = capacity;
}

Car_t::Car_t(const Car_t & c):car_id(default_car_id++)
{
    this->car_name = c.car_name;
    this->car_capacity = c.car_capacity;
    this->car_gear_type = c.car_gear_type;
}

Car_t& Car_t::operator=(const Car_t & c)
{
    //this->car_name = c.car_name;
    this->car_capacity = c.car_capacity;
    //this->car_gear_type = c.car_gear_type;
}

bool Car_t::operator<(const Car_t& c)const
{
    return (this->car_capacity < c.car_capacity);
}

bool Car_t::compare(const Car_t& c)const
{
    return (this->car_name == c.car_name);
}