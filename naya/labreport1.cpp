#include <iostream>
using namespace std;

// Function to reverse the array using a pointer
void reverseArray(int *arr, int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    // Dynamically allocate memory for the array
    int *arr = new int[n];

    // Take input elements
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Reverse the array
    reverseArray(arr, n);

    // Print reversed array
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] arr;

    return 0;
}