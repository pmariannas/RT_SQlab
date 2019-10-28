#ifndef ANALYZER_T_CLASS_H
#define ANALYZER_T_CLASS_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class analyzer_t
{

public:
    ~analyzer_t(){};
    analyzer_t();

    void analyze(vector<string> &tokenContainer, size_t lineNumber);
    //void setRules();
    void printVector(const vector<string> &v) const;
void statusOfBrackets();
private:

    void clearPlusMinus() { counterPlus = 0; counterMinus = 0; }
    void clearCounters();



    string check2Tokens(string currToken, string nextToken);
    bool isPredType(string token);
    bool isKeyWord(string token);
    bool isOperator(string token);
    bool isDelimeters(string token);
    bool isDeclared(string token);

    string incDecCounters(string token);
    void setFlag(string token);
    bool checkCorrectPlusMinusEqual(string token);
    string lastElementInContainer(string lastElement);
    bool isLegalVar(string token);
    string isMain(string currToken);



    // bool onOffIfElseFlag(string token);

    //DATA MEMBERS
    vector<string> predTypes;  // {"char", "short", "int", "long", "float", "double", "void"};
    vector<string> keyWords;   // = {"if", "else", "for", "while", "class", "private", "public", "protected" ,"main", "const", "virtual"};
    vector<string> tOperators; // = {"++", "--", "==", "->" , "=", "+", "-", "*", "&", "<<", ">>" };
    vector<string> delimeters;
    vector<string> declaredVariabls;

    //FLAGS
    //bool ifElseFlag;
    // bool roundBracketsFlag;  //()
    // bool curlyBracketsFlag;  //{}
    // bool squareBracketsFlag; //[]
    bool isIf;
    bool firstLine;
    bool lastLine;

    //COUNTERS
    int counterRoundBrackets;  //()
    int counterCurlyBrackets;  //{}
    int counterSquareBrackets; //[]
    size_t counterPlus;           //+
    size_t counterMinus;          //-
    size_t counterEqual;          //=
    //ITERATORS
    typedef typename vector<string>::iterator iter_t;
    typedef typename vector<string>::const_iterator citer_t;

    //NON COPYBLE
    analyzer_t(const analyzer_t &a);            //copy CTOR
    analyzer_t &operator=(const analyzer_t &a); //operator =
};

#endif

// typedef enum Status
// {
//     legal,
//     no_main_before,
//     illegal_declaration_before_main,
//     multiple_type_declaration,
//     isnt_defined,
//     no_operator,
//     illigal_operator,
//     variable_already_declared,
//     not_declared,
//     braces_error,
//     not_key_word
// } Status;