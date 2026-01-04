#include <iostream>

using namespace std;

void printArray(int arr[], int size);

int main(){
    int arr[100];
    int size = 0;
    int capacity = 100;

}

void printArray(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}