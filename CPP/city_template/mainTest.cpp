#include <iostream>
#include <string>
#include "building_t.h"
#include "street_t.h"
#include "city_t.h"

int main()
{
    size_t i=1, option;
    building_t<int> b1;
    street_t<string, int> s1;
    city_t<string, string, int> c1;

    while (i)
    {
       cout << "1 - create building" << endl
            << "2 - create street" << endl
            << "3 - create city" << endl
            << "4 - add Street To City" << endl
            << "5 - add Building To Street" << endl
            << "6 - get street from city" << endl
            << "7 - get building from street" << endl

            //<< "8 - " << endl
            //<< "9 - " << endl
            << "10- back to main" << endl;

        cin>>option;
        switch (option)
        {
            case 1:
                {
                    
                    b1.setBuilding(10);
                    cout<< b1.getBuilding()<< endl;
                }
                break;
            case 2:
                {
                    s1.setStreet("Rotshild");
                    cout<< s1.getStreet()<< endl;
                }
                break;  
            case 3:
                {
                    c1.setCity("Tel Aviv");
                    cout<< c1.getCity()<<endl;
                }
                break;
            case 4:
                {
                    c1.setStreetToCity(s1);
                }
                break;
            case 5:
                {
                    s1.setBuildingToStreet(b1);
                }
                break;
            case 6:
                {
                    try
                    {
                        cout<<"try to get street Alenbi from Tel Aviv ";
                        c1.getStreetFromCity("Alenbi");  
                        
                    }
                    catch(string e)
                    {
                        cout << e << endl;
                    }

                    try
                    {
                        cout<<"try to get street Rotshild from Tel Aviv ";
                        c1.getStreetFromCity("Rotshild");                    
                    }
                    catch(string e)
                    {
                        cout << e << endl;
                    }     
                } 
                break;
            case 7:
                {
                    try
                    {
                        cout<<"try to get building 111 from street Rotshild ";
                        s1.getBuildingFromStreet(111);                    
                      
                    }
                    catch(string e)
                    {
                        cout << e << endl;
                    }     
                } 
                break;
            case 8:
                break;
            case 9:
                
                break;
            case 10:
                i=0;
                break;
            
            default:
                i=0;
                break;
        }
    }
    
    
    return 0;
}