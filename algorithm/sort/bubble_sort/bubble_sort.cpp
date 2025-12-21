#include <iostream>

using namespace std;

void show_array(int arr[], int size);
void swap_element(int arr[], int first_index, int second_index);

int main(){

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