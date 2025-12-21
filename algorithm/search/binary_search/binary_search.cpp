#include <iostream>

using namespace std;

int binary_search(int arr[], int size, int target);

int main(){
    int arr[] = {33, 55, 65, 89, 100, 200, 3443, 44422, 55555};
    int size = sizeof(arr) / sizeof(int);
    cout << "Index of 100 " << binary_search(arr, size, 200) << endl;
    cout << "Index of 2" << binary_search(arr, size, 2) << endl; 
}

int binary_search(int arr[], int size, int target){
    int start = 0;
    int stop = size - 1;
    while(start <= stop){
        int middle = (start + stop) / 2;
        //better way
        //start + (stop - start) / 2
        if (arr[middle] == target){
            return middle;
        }else if (arr[middle] > target){
            stop = middle - 1;
        }else {
            start = middle + 1;
        }
    }
    return -1;
}