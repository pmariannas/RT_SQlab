#ifndef PARSER_T_CLASS_H
#define PARSER_T_CLASS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class tokenizer_t;
class analyzer_t;

class parser_t
{
public:
    parser_t();
    ~parser_t();

    void parseFunction(const char* filePath);

private:
    tokenizer_t* m_tokenizer;
    analyzer_t* m_analyzer;
    std::vector<std::string> tokenContainer;
    
    parser_t(const parser_t &p);            //copy CTOR
    parser_t &operator=(const parser_t &p); //operator =
};

#endif