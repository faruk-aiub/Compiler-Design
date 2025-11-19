#include <iostream>
#include <fstream>
using namespace std;

bool isOperatorChar(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '=' ||
           c == '<' || c == '>' || c == '%';
}

bool isPunctuationChar(char c)
{
    return c == '(' || c == ')' || c == '{' || c == '}' ||
           c == '[' || c == ']' || c == ';' || c == ',';
}

bool isKeyword(string token)
{
    if (token == "int" || token == "float" || token == "double" ||
        token == "char" || token == "return" || token == "void" ||
        token == "if" || token == "else" || token == "while" ||
        token == "for" || token == "break" || token == "continue" ||
        token == "long" || token == "short" || token == "unsigned" ||
        token == "signed" || token == "bool" || token == "true" ||
        token == "false" || token == "class" || token == "struct" ||
        token == "public" || token == "private" || token == "include" ||
        token == "using" || token == "namespace" || token == "main")
        return true;

    return false;
}

bool isNumber(string token)
{
    for (int i = 0; i < token.length(); i++)
        if (!isdigit(token[i]))
            return false;
    return true;
}

string classify(string token)
{
    if (isKeyword(token))
        return "Keyword";
    if (isNumber(token))
        return "Number";
    return "Identifier";
}

int main()
{
    ifstream file("tokenization.txt");

    if (!file.is_open())
    {
        cout << "File not found!" << endl;
        return 0;
    }

    cout << "Token\t\tType\n";
    cout << "---------------------------\n";

    char c;
    string token = "";

    while (file.get(c))
    {
        if (!isspace(c) && !isOperatorChar(c) && !isPunctuationChar(c))
        {
            token += c;
        }
        else
        {
            if (token != "")
            {
                cout << token << "\t\t" << classify(token) << endl;
                token = "";
            }

            if (isOperatorChar(c))
                cout << c << "\t\tOperator\n";

            if (isPunctuationChar(c))
                cout << c << "\t\tPunctuation\n";
        }
    }

    if (token != "")
        cout << token << "\t\t" << classify(token) << endl;

    return 0;
}
