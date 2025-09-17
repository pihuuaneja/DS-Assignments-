#include <iostream>
#include <string>
using namespace std;

string alphabetical(string str)
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
    return str;
}
bool isAnagram(string str1, string str2)
{
    if (alphabetical(str1) == alphabetical(str2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    string str1 = "show";
    string str2 = "hsow";

    cout << isAnagram(str1, str2);
}
