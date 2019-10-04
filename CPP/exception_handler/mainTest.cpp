#include <string>
#include <iostream>
#include "TException_t.h"

using namespace std; 

int main()
{

    try
    {
        throw TException_t<string>("MY TRY ERROR 000",__FILE__, __LINE__ , "ERROR");
    }
    catch(const TException_t<string>& e)
    {
        cout<< e.getException() << endl
            << e.getMessage() << endl
            << e.getLineOfException() << endl
            << e.getFileName() << endl;
    }

    

    // try
    // {
    //     throw TException_t<int>(777,__FILE__, __LINE__ , "ERROR");
    // }
    // catch(const TException_t<int>& e)
    // {
    //     cout<< e.getException() << endl
    //         << e.getMessage() << endl
    //         << e.getLineOfException() << endl
    //         << e.getFileName() << endl;
    // }
    
    return 0;
}