// #include "parser_t.h"

// parser_t::~parser_t() //DTOR
// {
// }

// parser_t::parser_t() //CTOR
// {
// }



// void parser_t::parseFunction(const string &fileName)
// {
//     size_t lineNumber = 1;
//     string fileLine;
//     ifstream m_file(fileName);
//     if (m_file.open())
//     {
//         while (getline(m_file, fileLine))
//         {
//             tokenContainer = m_tokenizer.tokenize(fileLine);
//             m_analyzer.analyze(tokenContainer, lineNumber);
//             lineNumber++;
//         }

//         m_file.close();
//     }
//     throw ("unable open this file!");
// }
