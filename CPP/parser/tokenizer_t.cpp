#include "tokenizer_t.h"
using namespace std;

// void clearTokensContainer(vector<string> tokenContainer)
// {
//     tokenContainer.clear();//removes all the elements from a vector container, thus making its size 0.
// }
// void tokenizer_t::setDelimiters()
// {
//     delimiters = " \n\t\v\f\r(){}[]<>;=+-*&";
// }
// string tokenizer_t::getDelimiters()
// {
//     return delimiters;
// }
void tokenizer_t::printTokens(vector<string> &tokens) const
{
    int i;
    cout << "The tokens:" << endl;
    for (i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << endl;
    }
}

void tokenizer_t::tokenize(const string &line, vector<string> &tokens) const
{
    tokens.clear();
    int sz = line.size() +1;
    char str[sz];

    strcpy(str, line.c_str());

    char *token = strtok(str, " \n\t\v\f\r(){}[]<>;=+-*&");
    int prev_c = 0;
    string tmp;
    while (token != NULL)
    {
        int c = 0;
        c = token - str + strlen(token);
        tokens.push_back(token);
        tmp = line[c];
        for (int d = prev_c; d < token - str; d++)
        {
            tmp = line[d];
            if (tmp != " ")
            {
                tokens.push_back(tmp);
            }
        }
        prev_c = c;
        token = strtok(NULL, " \n\t\v\f\r(){}[]<>;=+-*&");
    }
    for (int d = prev_c; d < strlen(line.c_str()); d++)
    {
        tmp = line[d];
        if (tmp != " ")
        {
            tokens.push_back(tmp);
        }
    }
}
