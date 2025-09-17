//(e) Write a program to convert a character from uppercase to lowercase. 

#include <iostream>
using namespace std;

void changeCase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

int main()
{
    char ch[] = "HeLLo";
    changeCase(ch);
    cout << ch << endl;
}
