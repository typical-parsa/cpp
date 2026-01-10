#include <iostream>
#include <climits>

using namespace std;

int linearSearch(int arr[], int size, int target);

int main(){
    
}

int linearSearch(int arr[], int size, int target){
    for (int i = 0 ; i < size ; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return INT_MIN;
}