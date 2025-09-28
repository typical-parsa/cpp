#include <iostream>

using namespace std;

void selection_sort(int arr[], int size);
void show_array(int arr[], int size);
void swap_elements(int arr[], int first_index, int second_index);

int main(){
    int arr[] = {9, 3, 1, 4, 2, 7, 6, 8, 5};
    int size = sizeof(arr) / sizeof(int);
    cout << "Before selection sorting: " << endl;
    show_array(arr, size);
    cout << "After selection sorting: " << endl;
    selection_sort(arr, size);
    show_array(arr, size);
}

void selection_sort(int arr[], int size){
    for (int i = 0 ; i < size - 1 ; i++){
        int min_index = i;
        for (int j = i + 1 ; j < size ; j++){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        if (min_index != i){
            swap_elements(arr, i, min_index);
        }
    }
}

void show_array(int arr[], int size){
    cout << "List elements: " << endl;
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap_elements(int arr[], int first_index, int second_index){
    int temp_value = arr[first_index];
    arr[first_index] = arr[second_index];
    arr[second_index] = temp_value;
}