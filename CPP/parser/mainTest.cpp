#include "parser_t.h"
#include "tokenizer_t.h"
#include "analyzer_t.h"

int main()
{
    parser_t parser;
    cout<<"HELLO TO PARSER!"<<endl;
    
    parser.parseFunction("parserFile.txt");   
    return 0;
}