#ifndef ANALYZER_T_CLASS_H
#define ANALYZER_T_CLASS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class analyzer_t
{

    public:
        ~analyzer_t();
        analyzer_t();
    

    private:
        vector <string> predTypes; // = {'char', 'short', 'int', 'long', 'float', 'double', 'void'};
        vector <string> keyWords; // = {'if', 'else', 'for', 'while', 'class', 'private', 'public', 'protected' ,'main', 'const', 'virtual'}; 
        vector <char> operators; // = {'++', '--', '==', '->' , '=', '+', '-', '*', '&', '<<', '>>'};
        vector <char> delimiterTokens; // = {'(', ')', '{', '}', '[', ']', '<', '>', ';', '=', '+', '-', '*', '&'};

        analyzer_t(const analyzer_t& a);            //copy CTOR
        analyzer_t &operator=(const analyzer_t& a); //operator =
};


analyzer_t::~analyzer_t()
{
}


analyzer_t::analyzer_t()
{
}

#endif