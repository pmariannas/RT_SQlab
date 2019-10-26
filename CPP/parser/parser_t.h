#ifndef PARSER_T_CLASS_H
#define PARSER_T_CLASS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "tokenizer_t.h"
#include "analyzer_t.h"

using namespace std;

class parser_t
{
public:
    parser_t(){ }
    ~parser_t(){ }

    void parseFunction(const char* filePath)
    {
        size_t lineNumber = 1;
        string fileLine;
        ifstream m_file(filePath);

        if (m_file.is_open())
        {
            while (getline(m_file, fileLine))
            {
                m_tokenizer.tokenize(fileLine,tokenContainer);
                m_tokenizer.printTokens(tokenContainer);
                m_analyzer.analyze(tokenContainer , lineNumber);
                lineNumber++;
            }

            m_file.close();
        }
        throw("unable to open this file!");
    }


private:
    tokenizer_t m_tokenizer;
    analyzer_t m_analyzer;
    vector<string> tokenContainer;

    typedef typename vector<string>::iterator iter_t;
    
    parser_t(const parser_t &p);            //copy CTOR
    parser_t &operator=(const parser_t &p); //operator =
};

// parser_t::parser_t(/* args */)
// {
// }

// parser_t::~parser_t()
// {
// }

#endif