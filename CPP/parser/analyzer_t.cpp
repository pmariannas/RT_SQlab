#include "analyzer_t.h"

analyzer_t::analyzer_t()
{
    int i;
    //ifElseFlag = true;
    counterRoundBrackets = 0;
    counterCurlyBrackets = 0;
    counterSquareBrackets = 0;
    firstLine = 1;


    string pt[] = {"char", "short", "int", "long", "float", "double", "void"};
    string kw[] = {"if", "else", "for", "while", "class", "private", "public", "protected", "main", "const", "virtual"};
    string op[] = {"++", "--", "==", "->", "=", "+", "-", "*", "&", "<<", ">>"};
    string dl[] = {"(", ")", "{", "}", "[", "]", "<", ">", ";", "=", "+", "-", "*", "&"};       
    
    for (i = 0; i < sizeof(pt) / sizeof(string); i++)
    {
        predTypes.push_back(pt[i]);
    }
    for (i = 0; i < sizeof(kw) / sizeof(string); i++)
    {
        keyWords.push_back(kw[i]);
    }
    for (i = 0; i < sizeof(op) / sizeof(string); i++)
    {
        tOperators.push_back(op[i]);
    }
    for (i = 0; i < sizeof(dl) / sizeof(string); i++)
    {
        delimeters.push_back(dl[i]);
    }
}

// void analyzer_t::setRules()
// {
//     string predTypes[] = {"char", "short", "int", "long", "float", "double", "void"};
//     string keyWords[] = {"if", "else", "for", "while", "class", "private", "public", "protected", "main", "const", "virtual"};
//     string tOperators[] = {"++", "--", "==", "->", "=", "+", "-", "*", "&", "<<", ">>"};
//     string delimeters[] = {"(", ")", "{", "}", "[", "]", "<", ">", ";", "=", "+", "-", "*", "&"};
// }

void analyzer_t::analyze(vector<string> &tokenContainer, size_t lineNumber)
{
    int i;
    for (i = 0; i < tokenContainer.size(); i++)
    {
        int nextIndex = i + 1;
        if (nextIndex < tokenContainer.size())
        {
            string currToken = tokenContainer[i];
            string nextToken = tokenContainer[nextIndex];
            
            if (lineNumber == 1 && firstLine == true)
            {
                firstLine = false;
                int ans = currToken.compare("main");
                if (ans != 0)
                {
                    cout << "Error in line: " << lineNumber << " , "
                         << "no main before" << endl;
                }
            }

            string st = check2Tokens(currToken, nextToken);
            if (st != "OK")
            {
                cout << "Error in line: " << lineNumber << " , " << st << endl;
            }
        }
    }
}

string analyzer_t::check2Tokens(string currToken, string nextToken)
{
    iter_t it;
    //check if token is type like int or float
    bool ans = isPredType(currToken);
    if (ans == true)
    {
        ans = isPredType(nextToken);
        if (ans == true)
        {
            return "multiple_type_declaration"; //error multiple type declaration
        }
        else
        {
            ans = isDeclared(nextToken);
            if (ans == true)
            {
                return "variable_already_declared";
            }
            else
            {
                declaredVariabls.push_back(nextToken);
                return "OK";
            }
        }
    }

    if (isKeyWord(currToken) == true)
    {
        if (isKeyWord(nextToken) == true)
        {
            if (currToken == "if" && nextToken == "else")
            {
                return "OK";
            }
            else
            {
                return "illegal used key words!";
            }
        }
    }
    return "OK";
    //--------------------------------------------------------
}

bool analyzer_t::isKeyWord(string token)
{
    iter_t it = find(keyWords.begin(), keyWords.end(), token);

    if (it != keyWords.end()) //find
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool analyzer_t::isPredType(string token)
{
    iter_t it = find(predTypes.begin(), predTypes.end(), token);

    if (it != predTypes.end()) //find
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool analyzer_t::isOperator(string token)
{
    iter_t it = find(tOperators.begin(), tOperators.end(), token);

    if (it != tOperators.end()) //find
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool analyzer_t::isDelimeters(string token)
{
    iter_t it = find(delimeters.begin(), delimeters.end(), token);

    if (it != delimeters.end()) //find
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool analyzer_t::isDeclared(string token)
{
    //check if already declared
    iter_t it = find(declaredVariabls.begin(), declaredVariabls.end(), token);
    if (it != tOperators.end()) //find
    {
        return true; //already declared
    }
    else
    {
        false;
    }
}

void analyzer_t::incDecCounters(string token)
{
    if (token == "(")
    {
        counterRoundBrackets++;
    }
    else if (token == ")")
    {
        counterRoundBrackets--;
    }
    else if (token == "{")
    {
        counterCurlyBrackets++;
    }
    else if (token == "}")
    {
        counterCurlyBrackets--;
    }
    else if (token == "[")
    {
        counterSquareBrackets++;
    }
    else if (token == "]")
    {
        counterSquareBrackets--;
    }
}

// bool analyzer_t::onOffIfElseFlag(string token)
// {
//     // if(token =="if")
//     // {
//     //     counterIfElse++;
//     // }
//     // else if(token == "else")
//     // {
//     //     if (counterIfElse == 0)
//     //     {
//     //         return false;
//     //     }
//     //     else
//     //     {
//     //         counterIfElse--;
//     //     }
//     // }
//     // return true
// }