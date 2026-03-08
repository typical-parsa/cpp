#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size);
void swapElement(int arr[], int firstIndex, int secondIndex);
void showArray(int arr[], int size);

int main(){
    int arr[] = {1, 5, 3, 2, 6, 4, 7, 9 ,8};
    int size = sizeof(arr) / sizeof(int);
    cout << "Befor sorting : " << endl;
    showArray(arr, size);
    cout << "After sorting : " << endl;
    bubbleSort(arr, size);
    showArray(arr, size);
}

void bubbleSort(int arr[], int size){
    for (int i = 0 ; i < size - 1 ; i++){
        bool swapped = false;
        for (int j = 0 ; j < size - i - 1 ; j++){
            if (arr[j] > arr[j + 1]){
                swapElement(arr, j, j+1);
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
}

void swapElement(int arr[], int firstIndex, int secondIndex){
    int tempValue = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = tempValue;
}

void showArray(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}