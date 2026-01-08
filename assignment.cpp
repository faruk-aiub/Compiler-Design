#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str;
    cout << "Enter a string: ";
    cin >> str;

    int pos = 0;
    int n = str.size();
    bool isValid = true;

    for ( ;pos < n && str[pos] == 'b'; pos++)
        ;

    if (pos < n && str[pos] == 'a')
    {
        pos++;
    }
    else
    {
        isValid = false;
    }

    while (pos < n && isValid)
    {

        if (str[pos] == 'a')
        {
            pos++;
        }
        else if (str[pos] == 'b')
        {

            if (pos + 1 < n && str[pos + 1] == 'a')
            {
                pos += 2;

                if (pos < n && (str[pos] == 'a' || str[pos] == 'b'))
                {
                    pos++;
                }
            }
            else
            {
                isValid = false;
            }
        }
        else
        {
            isValid = false;
        }
    }

    cout << ((isValid && pos == n) ? "String ACCEPTED" : "String REJECTED") << endl;

    return 0;
}
