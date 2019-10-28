#include "analyzer_t.h"

analyzer_t::analyzer_t()
{
    int i;
    counterRoundBrackets = 0;
    counterCurlyBrackets = 0;
    counterSquareBrackets = 0;
    firstLine = 1;
    lastLine = 0;
    isIf = false;
    // declaredVariabls.push_back("");

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
void analyzer_t::printVector(const vector<string> &v) const
{

    int i;
    for (i = 0; i < v.size(); i++)
    {
        cout << v[i] << "   ";
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
    if (lineNumber == 1 && firstLine == true)
    {
        string currToken = tokenContainer[0];
        firstLine = false;
        int ans = currToken.compare("main");
        if (ans != 0)
        {
            cout << "Error in line: " << lineNumber << " , "
                 << "no main before" << endl;
        }
    }
    for (i = 0; i < tokenContainer.size(); i++)
    {
        if (tokenContainer.size() == 1) //if size container 1
        {
            string lastElement = tokenContainer[i];
            string st = lastElementInContainer(lastElement);
            if (st != "OK")
            {
                cout << "Error in line: " << lineNumber << " , " << st << endl;
            }
        }
        else
        {
            int nextIndex = i + 1;
            if (nextIndex < tokenContainer.size())
            {
                string currToken = tokenContainer[i];
                string nextToken = tokenContainer[nextIndex];

                if (isIf == false)
                {
                    if (currToken == "if")
                        isIf = true;
                }

                string st = check2Tokens(currToken, nextToken);
                if (st != "OK")
                {
                    cout << "Error in line: " << lineNumber << " , " << st << endl;
                }
            }
            else //the last param in vector
            {
                //if the last element in container
                string lastElement = tokenContainer[i];
                string st = lastElementInContainer(lastElement);
                if (st != "OK")
                {
                    cout << "Error in line: " << lineNumber << " , " << st << endl;
                }
            }
        }
    }
}

string analyzer_t::lastElementInContainer(string lastElement)
{

    if (isKeyWord(lastElement) && lastElement == "else" && isIf == false) //not decla
    {
        return "else without if";
    }
    else if (isDelimeters(lastElement) && (lastElement == "+" || lastElement == "-" || lastElement == "="))
    {
        if (checkCorrectPlusMinusEqual(lastElement) == false)
        {
            return "no operator ";
        }
        return "OK";
    }
    else if (isPredType(lastElement) == true)
    {
        return "multiple type declaration";
    }
    else
    {
        return "OK";
    }
}

string analyzer_t::check2Tokens(string currToken, string nextToken)
{
    iter_t it;

    //check if token is type like int or float
    if (isPredType(currToken) == true)
    {
        if (isPredType(nextToken) == true)
        {
            return "multiple_type_declaration"; //error multiple type declaration
        }
        else if (!isalpha(nextToken.at(0)))
        {
            return "illegal variable";
        }

        else
        {
            if (isDeclared(nextToken))
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

    if (isKeyWord(currToken))
    {
        if (currToken == "else")
        {
            if (isIf == false)
            {
                return "else without if";
            }
        }
    }
    //count
    if (isDelimeters(currToken) && (currToken == "+" || currToken == "-" || currToken == "="))
    {
        if (checkCorrectPlusMinusEqual(currToken) == false)
        {
            return "no operator";
        }
    }
    if (isDelimeters(currToken))
    {
        if (currToken == "(" || currToken == ")" || currToken == "{" || currToken == "}" || currToken == "[" || currToken == "]" || currToken == "<" || currToken == ">")
        {
            string mymsg;
            mymsg = incDecCounters(currToken);
            return mymsg;
        }
    }

    return "OK";
    //--------------------------------------------------------
}

void analyzer_t::setFlag(string token)
{
    if (token == "if")
    {
        isIf = true;
    }
}

bool analyzer_t::isLegalVar(string token)
{
    if (!(isalpha(token.at(0))))
    {
        return false;
    }
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
    iter_t it;
    it = find(delimeters.begin(), delimeters.end(), token);

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
    iter_t it;
    it = find(declaredVariabls.begin(), declaredVariabls.end(), token);

    if (it != declaredVariabls.end()) //
    {
        return true; //find - already declared
    }
    else
    {
        false;
    }
}

string analyzer_t::incDecCounters(string token)
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
    // else if(token == "<")
    // {

    // }
    // else if( token == ">")
    // {

    // }

    if (counterRoundBrackets < 0)
    {
        counterRoundBrackets = 0;
        return "illegal '(' has to be before ')'";
    }
    else if (counterCurlyBrackets < 0)
    {
        counterCurlyBrackets = 0;
        return "illegal '{' has to be before '}'";
    }
    else if (counterSquareBrackets < 0)
    {
        counterSquareBrackets = 0;
        return "illegal '[' has to be before ']'";
    }

    return "OK";
}

void analyzer_t::statusOfBrackets()
{
    if (counterRoundBrackets != 0)
    {
        if (counterRoundBrackets > 0)
        {
            for (int i = 0; i < counterRoundBrackets; i++)
            {
                cout << " ( NOT closed" << endl;
            }
        }
    }
    if (counterCurlyBrackets != 0)
    {
        if (counterCurlyBrackets > 0)
        {
            for (int i = 0; i < counterCurlyBrackets; i++)
            {
                cout << " { NOT closed" << endl;
            }
        }
    }
    if (counterSquareBrackets != 0)
    {

        if (counterSquareBrackets > 0)
        {
            for (int i = 0; i < counterSquareBrackets; i++)
            {
                cout << " [ NOT closed" << endl;
            }
        }
    }
    clearCounters();
    declaredVariabls.clear();
}

bool analyzer_t::checkCorrectPlusMinusEqual(string token)
{
    if (token == "+")
    {

        if (counterPlus >= 2)
        {
            counterPlus == 0;
            return false;
        }
        else
        {
            counterMinus = 0;
            counterEqual = 0;
            counterPlus++;
        }
    }
    else if (token == "-")
    {
        if (counterMinus >= 2)
        {
            counterMinus == 0;
            return false;
        }
        else
        {
            counterEqual = 0;
            counterPlus = 0;
            counterMinus++;
        }
    }
    else if (token == "=")
    {
        if (counterEqual >= 2)
        {
            counterEqual = 0;
            return false;
        }
        else
        {
            counterMinus = 0;
            counterPlus = 0;
            counterEqual++;
        }
    }
    return true;
}

void analyzer_t::clearCounters()
{

    isIf = 0;
    firstLine = 1;

    //COUNTERS
    counterRoundBrackets = 0;  //()
    counterCurlyBrackets = 0;  //{}
    counterSquareBrackets = 0; //[]
    counterPlus = 0;           //+
    counterMinus = 0;          //-
    counterEqual = 0;
}