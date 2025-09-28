#include <iostream>

using namespace std;

void bubble_sort(int arr[], int size);
void show_array(int arr[], int size);
void swap_elements(int arr[], int first_index, int second_index);

int main(){
    int arr[] = {9, 3, 1, 4, 2, 7, 6, 8, 5};
    int size = sizeof(arr) / sizeof(int);
    cout << "Before bubble sorting: " << endl;
    show_array(arr, size);
    cout << "After bubble sorting: " << endl;
    bubble_sort(arr, size);
    show_array(arr, size);
}

void bubble_sort(int arr[], int size){
    bool swapped;
    for (int i = size - 1 ; i > 0 ; i--){
        swapped = false;
        for (int j = 0 ; i > j ; j++){
            if (arr[j] > arr[j+1]){
                swap_elements(arr, j, j+1);
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
}

void show_array(int arr[], int size){
    cout << "List items: " << endl;
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void swap_elements(int arr[], int first_index, int second_index){
    int temp_value = arr[first_index];
    arr[first_index] = arr[second_index];
    arr[second_index] = temp_value;
}