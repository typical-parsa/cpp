#include <iostream>
#include <climits>

using namespace std;

int binarySearch(int arr[], int size, int target);

int binarySearch(int arr[], int size, int target){
    int start = 0;
    int stop = size - 1;
    while (start <= stop){
        int middle = (start + stop) / 2;
        //better way
        //start + (stop - start) / 2
        if (arr[middle] = target){
            return middle;
        }else if (arr[middle] > target){
            stop = middle - 1;
        }else {
            start = middle + 1;
        }
    }
    return INT_MIN;
}