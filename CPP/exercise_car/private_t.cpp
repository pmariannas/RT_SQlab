#include "private_t.h"

using namespace std;


Private_t::~Private_t()
{
}

Private_t::Private_t()
{
    setCarName("PRIVATE");
    //setCarGear('Automatic');
    setCarCapacity(1500);
    this->speed = 0;
}

Private_t::Private_t(const size_t capacity)
{
    setCarName("PRIVATE");
    //setCarGear('Automatic');
    setCarCapacity(capacity);
    this->speed = 0;
}

Private_t::Private_t(const Private_t& c)
{
    setCarName("PRIVATE");
    //setCarGear('Automatic');
    setCarCapacity(1500);
    this->speed = 0;
}
