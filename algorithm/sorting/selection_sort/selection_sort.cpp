#include <iostream>

using namespace std;

void show_array(int arr[], int size);
void swap_element(int arr[], int first_index, int second_index);
void selection_sort(int arr[], int size);
int main(){

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
            swap_element(arr, i, min_index);
        }
    }
}

void swap_element(int arr[], int first_index, int second_index){
    int temp_value = arr[first_index];
    arr[first_index] = arr[second_index];
    arr[second_index] = arr[first_index];
}

void show_array(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}