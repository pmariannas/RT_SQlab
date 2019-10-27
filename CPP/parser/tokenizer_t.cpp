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
    cout<<"__________________________"<<endl;
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

    //--------------------------------
    // int counter = 0;
    // int prev = 0;
    // int lenLine = 0;
    // for (int i = 0; i < line.length(); i++)
    // {
    //     while (isspace(line[i]))
    //     {
    //         i++;
    //     }

    //     prev = i;

    //     while (isalpha(line[i]) || isdigit(line[i]))
    //     {
    //         i++;
    //     }

    //     lenLine = i - prev;

    //     if (lenLine > 0)
    //     {
    //         tokens.push_back(line.substr(prev, lenLine));
    //         counter++;
    //     }
    //     if (!isspace(line[i]) && !isalpha(line[i]))
    //     {
    //         tokens.push_back(line.substr(i, 1));
    //         counter++;
    //     }
    // }
    // //----------------------------------------------------

}

// bool tokenizer_t::isDelimiter(const char *c)
// {
// 	if (isalpha(c[0]) || isdigit(c[0]))
// 		return false;

// 	for (int i = 0; i < 16; i++)
// 	{
// 		if (c[0] == *(delimiters)[i])
// 			return true;
// 	}

// 	return false;
// }

// void tokenizer_t::tokenize(const std::string& str, std::vector<std::string> &tokens)
// {
// 	string tok;

// 	for (int i = 0; i< str.length(); i++)
// 	{
// 		if (!isspace(str[i]))
// 		{
// 			if (!(isDelimiter(&str[i])))
// 			{
// 				tok += str[i];
// 				if (i == str.length() - 1) // if end of line push the token
// 				{
// 					tokens.push_back(tok);
// 				}
// 			}
// 			else
// 			{
// 				if (!tok.empty())
// 				{
// 					tokens.push_back(tok);
// 				}
// 				tok = str[i];
// 				tokens.push_back(tok);
// 				tok = "";
// 			}
// 		}
// 		else
// 		{
// 			if (!tok.empty())
// 			{
// 				tokens.push_back(tok);
// 				tok = "";
// 			}
// 		}
// 	}
// }