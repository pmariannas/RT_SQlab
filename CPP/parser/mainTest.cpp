#include "parser_t.h"
#include "tokenizer_t.h"
#include "analyzer_t.h"

int main(int argc, char **argv)
{
    parser_t parser;
    // cout << "HELLO TO PARSER!" << endl;
    // try
    // {
    //     parser.parseFunction("11_Parser_qq.txt");
    // }
    // catch (const char* e)
    // {
    //     cout << e << endl;
    // }


    for(int i = 1; i < argc; i++)
    {
        try
        {
            parser.parseFunction(argv[i]);
        }
        catch(const char* e)
        {
            cout << e << endl;
        }
    }


    return 0;
}