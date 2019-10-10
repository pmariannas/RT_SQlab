#include "container_t.h"



int main()
{
    unsigned int i = 1;
    unsigned int op=1;
    tContainer_t <int, vector<int*> > intArray;

    cout<< "choose vector(2) || list(3) || default(0)-vector"<<endl;
    cin>>op;
    while (op)
    {
        if(op==2)
        {
            tContainer_t <int, vector<int*> > intArray;
            break;
        }
        else if(op==3)
        {
            tContainer_t <int, list<int*> > intArray; 
            break;  
        }
        else
        {
            cout<< "choose vector(2) || list(3)"<<endl;
            cin >> op;
        }

    }
    
    while (i)
    {
        cout << "\nChoose option: \n"<< endl;
        cout << "0 - exit " << endl;
        cout << "1 - insert element container " << endl;
        cout << "2 - get Number Of Elements" << endl;
        cout << "3 - get First Element in container" << endl;
        cout << "4 - get Last Element in container" << endl;
        cout << "5 - remove All Elements" << endl;
        cout << "6 - remove and delete All Elements" << endl;
        cout << "7 - find by value" << endl;
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
                size_t num;
                int* x = new int;

                cout<<"enter element: ";
                cin>>num;
                *x = num;
                intArray.insertEnd(x);
            

                break;
            }
            case 2:
            {
                
                cout<< "number of element in container: " << intArray.getNumOfElements() <<endl;
                break;
            }
            case 3:
            {
                try
                {
                    cout<< "First Element in container: " <<intArray.getFirstElement() <<endl;

                }
                catch(string e)
                {
                    cout<< e << endl;
                }
                
                break;
            }
            case 4:
            {
                try
                {
                    cout<< "Last Element in container: " <<intArray.getLastElement() <<endl;
                }
                catch(string e)
                {
                    cout<< e << endl;
                }
                

                break;
            }
            case 5:
            {
                try
                {
                    intArray.removeAllElements();
                    cout<< "All Elements removed!"<< endl;
                }
                catch(string e)
                {
                    cout<< e << endl;
                }
                
                break;
            }
            case 6:
            {
                try
                {
                    intArray.removeAndDeleteAllElements();
                    cout<<"All Elements removed And Deleted" <<endl;
                }
                catch(string e)
                {
                    cout<< e << endl;
                }
                break;
            }
            case 7:
            {
                
                //intArray.findElement(10);
                cout<< "the find element is: " << endl;
               
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

