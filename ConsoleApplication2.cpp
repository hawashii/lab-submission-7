#include<iostream>
using namespace std;
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);
    return mid;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = medianOfThree(arr, low, high);
        swap(arr[pivotIndex], arr[high]);
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}