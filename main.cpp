#include <iostream>
#include <algorithm>

using namespace std;


int getArrayElements() {
    int numElements;

    cout << "How many elements should the array be? (50 or less):" << endl;
    cin >> numElements;

    if (numElements >= 50 || numElements <= 0) {
        throw invalid_argument("Array elements must be less than or equal to 50.");
    } else {
        return numElements;
    }
}

int *makeArray(int numElements) {
    int* ptr = new int[numElements](); // initiate all index's to 0

    return ptr;
}

void allocateArray(int arr[], int numElements) {
    for (int count = 0; count < numElements; count++) {
        cout << "What is the value for index " << count << endl;
        cin >> *(arr + count);
    }
}

void getKey(int &key) {
    cout << "what integer are you searching for?" << endl;
    cin >> key;
}

void selectionSort(int arr[], int numElements) {
    for (int i = 0; i < numElements - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < numElements; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == key)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < key)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }
    // If we reach here, then element was not present
    return -1;
}

float mean(const int *arr, int numElements) {
    float total = 0;

    for (int i = 0; i < numElements; i++) {
        total += *(arr + i);
    }

    return(total/numElements);
}

int main() {
    int* arr = nullptr;
    int numElements = getArrayElements();
    int key, result = 0;

    arr = makeArray(numElements); // ask user for array element quantity
    allocateArray(arr, numElements); // ask user for array element values
    selectionSort(arr, numElements); // sort array

    getKey(key); // get value to search for
    result = binarySearch(arr, 0,numElements -1, key); // search for key in sorted arr

    if (result != -1) {
        cout << "Your Key: " << key << " was found at index: " << result << endl;
    } else {
        cout << "Your Key: " << key << " was not in the array." << endl;
    }
    cout << "Mean: " << mean(arr, numElements) << endl;


    delete[] arr;
    arr = nullptr;


    return 0;
}