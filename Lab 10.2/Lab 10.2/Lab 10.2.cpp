#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int CountMax(char* word)
{
    int max = 0,i=0;
    while (word[i] != NULL)
    {
        max++;
        i++;
        if (word[i] == '.' || word[i] == ',' || word[i] == '-' || word[i] == '"' || word[i] == '!' || word[i] == '?')
            max = max - 1;
    }
    return max;

}
int main()
{
    char ch;
    char word[101];
    ifstream t;
    t.open("1.txt");
    if (!t.is_open())
    {
        cout << "Файл не відкрито!" << endl;
        return 0;
    }
    int max = 0;
    while (t>>word)
    {
        if (max < CountMax(word))
            max = CountMax(word);
    }

    cout << "Length of the biggest word :" << max;
    t.close();
    return 0;
}


