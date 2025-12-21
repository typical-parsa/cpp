#include <iostream>
#include <climits>

using namespace std;

int linear_search(int arr[], int size, int target);

int main(){

    int arr[] = {44,66,4,223,234,653};
    int size = sizeof(arr) / sizeof(int);
    cout << "Index of 223 is " << linear_search(arr, size,223) << endl;
    cout << "Index of 444 is " << linear_search(arr, size,444) << endl;
}

int linear_search(int arr[], int size, int target){
    for (int i = 0 ; i < size ; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return INT_MIN;
}