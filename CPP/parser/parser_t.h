#ifndef PARSER_T_CLASS_H
#define PARSER_T_CLASS_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

class parser_t
{

    public:
        ~parser_t();
        parser_t();

        //void openFile();
        //void readFile();
        //void cleanParser();
    

    private:
        //?<tokenizer_t > tokenContainer;
        //?typedef typename <tokenizer_t >::iterator iter_t;

        parser_t(const parser_t& p);            //copy CTOR
        parser_t &operator=(const parser_t& p); //operator =
};


parser_t::~parser_t()
{
}


parser_t::parser_t()
{
}

#endif