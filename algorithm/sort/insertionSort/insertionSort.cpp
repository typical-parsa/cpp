#include <iostream>

using namespace std;

void insertionSort(int arr[], int size);
void showArray(int arr[], int size);

int main(){
    int arr[] = {1, 5, 3, 2, 6, 4, 7, 9 ,8};
    int size = sizeof(arr) / sizeof(int);
    cout << "Befor sorting : " << endl;
    showArray(arr, size);
    cout << "After sorting : " << endl;
    insertionSort(arr, size);
    showArray(arr, size);
}

void insertionSort(int arr[], int size){
    for (int i = 1 ; i < size ; i++){
        int key = arr[i];
        int j = i - 1;
        //shift bigger element to the right
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        //insert the key
        arr[j+1] = key;
    }
}

void showArray(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}