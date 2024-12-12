#include <iostream>
using namespace std;

class Heap {
    int arr[20]; 
    int n;       

public:
    
    void input() {
        cout << "Enter the number of elements: ";
        cin >> n;
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    
    void heapify(int size, int i) {
        int largest = i;       
        int left = 2 * i + 1;  
        int right = 2 * i + 2; 

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(size, largest);
        }
    }

    
    void sort() {
        
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(n, i);
        }

        
        for (int i = n - 1; i > 0; i--) {
            
            swap(arr[0], arr[i]);

            heapify(i, 0);
        }
    }

    
    void display() {
        cout << "The sorted array is: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap heap;
    heap.input();
    heap.sort();
    heap.display();
    return 0;
}
