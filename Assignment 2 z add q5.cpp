/* Given a fixed-length integer array arr, duplicate each occurrence of two (2), shifting the 
remaining elements to the right.  
Note that elements beyond the length of the original array are not written. Do the above 
modifications to the input array in place and do not return anything.*/

#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int countTwos = 0;

  
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) countTwos++;
    }

    
    for (int i = n - 1; i >= 0; i--) {
        int newPos = i + countTwos;
        
        
        if (arr[i] == 2) {
            if (newPos < n) arr[newPos] = 2;
            countTwos--;
            if (i + countTwos < n) arr[i + countTwos] = 2;
        }
        else {
            if (newPos < n) arr[newPos] = arr[i];
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    duplicateTwos(arr, n);

    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

