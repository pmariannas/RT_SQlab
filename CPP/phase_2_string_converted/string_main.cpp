#include "string_t.h"
#include <iostream>

using namespace std;

int main() { 

    int i = 1;
    String_t str1;
    String_t str2;
    String_t str3;
    while(i)
    {
        cout << "Choose option: \n" << endl;
        cout << "1 - SET String\n" << "2 - GET String \n" << "3 - LENGHT String\n" 
            << "4 - COMPARE String\n" << "5 - PRINT STRING  \n" << "6 - exit\n" 
            <<endl;
        cin >> i;
        switch (i) {
            case 1: 
                
                str1.setString("Marianna");
                str2.setString("Pechkar");
                str3.setString("Marianna");
                
                break;              
            case 2: 
                if(str1.getString()!=NULL ||str2.getString()!=NULL ||str3.getString()!=NULL)
                {
                    cout<< "first string:" << str1.getString() << endl; 
                    cout<< "second string:" << str2.getString() << endl;
                }
                else
                    cout << "set string before get\n"<<endl;
                    
                break;              
            case 3: 

                if(str1.getString()!=NULL ||str2.getString()!=NULL ||str3.getString()!=NULL)
                {
                    cout<< "first string length:" << str1.lengthString() << endl;
                    cout<< "second string length:" << str2.lengthString() << endl;
                }
                else
                    cout << "set string before \n"<<endl;
                break;              
            case 4: 
                if(str1.getString()!=NULL ||str2.getString()!=NULL ||str3.getString()!=NULL)
                    {
                        str1.printString();
                        str2.printString();
                        cout<< "compare:  " << str1.compareString(str2) << endl;
                        str1.printString();
                        str3.printString();
                        cout<< "compare:  " << str1.compareString(str3) << endl;

                    }
                else
                    cout << "set string before \n"<<endl;
                break;              
            case 5: 
                if(str1.getString()!=NULL ||str2.getString()!=NULL ||str3.getString()!=NULL)
                {
                    str1.printString();
                    str2.printString();
                }
                else
                    cout << "set string before \n"<<endl;
                break;              
            case 6: 
                i = 0;
                break; 
            case 7: 
                convertUpper();
                break;             
                }

    }
    
    str1.~String_t();
    str2.~String_t();
    str3.~String_t();
 
 
    return 0; 
} 