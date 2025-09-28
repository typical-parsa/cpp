#include <iostream>

using namespace std;

int linear_search(int arr[], int size, int target);

int main(){
    int arr[] = {9, 3, 1, 4, 2, 7, 6, 8, 5};
    int size = sizeof(arr) / sizeof(int);
    cout << linear_search(arr, size, 5) << endl; 
}

int linear_search(int arr[], int size, int target){
    for (int i = 0 ; i < size ; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}