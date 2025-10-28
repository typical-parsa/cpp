#include <iostream>

using namespace std;

void bubble_sort(int arr[], int size);
void swap_element(int arr[], int first_index, int second_index);
void show_array(int arr[], int size);


int main(){
    int arr[] = {4, 3, 6, 1, 9, 2, 5, 8, 7};
    int size = (sizeof(arr) / sizeof(int));
    cout << "Before bubble sorting: " << endl;
    show_array(arr, size);
    cout << "After bubble sorting: " << endl;
    bubble_sort(arr, size);
    show_array(arr, size);
}

void bubble_sort(int arr[], int size){
    bool swapped;
    for (int i = 0 ; i < size - 1 ; i++){
        swapped = false;
        for (int j = 0 ; j < size - i ; j++){
            if (arr[j] > arr[j + 1]){
                swap_element(arr, j, j+1);
                swapped = true;
            }
        }
        if (!swapped){
            break;
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