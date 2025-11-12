#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void identifier(const string& str)
{

    if ((str[0] >= 'A' && str[0] <= 'Z') ||
        (str[0] >= 'a' && str[0] <= 'z') ||
        (str[0] == '_'))
    {
        bool valid = true;
        for (int i = 1; i < str.length(); i++)
        {
            if (!((str[i] >= 'A' && str[i] <= 'Z') ||
                  (str[i] >= 'a' && str[i] <= 'z') ||
                  (str[i] >= '0' && str[i] <= '9') ||
                  (str[i] == '_') ||
                  (str[i] == ' '))) 
            {
                valid = false;
                break;
            }
        }

        if (valid)
            cout << "'" << str << "' is a valid identifier." << endl;
        else
            cout << "'" << str << "' is not a valid identifier." << endl;
    }
    else
    {
        cout << "'" << str << "' is not a valid identifier." << endl;
    }
}

int main()
{
    ifstream file("input.txt");  
    string word;
    getline(file, word); 
    file.close();

    identifier(word); 

    return 0;
}
