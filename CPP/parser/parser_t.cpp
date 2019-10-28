#include "parser_t.h"

#include "tokenizer_t.h"
#include "analyzer_t.h"

using namespace std;

parser_t::parser_t()
{
    m_tokenizer = new tokenizer_t;
    m_analyzer = new analyzer_t; 
}

parser_t::~parser_t()
{
    delete m_analyzer;
    delete m_tokenizer;
}

void parser_t::parseFunction(const char *filePath)
{
    size_t lineNumber = 1;
    string fileLine;
    ifstream m_file(filePath);

    if (m_file.is_open())
    {
        while (getline(m_file, fileLine) > 0)
        {
            m_tokenizer->tokenize(fileLine, tokenContainer);
            //m_tokenizer->printTokens(tokenContainer);
            m_analyzer->analyze(tokenContainer, lineNumber);
            lineNumber++;
        }
        m_analyzer->statusOfBrackets();
        m_file.close();
    }
    else
    {
        throw("unable to open this file!");
    }
}
