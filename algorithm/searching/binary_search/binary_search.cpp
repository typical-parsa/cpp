#include <iostream>
#include <climits>
using namespace std;

int binary_search(int arr[], int size, int target);

int main(){
}

int binary_search(int arr[], int size, int target){
    int start = 0;
    int stop = size - 1;
    while (start <= stop){
        int mid = (start + stop) / 2;
        if (arr[mid] == target){
            return mid;
        }else if (arr[mid] > target){
            stop = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return INT_MIN;
}