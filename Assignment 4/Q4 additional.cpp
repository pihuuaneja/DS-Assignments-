#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeatingChar(string str)
{
    unordered_map<char, int> freq;
    queue<char> q;

    for (char ch : str)
    {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << "-1 ";
    }
}

int main()
{
    string str = "aabc";
    firstNonRepeatingChar(str);
    return 0;
}
