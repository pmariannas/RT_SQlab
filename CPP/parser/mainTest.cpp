#include "parser_t.h"
#include "tokenizer_t.h"
#include "analyzer_t.h"

int main()
{
    parser_t parser;
    cout << "HELLO TO PARSER!" << endl;
    try
    {
        parser.parseFunction("11_Parser_qq.txt");
    }
    catch (const char* e)
    {
        cout << e << endl;;
    }

    return 0;
}