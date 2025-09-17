//(b) Write a program to reverse a string. 

#include <iostream>
using namespace std;


string reverseStr(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        // swap characters
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    return s;
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;   

    string rev = reverseStr(str);

    cout << "Reversed String: " << rev << endl;

    return 0;
}


