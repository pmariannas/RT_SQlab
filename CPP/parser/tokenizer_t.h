#ifndef TOKENIZER_T_CLASS_H
#define TOKENIZER_T_CLASS_H

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h> // Tokenizing a string using stringstream

using namespace std;

class tokenizer_t
{

public:
    ~tokenizer_t() {} //DTOR
    tokenizer_t() {}  //CTOR
    // void clearTokensContainer(vector<string> tokenContainer)
    // {
    //     tokenContainer.clear();//removes all the elements from a vector container, thus making its size 0.
    // }
    void printTokens(vector<string> &tokens)
    {
        int i;
        cout << "The tokens:" << endl;
        for (i = 0; i < tokens.size(); i++)
        {
            cout << tokens[i] << endl;
        }
    }

    void tokenize(const string &line, vector<string> &tokens)
    {
        // tokens.clear();
        // char str[line.size() + 1];

        // strcpy(str, line.c_str());

        // char *token = strtok(str, " \n\t\v\f\r(){}[]<>;=+-*&");
        // int prev_c = 0;
        // string tmp;
        // while (token != NULL)
        // {
        //     int c = 0;
        //     c = token - str + strlen(token);
        //     tokens.push_back(token);
        //     tmp = line[c];
        //     for (int d = prev_c; d < token - str; d++)
        //     {
        //         tmp = line[d];
        //         if(tmp!=" ")
        //         {tokens.push_back(tmp);}
        //     }
        //     prev_c = c;
        //     token = strtok(NULL, " \n\t\v\f\r(){}[]<>;=+-*&");
        // }
        // for (int d = prev_c; d < strlen(line.c_str()); d++)
        // {
        //     tmp = line[d];
        //     if (tmp != " ")
        //     {
        //         tokens.push_back(tmp);
        //     }
        // }


        //--------------------------------
        int counter = 0;
        int prev = 0;
        int lenLine = 0;
        for (int i = 0; i < line.length() ; i++)
        {
            while (isspace(line[i]))
            {
                i++;
            }

            prev = i;

            while (isalpha(line[i]) || isdigit(line[i]))
            {
                i++;
            }

            lenLine = i - prev;

            if (lenLine > 0)
            {
                tokens.push_back(line.substr(prev, lenLine));
                counter++;
            }
            if (!isspace(line[i]) && !isalpha(line[i]))
            {
                tokens.push_back(line.substr(i, 1));
                counter++;
            }
        }
        //----------------------------------------------------

    }

private:
    //vector<string> tokens; // Vector of string to save tokens
    // char delimiters[] = {' ', '\n', '\t', '\v', '\f', '\r', '(', ')', '{', '}', '[', ']', '<', '>', ';', '=', '+', '-', '*', '&'}; //delimiter between tokens
    tokenizer_t(const tokenizer_t &t);            //copy CTOR
    tokenizer_t &operator=(const tokenizer_t &t); //operator =
};

#endif