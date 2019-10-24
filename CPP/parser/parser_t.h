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
        ~parser_t(){closeFile();} //must close file and delete new
        parser_t();
        
        void openFile(const string& filename)
        {
            m_file.open(filename);
        }

        void closeFile()
        {
            m_file.close();
        }

        void parseFunction()
        {
            size_t lineNumber=1;
            string fileLine;
            while(getline (m_file,fileLine))
            {
                tokenContainer=m_tokenizer.tokenize(fileLine);
                m_analyzer.analyze(tokenContainer,lineNumber);
                lineNumber++;
            
            }
        }
        //void cleanParser();
    

    private:
        vector <string>& tokenContainer;
        tokenizer_t m_tokenizer;
        analyzer_t m_analyzer;
        ifstream m_file;
        
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