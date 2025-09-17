#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string a, string b)
{

    return b.find(a) != string::npos;
}

bool canSplit(string s)
{
    int n = s.length();

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string p1 = s.substr(0, i);
            string p2 = s.substr(i, j - i);
            string p3 = s.substr(j);

            if (isSubstring(p1, p2) && isSubstring(p1, p3))
                return true;
            if (isSubstring(p2, p1) && isSubstring(p2, p3))
                return true;
            if (isSubstring(p3, p1) && isSubstring(p3, p2))
                return true;
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    if (canSplit(s))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
