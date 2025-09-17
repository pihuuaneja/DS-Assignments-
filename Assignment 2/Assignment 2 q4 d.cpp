//(d) Write a program to sort the strings in alphabetical order.

#include <iostream>
using namespace std;
void lowerCase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
                }
    }
}
void alphabetical(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    int len = count;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (str[i] > str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
int main()
{
    char str[] = "Hello";
    lowerCase(str);
    alphabetical(str);

    cout << "Sorted string: " << str << endl;
}
