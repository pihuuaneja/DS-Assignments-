#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool inc){
    int extreme = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(inc){ // increasing ? max heap
        if(l < n && arr[l] > arr[extreme]) extreme = l;
        if(r < n && arr[r] > arr[extreme]) extreme = r;
    }
    else{ // decreasing ? min heap
        if(l < n && arr[l] < arr[extreme]) extreme = l;
        if(r < n && arr[r] < arr[extreme]) extreme = r;
    }

    if(extreme != i){
        int temp = arr[i];
        arr[i] = arr[extreme];
        arr[extreme] = temp;
        heapify(arr, n, extreme, inc);
    }
}

void heapSort(int arr[], int n, bool inc){
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, inc);

    for(int i = n - 1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0, inc);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "Increasing order: ";
    heapSort(arr, n, true);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Decreasing order: ";
    heapSort(arr, n, false);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

