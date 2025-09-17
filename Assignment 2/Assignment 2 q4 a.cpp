//(a) Write a program to concatenate one string to another string.

#include <iostream>
using namespace std;


string concat(string s1, string s2) {
    string result = s1;   
    for (int i = 0; s2[i] != '\0'; i++) {
        result += s2[i];  
    }
    return result;
}

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;   

    cout << "Enter second string: ";
    cin >> str2;

    string finalStr = concat(str1, str2);

    cout << "Concatenated String: " << finalStr << endl;

    return 0;
}

