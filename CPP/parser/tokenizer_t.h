#ifndef TOKENIZER_T_CLASS_H
#define TOKENIZER_T_CLASS_H

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h> // Tokenizing a string using stringstream



class tokenizer_t
{

public:
    ~tokenizer_t() {} //DTOR
    	tokenizer_t(): m_tokensDelimiters("()[]{};<>=+-*&"),m_blankDelimiters(" \n\t\v\f\r") {};//CTOR
    
    void printTokens(std::vector<std::string> &tokens)const;

    void tokenize(const std::string &line, std::vector<std::string> &tokens)const;
    
    // std::string getDelimiters();
    // void setDelimiters();

private:
    const std::string m_tokensDelimiters;
	const std::string m_blankDelimiters;

    //std::string delimiters;    
    //vector<string> tokens; // Vector of string to save tokens
    // char delimiters[] = {' ', '\n', '\t', '\v', '\f', '\r', '(', ')', '{', '}', '[', ']', '<', '>', ';', '=', '+', '-', '*', '&'}; //delimiter between tokens
    tokenizer_t(const tokenizer_t &t);            //copy CTOR
    tokenizer_t &operator=(const tokenizer_t &t); //operator =
};

#endif