//(c) Write a program to delete all the vowels from the string. 

#include <iostream>
using namespace std;

string removeVowels(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        
        if (!(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
              ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')) {
            result += ch;  
        }
    }
    return result;
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;  

    string noVowels = removeVowels(str);

    cout << "String without vowels: " << noVowels << endl;

    return 0;
}



