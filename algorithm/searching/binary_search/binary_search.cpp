#include <iostream>

using namespace std;

int binary_search(int arr[], int size, int target);

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    cout << binary_search(arr, size, 5) << endl;
}

int binary_search(int arr[], int size, int target){
    int start = 0;
    int stop = size - 1;
    while (start <= stop){
        int mid = (stop - start) / 2;
        if (arr[mid] == target){
            return mid;
        }else if (arr[mid] > target){
            stop = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
}