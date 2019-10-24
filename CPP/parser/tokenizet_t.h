#ifndef TOKENIZER_T_CLASS_H
#define TOKENIZER_T_CLASS_H

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

class tokenizer_t
{

    public:
        ~tokenizer_t();
        tokenizer_t();
        //getTokens();
        //void createTokens(const string& line);

    private:
        vector <string> tokens;                         // Vector of string to save tokens
        tokenizer_t(const tokenizer_t& t);             //copy CTOR
        tokenizer_t &operator=(const tokenizer_t& t); //operator =
};


tokenizer_t::~tokenizer_t()
{
}


tokenizer_t::tokenizer_t()
{
}


void tokenizer_t::createTokens(const string& line)
{	
	// stringstream class check1 
	stringstream check1(line); 
	
	string intermediate; 
	
	while(getline(check1, intermediate, ' ')) 
	{ 
		tokens.push_back(intermediate); 
	} 
}

#endif