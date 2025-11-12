#include<iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int val) {
        arr[size] = val;
        int i = size;
        size++;
        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            int temp = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }

    void heapify(int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && arr[l] > arr[largest]) largest = l;
        if (r < size && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(largest);
        }
    }

    int getMax() {
        if (size == 0) {
            cout << "Empty\n";
            return -1;
        }
        return arr[0];
    }

    void removeMax() {
        if (size == 0) {
            cout << "Empty\n";
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }

    void display() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(10);
    pq.insert(40);
    pq.insert(20);
    pq.insert(30);
    pq.insert(50);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Max element: " << pq.getMax() << endl;

    pq.removeMax();
    cout << "After removing max: ";
    pq.display();
}

