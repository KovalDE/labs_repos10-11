#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int Count(char* str)
{
    if (strlen(str) < 3)
        return 0;
    int k = 0;
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == '+' || str[i] == '-' || str[i] == '=')
            k++;
    return k;
}
int main()
{
    char ch;
    char str[101];
    ifstream t;
    t.open("1.txt");
    if (!t.is_open())
    {
        cout << "Файл не відкрито!" << endl;
        return 0;
    }
    int i = 0;
    while (!t.eof())
    {
        t >> str;
        if (!t)
            break;
    }
    cout << endl;
    cout << "Count +,-,= :" << Count(str);
    t.close();
}


