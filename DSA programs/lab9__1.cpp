#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
      
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arrSelection[size], arrInsertion[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arrSelection[i];
        arrInsertion[i] = arrSelection[i]; 
    }

    selectionSort(arrSelection, size);
    cout << "Sorted array using Selection Sort: ";
    for (int i = 0; i < size; ++i) {
        cout << arrSelection[i] << " ";
    }
    cout << endl;
    insertionSort(arrInsertion, size);
    cout << "Sorted array using Insertion Sort: ";
    for (int i = 0; i < size; ++i) {
        cout << arrInsertion[i] << " ";
    }
    cout << endl;

    return 0;
}
