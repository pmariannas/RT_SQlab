#include <iostream>
#include <string.h>
#include <cstring>
#include "memManager.h"
#include "memPage.h"
#include "memPool.h"

void memTest(MemManager_t* mm)
{
    size_t option, i=1, size, position, ans;
    while (i)
    {
       cout << "1 - Get current position in memory" << endl
            << "2 - Set current position in memory" << endl
            << "3 - Get actual page size" << endl
            << "4 -" << endl
            << "5 - Write without position" << endl
            << "6 - Write with position" << endl
            << "7 - Read without position" << endl
            << "8 - Read with position" << endl
            << "9 - " << endl
            << "10- back to main" << endl;

        cin>>option;
        switch (option)
        {
            case 1:
                {
                    cout<< "The current position is: "<< mm->getCurrentPosition() <<endl;
                break;
                }
            case 2:
                {
                    try
                    {
                        cout<<"Set current position in memory ";
                        cin>>position;
                        mm->setCurrentPosition(position);
                    }
                    catch(string e)
                    {
                        cout << e << endl;
                    }
                    
                    break;      

                }  
            case 3:
                {
                    cout<< "The actual page size is: "<< mm->getActualPagelSize() <<endl;
                    break;
                }
            case 4:
                
                
                break;
            case 5:
                {
                    cout<< "enter string to write:"<<endl;
                    char buff[256];
                    cin>>buff;
                    cout<<"enter number of bytes to write: ";
                    cin>>size;
                    if(size>strlen(buff))
                    {
                        size = strlen(buff);
                    }
                    ans = mm->write(buff, size);
                    cout<<"The number of writen bytes: "<<ans<<endl;
                    break;          
                }
                
            case 6:
                {
                    cout<< "enter string to write:"<<endl;
                    char buff[256];
                    cin>>buff;
                    cout<<"enter number of bytes to write: ";
                    cin>>size;
                    cout<<"enter position to write: ";
                    cin>>position;
                    if(size>strlen(buff))
                    {
                        size = strlen(buff);
                    }
                    
                    ans = mm->write(buff, size, position);
                    cout<<"The number of writen bytes: "<<ans<<endl;
                    break;          
                }
                
            case 7:
                {
                    char buff[256];
                    cout<<"enter number of bytes to read: ";
                    cin>>size;
                    ans = mm->read(buff, size);
                    cout<<"The number of read bytes: "<<ans<<endl;
                    break;          
                }
                
            case 8:
                {
                    char buff[256];
                    cout<<"enter number of bytes to read: ";
                    cin>>size;
                    cout<<"enter position to read: ";
                    cin>>position;
                    ans = mm->read(buff, size, position);
                    cout<<"The number of read bytes: "<<ans<<endl;
                    break;          
                }
            case 9:
                {
                   
                }
                break;
            case 10:
                i=0;
                break;
            
            default:
                i=0;
                break;
        }
    }
    
}


int main()
{
    MemManager_t* mm;
    int i=1, option;
    while (i)
    {
        cout<<"for test Page enter 1, for Pool enter 2"<<endl;
        cin>>option;
        if(option==1)
        {
            mm = new MemPage_t;
        }
        else if(option==2)
        {
            mm = new MemPool_t;
        }
        
        try
        {
            memTest(mm);
        }
        catch(const std::exception& e)
        {
            cout << e.what() << '\n';
        }
        
        
    }
    
    
    return 0;
}