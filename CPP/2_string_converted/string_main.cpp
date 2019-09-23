#include "string_t.h"
#include <iostream>

using namespace std;
void stringCompare()
{
    char* string = new char[128];
    cout<< "enter string 1\n";
    cin>>string;
    String_t s1(string);
    delete[] string;

    cout<< "enter string 2\n";
    cin>>string;
    String_t s2(string);
    delete[] string;

    cout<< "compare result: " << s1.compareString(s2) << endl;
}

void upperConvert()
{
    char* string = new char[128];
    cout<< "enter string \n";
    cin>>string;
    String_t s1(string);
    delete[] string;
    s1.convertUpper();
    cout<< "upper result --> " ;
    s1.printString() ;
}

void funcPrepend()
{
    char* string = new char[128];
    cout<< "enter string 1\n";
    cin>>string;
    String_t s1(string);
    delete[] string;
    
    cout<< "enter string 2\n";
    cin>>string;
    
    s1.prependFunc(string);
    delete[] string;
    cout<< "prepend result -->  ";
    s1.printString();
}

int main() 
{ 

    unsigned int i = 1;
    
    while(i)
    {
        cout << "\nChoose option: \n" << endl;
        cout << "0 - exit " << endl;
        cout << "1 - constractor" << endl;
        cout << "2 - COMPARE String " << endl;
        cout << "3 - convertUpper" << endl;
        cout << "4 - prependFunc " << endl;
        cout << "5 - prependFunc(const String_t& s)"<< endl;
        cout << "6 - operator+=(const char* s)" << endl;
        cout << "7 - operator> " << endl;
        cout << "8 - containsFunc(const char* s)" << endl;
        cout << "9 - char operator[](size_t pos)const " << endl;
        cout << "10 - " << endl;
            
        cin >> i;
        switch (i) 
        {
            case 0: 
                i = 0 ;
                break; 
            case 1: 
            {
                String_t s1; 
                String_t s2("Marianna");
                String_t s3 = s2;
                cout<< "default constractor--> ";
                s1.printString();
                cout<<endl;
                
                cout<< "CTOR from char*--> ";
                s2.printString();
                cout<<endl;
                
                cout<< "copy CTOR--> ";
                s3.printString(); 
                cout<<endl;
                
                break;
            }
                
            case 2:
            {
                stringCompare();
                break; 
            }
            case 3:
            {
                upperConvert();
                break;
            }
            case 4:
            {
                funcPrepend();//char* s
                break;
            }
            case 5:
            {
                //Prepend---> String_t& s
                String_t s1("Pechakr"); 
                String_t s2("Marianna");
                s1.prependFunc(s2);
                s1.printString();
                break;
            }
            case 6:
            {
                char* string = new char[128];
                cout<< "enter string 1\n";
                cin>>string;
                String_t s1(string);
                delete[] string;
                
                cout<< "enter string 2\n";
                cin>>string;
                
                s1.operator+=(string);
                delete[] string;
                cout<< "operator+= result--> " ;
                s1.printString();

                break;
            }
            case 7:
            {
                char* string = new char[128];
                cout<< "enter string 1\n";
                cin>>string;
                String_t s1(string);
                delete[] string;
                
                cout<< "enter string 2\n";
                cin>>string;
                
                bool b = s1.operator>(string);
                delete[] string;
                cout<< "operator> result--> " << b ;

                break;
            }
            case 8:
            {
                char* string = new char[128];
                cout<< "enter string 1\n";
                cin>>string;
                String_t s1(string);
                delete[] string;
                
                cout<< "enter string 2\n";
                cin>>string;
                
                bool b = s1.operator>(string);
                delete[] string;
                cout<< "containsFunc result--> " << b ;

                break;
            }
            case 9:
            {
                unsigned int pos;
                char* string = new char[128];
                cout<< "enter string 1\n";
                cin>>string;
                String_t s1(string);
                delete[] string;
                
                cout<< "enter position \n";
                cin>>pos;
        
                char ch = s1.operator[](pos);
                cout<< "char in position "<<pos << " is: "<<  ch;

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