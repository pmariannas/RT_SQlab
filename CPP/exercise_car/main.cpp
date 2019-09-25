#include "car_t.h"
#include "bus_t.h"
#include "private_t.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    unsigned int i = 1;

    while (i)
    {
        cout << "\nChoose option: \n"<< endl;
        cout << "0 - exit " << endl;
        cout << "1 - create bus and private car by def constractor" << endl;
        cout << "2 - create bus and private with capacity" << endl;
        cout << "3 - operator=(const Car_t& c);" << endl;
        cout << "4 -  " << endl;
        cout << "5 - " << endl;
        cout << "6 - " << endl;
        cout << "7 - " << endl;
        cout << "8 - " << endl;
        cout << "9 - " << endl;
        cout << "10 - " << endl;
        

        cin >> i;
        switch (i)
        {
            case 0:
                i = 0;
                break;
            case 1:
            {
                Bus_t bus1;
                Private_t priv1;

                bus1.printBus();
                priv1.printPrivet();

                break;
            }
            case 2:
            {
                Bus_t bus2(4500);
                Private_t priv2(1800);
                bus2.printBus();
                priv2.printPrivet();

                break;
            }
            case 3:
            {
                Bus_t bus2(4500);
                Private_t priv2(1800);
                bus2.operator=(priv2).printCar();
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                
                break;
            }
            case 6:
            {
        
                break;
            }
            case 7:
            {

                break;
            }
            case 8:
            {
            
                break;
            }
            case 9:
            {
                
                break;
            }
            case 10:
            {
            
                break;
            }
        
        }
    }

    return 0;
}