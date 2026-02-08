#include <iostream>

using namespace std;

void selectionSort(int arr[], int size);
void showArray(int arr[], int size);
void swapElement(int arr[], int firstIndex, int secondIndex);


int main(){

}

void selectionSort(int arr[], int size){
    for (int i = 0 ; i < size - 1 ; i++){
        int minIndex = i;
        for (int j = i + 1 ; j < size ; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if (minIndex != i){
            swap_element(arr, i, minIndex);
        }
    }
}

void swap_element(int arr[], int first_index, int second_index){
    int temp_value = arr[first_index];
    arr[first_index] = arr[second_index];
    arr[second_index] = temp_value;
}

void show_array(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}